// SPDX-License-Identifier: MIT
// OpenWhisk 3S firmware - configuration (pins + tunable parameters)
// Copyright (c) 2026 GPE 2026/27 Group 1
//
// Change values here only. All values are STARTING POINTS that must be
// confirmed by the bench tests in tests/TEST_PLAN.md (T1, T2, T9).

#ifndef OPENWHISK_CONFIG_H
#define OPENWHISK_CONFIG_H

// ---------------------------------------------------------------------------
// Pin map
// ---------------------------------------------------------------------------
#if defined(__AVR_ATtiny85__)
  // Target hardware: ATtiny85 (DIP-8), ATTinyCore, internal 8 MHz.
  // Arduino pin number = PBn.            Physical pin
  #define PIN_BUTTON   3   // PB3  -> 12 mm push button to GND   (pin 2)
  #define PIN_IN1      4   // PB4  -> DRV8833 AIN1 (PWM, OC1B)   (pin 3)
  #define PIN_IN2      0   // PB0  -> DRV8833 AIN2 (held LOW)    (pin 5)
  #define PIN_NSLEEP   2   // PB2  -> DRV8833 EEP/STBY/nSLEEP    (pin 7)
  #define PIN_LED      1   // PB1  -> optional status LED + 1k   (pin 6)
#else
  // Bench-test option: Arduino Uno / Nano (ATmega328P).
  #define PIN_BUTTON   2
  #define PIN_IN1      9   // analogWrite PWM (~490 Hz)
  #define PIN_IN2      8
  #define PIN_NSLEEP   7
  #define PIN_LED      13
#endif

// 1 = status LED fitted on PIN_LED (blinks on low battery). 0 = not fitted.
// The tracker BOM button is a non-LED type, so default is 0.
#define USE_STATUS_LED        0

// ---------------------------------------------------------------------------
// Speed levels, defined as AVERAGE MOTOR VOLTAGE in millivolts.
// The firmware converts them into a PWM duty using the measured cell voltage,
// so each level stays roughly constant while the cell drains from 4.2 V to 3.2 V.
// Motor: DC brushed 130 series, 3.7 V class (Action tracker, BOM updated #1).
// ---------------------------------------------------------------------------
#define LEVEL1_MV             2000   // gentle  - start of frothing, light mixing
#define LEVEL2_MV             2800   // medium
#define LEVEL3_MV             3600   // high    - frothing / whisking cream
#define MOTOR_MAX_MV          3700   // never exceed the motor's rated voltage

// ---------------------------------------------------------------------------
// Button
// ---------------------------------------------------------------------------
#define DEBOUNCE_MS             30   // contact bounce filter
#define LONG_PRESS_MS          800   // hold this long = switch OFF from any speed

// ---------------------------------------------------------------------------
// Soft start (limits inrush current and splashing at start)
// ---------------------------------------------------------------------------
#define RAMP_STEP_MS             4   // ms between duty increments
#define RAMP_STEP_DUTY           2   // duty increment (0..255) -> ~0.5 s to full

// ---------------------------------------------------------------------------
// Battery protection (Lishen LR1865SK: 4.20 V full, 3.65 V nominal)
// The cell must ALSO have a hardware protection circuit (e.g. DW01 on the
// charger module) - firmware protection is a second layer, not the only one.
// ---------------------------------------------------------------------------
#define LOW_BATT_CUTOFF_MV    3200   // under load: stop motor below this ...
#define LOW_BATT_CONFIRM_MS   2000   // ... if it stays low this long
#define START_MIN_MV          3300   // refuse to start below this (no load)
#define LOW_BATT_RECOVER_MV   3600   // leave low-battery lock-out above this (after charging)

// ---------------------------------------------------------------------------
// Safety / power saving
// ---------------------------------------------------------------------------
#define AUTO_OFF_MS         180000UL // 3 min continuous run -> OFF (frothing needs ~30 s)
#define SLEEP_AFTER_MS        3000UL // idle time before deep sleep (ATtiny85 only)
#define VCC_SAMPLE_MS           20   // supply voltage sampling period

// ---------------------------------------------------------------------------
// Supply-voltage measurement
// ATtiny85 measures its own VCC (= cell voltage) against the internal 1.1 V
// bandgap. The bandgap varies +-10 % between chips: calibrate once by measuring
// the cell with a multimeter and adjusting BANDGAP_MV (see firmware/README.md).
// ---------------------------------------------------------------------------
#define BANDGAP_MV            1100UL
// Bench boards (Uno/Nano) are USB-powered, so VCC is not the cell voltage.
// They use this fixed value instead (set it to the measured cell voltage).
#define BENCH_VBAT_MV         3700

#endif // OPENWHISK_CONFIG_H
