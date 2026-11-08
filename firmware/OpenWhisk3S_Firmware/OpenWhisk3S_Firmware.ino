// SPDX-License-Identifier: MIT
// OpenWhisk 3S firmware v0.1 - 3-speed button control for a DRV8833 motor driver
// Copyright (c) 2026 GPE 2026/27 Group 1
//
// Target : ATtiny85 @ 8 MHz internal (ATTinyCore, "Arduino as ISP" or USBasp)
// Bench  : Arduino Uno / Nano also compile (no sleep, fixed battery voltage)
//
// Hardware chain (see electronics/wiring.md):
//   18650 cell -> charger/protection -> ATtiny85 VCC and DRV8833 VM
//   ATtiny85 PB4 (PWM) -> DRV8833 AIN1, PB0 -> AIN2 (LOW), PB2 -> EEP/nSLEEP
//   DRV8833 AOUT1/AOUT2 -> 130-series DC motor
//   12 mm momentary push button between PB3 and GND (internal pull-up)

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include "config.h"
#include "speed_logic.h"

SpeedLogic logic;
static uint16_t vccMv = 0;
static uint32_t lastVccSampleMs = 0;

// ---------------------------------------------------------------------------
// PWM output
// ---------------------------------------------------------------------------
static void pwmInit() {
  pinMode(PIN_IN1, OUTPUT);
  digitalWrite(PIN_IN1, LOW);
#if defined(__AVR_ATtiny85__)
  // Timer1, PWM mode B on OC1B (PB4). Clock = CK/1 = 8 MHz, TOP = OCR1C = 255
  // -> 31.25 kHz: above hearing range, so no motor whine. Timer0 stays free
  // for millis().
  TCCR1 = _BV(CS10);
  OCR1C = 255;
  OCR1B = 0;
  GTCCR = _BV(PWM1B);            // PWM enabled, output not yet connected
#endif
}

static void pwmWrite(uint8_t duty) {
#if defined(__AVR_ATtiny85__)
  if (duty == 0) {
    GTCCR &= ~_BV(COM1B1);       // disconnect timer, pin = plain LOW
    digitalWrite(PIN_IN1, LOW);
  } else {
    OCR1B = duty;
    GTCCR |= _BV(COM1B1);        // clear on compare match, set at BOTTOM
  }
#else
  analogWrite(PIN_IN1, duty);
#endif
}

// ---------------------------------------------------------------------------
// Supply (= cell) voltage
// ---------------------------------------------------------------------------
static void adcInit() {
#if defined(__AVR_ATtiny85__)
  ADMUX = _BV(MUX3) | _BV(MUX2);               // ref = VCC, input = 1.1 V bandgap
  ADCSRA = _BV(ADEN) | _BV(ADPS2) | _BV(ADPS1); // enable, 8 MHz / 64 = 125 kHz
  delay(2);                                     // let the bandgap settle
#endif
}

static uint16_t readVccMv() {
#if defined(__AVR_ATtiny85__)
  ADCSRA |= _BV(ADSC);
  while (ADCSRA & _BV(ADSC)) { }
  uint16_t adc = ADC;
  if (adc == 0) return 0;
  return (uint16_t)((BANDGAP_MV * 1024UL) / adc);
#else
  return BENCH_VBAT_MV;
#endif
}

// ---------------------------------------------------------------------------
// Deep sleep (ATtiny85 only): ~1 uA, wakes on button press
// ---------------------------------------------------------------------------
#if defined(__AVR_ATtiny85__)
ISR(PCINT0_vect) { }               // only used to wake up

static void deepSleep() {
  pwmWrite(0);
  digitalWrite(PIN_NSLEEP, LOW);   // DRV8833 into sleep mode
#if USE_STATUS_LED
  digitalWrite(PIN_LED, LOW);
#endif
  ADCSRA &= ~_BV(ADEN);            // ADC off saves ~300 uA
  GIMSK |= _BV(PCIE);
  PCMSK |= _BV(PCINT3);            // wake on PB3 (button) change
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sei();
  sleep_cpu();
  // ... button pressed: execution continues here
  sleep_disable();
  PCMSK &= ~_BV(PCINT3);
  adcInit();
}
#endif

// ---------------------------------------------------------------------------
void setup() {
  pinMode(PIN_BUTTON, INPUT_PULLUP);
  pinMode(PIN_IN2, OUTPUT);
  digitalWrite(PIN_IN2, LOW);      // one direction only; IN2 LOW = coast decay
  pinMode(PIN_NSLEEP, OUTPUT);
  digitalWrite(PIN_NSLEEP, LOW);
#if USE_STATUS_LED
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);
#endif
  pwmInit();
  adcInit();
  vccMv = readVccMv();
  logic.begin(millis(), vccMv);
}

void loop() {
  uint32_t now = millis();

  if ((uint32_t)(now - lastVccSampleMs) >= VCC_SAMPLE_MS) {
    lastVccSampleMs = now;
    vccMv = readVccMv();
  }

  bool pressed = (digitalRead(PIN_BUTTON) == LOW);
  logic.update(now, pressed, vccMv);

  bool active = logic.isRunning() || logic.dutyNow > 0;
  digitalWrite(PIN_NSLEEP, active ? HIGH : LOW);
  pwmWrite(logic.dutyNow);

#if USE_STATUS_LED
  // Blink 4 Hz while locked out for low battery, otherwise off
  bool led = (logic.state == STATE_LOW_BATTERY) && ((now / 125UL) & 1UL);
  digitalWrite(PIN_LED, led ? HIGH : LOW);
#endif

#if defined(__AVR_ATtiny85__)
  if (!active && !pressed && logic.idleTime(now) >= SLEEP_AFTER_MS) {
    deepSleep();
    vccMv = readVccMv();
    logic.resync(millis(), vccMv);
  }
#endif
}
