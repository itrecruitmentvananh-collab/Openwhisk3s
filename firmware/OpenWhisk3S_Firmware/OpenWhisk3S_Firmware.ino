// SPDX-License-Identifier: MIT
// OpenWhisk 3S firmware v0.3 - 3-speed button & LED control for ESP32-C3 SuperMini + DRV8833
// Copyright (c) 2026 GPE 2026/27 Group 1 — Trần Thiên Nga, Lê Thị Vân Anh, Phạm Hoài Thương,
// Lê Văn Đông, Võ Sỹ Hùng, Ngô Hoàng Quân, Trần Việt Tùng.
//
// Primary Target (BOM 08.11.2026 Item #11 / CAD #15):
//   ESP32-C3 SuperMini (flashed directly over built-in USB-C using Arduino IDE "ESP32C3 Dev Module")
// Fallback Targets:
//   ATtiny85 @ 8 MHz internal, or Arduino Uno / Nano for bench testing
//
// Hardware chain (see electronics/wiring.md & ASSEM_INNER 1046.pdf):
//   18650 cell (CAD #17) -> USB-C charger/protection (CAD #9) -> ESP32-C3 SuperMini (CAD #15) & DRV8833 VM (CAD #16)
//   ESP32-C3 GPIO4 (PWM) -> DRV8833 AIN1, GPIO5 -> AIN2 (LOW), GPIO6 -> EEP/nSLEEP (HIGH when active)
//   DRV8833 AOUT1/AOUT2 -> 130-Series 3.7V DC Motor (CAD #2)
//   12 mm Waterproof Illuminated Push Button (CAD #10):
//     - Switch contact between GPIO3 and GND (INPUT_PULLUP)
//     - Button LED+ driven by GPIO8 (Steady ON when running, 4 Hz blink on low battery, OFF when stopped)

#if defined(__AVR__)
  #include <avr/io.h>
  #include <avr/interrupt.h>
  #include <avr/sleep.h>
#endif
#include "config.h"
#include "speed_logic.h"

SpeedLogic logic;
static uint16_t vccMv = 0;
static uint32_t lastVccSampleMs = 0;

// ---------------------------------------------------------------------------
// PWM output (ESP32-C3 SuperMini, ATtiny85, or Arduino Uno/Nano)
// ---------------------------------------------------------------------------
static void pwmInit() {
  pinMode(PIN_IN1, OUTPUT);
  digitalWrite(PIN_IN1, LOW);
#if defined(ESP32) || defined(ARDUINO_ARCH_ESP32)
  // ESP32-C3 hardware PWM via analogWrite (8-bit resolution: 0..255, 20 kHz ultrasonic)
  analogWriteResolution(PIN_IN1, 8);
  analogWriteFrequency(PIN_IN1, 20000);
  analogWrite(PIN_IN1, 0);
#elif defined(__AVR_ATtiny85__)
  // Timer1, PWM mode B on OC1B (PB4). Clock = CK/1 = 8 MHz, TOP = OCR1C = 255 -> 31.25 kHz
  TCCR1 = _BV(CS10);
  OCR1C = 255;
  OCR1B = 0;
  GTCCR = _BV(PWM1B);
#endif
}

static void pwmWrite(uint8_t duty) {
#if defined(__AVR_ATtiny85__)
  if (duty == 0) {
    GTCCR &= ~_BV(COM1B1);
    digitalWrite(PIN_IN1, LOW);
  } else {
    OCR1B = duty;
    GTCCR |= _BV(COM1B1);
  }
#else
  analogWrite(PIN_IN1, duty);
#endif
}

// ---------------------------------------------------------------------------
// Supply (= cell) voltage monitoring
// ---------------------------------------------------------------------------
static void adcInit() {
#if defined(ESP32) || defined(ARDUINO_ARCH_ESP32)
  pinMode(PIN_VBAT_ADC, INPUT);
#elif defined(__AVR_ATtiny85__)
  ADMUX = _BV(MUX3) | _BV(MUX2);               // ref = VCC, input = 1.1 V bandgap
  ADCSRA = _BV(ADEN) | _BV(ADPS2) | _BV(ADPS1); // enable, 8 MHz / 64 = 125 kHz
  delay(2);
#endif
}

static uint16_t readVccMv() {
#if defined(__AVR_ATtiny85__)
  ADCSRA |= _BV(ADSC);
  while (ADCSRA & _BV(ADSC)) { }
  uint16_t adc = ADC;
  if (adc == 0) return 0;
  return (uint16_t)((BANDGAP_MV * 1024UL) / adc);
#elif defined(ESP32) || defined(ARDUINO_ARCH_ESP32)
  // If optional 1:2 voltage divider is wired to GPIO2 (PIN_VBAT_ADC), read millivolts;
  // otherwise return nominal 3.65 V (3650 mV) so 3-speed PWM runs out-of-the-box.
  uint32_t mvPin = analogReadMilliVolts(PIN_VBAT_ADC);
  if (mvPin >= 1400 && mvPin <= 2200) {
    return (uint16_t)(mvPin * 2UL);
  }
  return BENCH_VBAT_MV;
#else
  return BENCH_VBAT_MV;
#endif
}

// ---------------------------------------------------------------------------
// Deep sleep (ATtiny85 fallback)
// ---------------------------------------------------------------------------
#if defined(__AVR_ATtiny85__)
ISR(PCINT0_vect) { }

static void deepSleep() {
  pwmWrite(0);
  digitalWrite(PIN_NSLEEP, LOW);
#if USE_STATUS_LED
  digitalWrite(PIN_LED, LOW);
#endif
  ADCSRA &= ~_BV(ADEN);
  GIMSK |= _BV(PCIE);
  PCMSK |= _BV(PCINT3);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sei();
  sleep_cpu();
  sleep_disable();
  PCMSK &= ~_BV(PCINT3);
  adcInit();
}
#endif

// ---------------------------------------------------------------------------
// Arduino Setup & Main Control Loop
// ---------------------------------------------------------------------------
void setup() {
  pinMode(PIN_BUTTON, INPUT_PULLUP);
  pinMode(PIN_IN2, OUTPUT);
  digitalWrite(PIN_IN2, LOW);      // One direction only; IN2 LOW = coast decay
  pinMode(PIN_NSLEEP, OUTPUT);
  digitalWrite(PIN_NSLEEP, LOW);   // DRV8833 in low-power sleep when idle
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
  // BOM 08.11.2026 Item #9 (CAD #10): 12 mm waterproof push button with LED
  // - Steady ON while motor is running (Low / Medium / High)
  // - Fast 4 Hz blink when locked out for low battery
  // - OFF when motor is stopped
  bool ledOn = false;
  if (logic.state == STATE_LOW_BATTERY) {
    ledOn = ((now / 125UL) & 1UL) != 0;
  } else if (active) {
    ledOn = true;
  }
  digitalWrite(PIN_LED, ledOn ? HIGH : LOW);
#endif

#if defined(__AVR_ATtiny85__)
  if (!active && !pressed && logic.idleTime(now) >= SLEEP_AFTER_MS) {
    deepSleep();
    vccMv = readVccMv();
    logic.resync(millis(), vccMv);
  }
#endif
}
