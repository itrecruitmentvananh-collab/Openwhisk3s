// SPDX-License-Identifier: MIT
// OpenWhisk 3S firmware - configuration (pins + tunable parameters)
// Target Controller: ESP32-C3 SuperMini (CAD #15, BOM #11) driving DRV8833 (CAD #16, BOM #10)
// and 12mm Waterproof Illuminated Push Button with LED (CAD #10, BOM #9)
// Copyright (c) 2026 GPE 2026/27 Group 1

#ifndef OPENWHISK_CONFIG_H
#define OPENWHISK_CONFIG_H

// ---------------------------------------------------------------------------
// Pin map — ESP32-C3 SuperMini (default) & ATtiny85 / Arduino Uno fallback
// ---------------------------------------------------------------------------
#if defined(ESP32) || defined(ARDUINO_ARCH_ESP32)
  // Target hardware in BOM 08.11.2026: ESP32-C3 SuperMini (CAD #15)
  #define PIN_BUTTON   3   // GPIO3  -> 12 mm push button contact to GND (INPUT_PULLUP)
  #define PIN_IN1      4   // GPIO4  -> DRV8833 AIN1 (PWM output)
  #define PIN_IN2      5   // GPIO5  -> DRV8833 AIN2 (held LOW)
  #define PIN_NSLEEP   6   // GPIO6  -> DRV8833 EEP / nSLEEP (HIGH when motor active)
  #define PIN_LED      8   // GPIO8  -> 12 mm button LED / onboard status LED
  #define PIN_VBAT_ADC 2   // GPIO2 (ADC1_CH2) -> optional battery voltage divider sense
#elif defined(__AVR_ATtiny85__)
  #define PIN_BUTTON   3
  #define PIN_IN1      4
  #define PIN_IN2      0
  #define PIN_NSLEEP   2
  #define PIN_LED      1
#else
  #define PIN_BUTTON   2
  #define PIN_IN1      9
  #define PIN_IN2      8
  #define PIN_NSLEEP   7
  #define PIN_LED      13
#endif

// 1 = illuminated button LED enabled (BOM 08.11.2026 Item #9: 12mm button with LED)
#define USE_STATUS_LED        1

// ---------------------------------------------------------------------------
// Speed levels (target operating speeds: ~9,000 / 11,000 / 13,000 RPM)
// Defined as AVERAGE MOTOR VOLTAGE in millivolts for the 130-Series 3.7V DC motor
// ---------------------------------------------------------------------------
#define LEVEL1_MV             2500   // Low  (~9,000 RPM target)  - gentle stirring / eggs
#define LEVEL2_MV             3100   // Med  (~11,000 RPM target) - cream / sauces
#define LEVEL3_MV             3650   // High (~13,000 RPM target) - milk foaming
#define MOTOR_MAX_MV          3700   // Never exceed motor's 3.7 V rated voltage

// ---------------------------------------------------------------------------
// Button & Soft-Start timings
// ---------------------------------------------------------------------------
#define DEBOUNCE_MS             30   // contact bounce filter
#define LONG_PRESS_MS          800   // hold >= 0.8 s = immediate OFF from any speed
#define RAMP_STEP_MS             4   // ms between duty increments
#define RAMP_STEP_DUTY           2   // ~0.5 s soft-start ramp to prevent splashing

// ---------------------------------------------------------------------------
// Battery protection (Lishen LR1865SK 18650: 4.20 V full, 3.65 V nominal)
// ---------------------------------------------------------------------------
#define LOW_BATT_CUTOFF_MV    3200   // under load: stop motor below 3.20 V ...
#define LOW_BATT_CONFIRM_MS   2000   // ... if sustained for 2.0 s
#define START_MIN_MV          3300   // refuse to start below 3.30 V
#define LOW_BATT_RECOVER_MV   3600   // clear lock-out after recharging above 3.60 V

// ---------------------------------------------------------------------------
// Safety auto-off
// ---------------------------------------------------------------------------
#define AUTO_OFF_MS         180000UL // 3 min continuous run -> automatic OFF
#define SLEEP_AFTER_MS        3000UL
#define VCC_SAMPLE_MS           20
#define BANDGAP_MV            1100UL
#define BENCH_VBAT_MV         3650   // Nominal 3.65 V Lishen LR1865SK cell

#endif // OPENWHISK_CONFIG_H
