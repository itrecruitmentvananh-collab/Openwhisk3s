// SPDX-License-Identifier: MIT
// OpenWhisk 3S firmware - hardware-independent control logic
// Copyright (c) 2026 GPE 2026/27 Group 1
//
// This file contains NO Arduino or AVR code, so it can be unit-tested on a PC
// (see firmware/test/test_speed_logic.cpp).
//
// Behaviour:
//   short press : OFF -> SPEED1 -> SPEED2 -> SPEED3 -> OFF
//   long press  : any speed -> OFF
//   soft start  : duty ramps up, drops immediately
//   low battery : motor stops, lock-out until the cell is charged
//   auto-off    : after AUTO_OFF_MS of continuous running

#ifndef OPENWHISK_SPEED_LOGIC_H
#define OPENWHISK_SPEED_LOGIC_H

#include <stdint.h>
#include "config.h"

enum MotorState {
  STATE_OFF = 0,
  STATE_SPEED1 = 1,
  STATE_SPEED2 = 2,
  STATE_SPEED3 = 3,
  STATE_LOW_BATTERY = 4
};

class SpeedLogic {
public:
  MotorState state;
  uint8_t dutyNow;          // PWM duty currently applied, 0..255

  void begin(uint32_t now, uint16_t vccMv) {
    state = STATE_OFF;
    dutyNow = 0;
    rawLast = false;
    stable = false;
    rawChangeMs = now;
    pressStartMs = now;
    longHandled = false;
    runStartMs = now;
    lastRampMs = now;
    lowSinceMs = now;
    lowTiming = false;
    lastActivityMs = now;
    vccFilt = vccMv;
  }

  // Call after waking from sleep: time stood still and the filter is stale.
  void resync(uint32_t now, uint16_t vccMv) {
    vccFilt = vccMv;
    rawChangeMs = now;
    lastActivityMs = now;
  }

  bool isRunning() const {
    return state == STATE_SPEED1 || state == STATE_SPEED2 || state == STATE_SPEED3;
  }

  uint16_t filteredVcc() const { return vccFilt; }

  uint32_t idleTime(uint32_t now) const { return now - lastActivityMs; }

  // PWM duty that gives the level's average motor voltage at this cell voltage.
  static uint8_t dutyFor(MotorState s, uint16_t vccMv) {
    uint32_t mv;
    if (s == STATE_SPEED1)      mv = LEVEL1_MV;
    else if (s == STATE_SPEED2) mv = LEVEL2_MV;
    else if (s == STATE_SPEED3) mv = LEVEL3_MV;
    else return 0;
    if (mv > MOTOR_MAX_MV) mv = MOTOR_MAX_MV;
    if (vccMv == 0) return 0;
    uint32_t d = (mv * 255UL) / vccMv;
    if (d > 255UL) d = 255UL;     // cell lower than target: full duty
    return (uint8_t)d;
  }

  // Call often (every loop, at least every few ms).
  void update(uint32_t now, bool rawPressed, uint16_t vccMv) {
    // 1. Supply voltage filter (simple 1/4 low-pass)
    vccFilt = (uint16_t)(((uint32_t)vccFilt * 3UL + vccMv) / 4UL);

    // 2. Button debounce + short/long press detection
    if (rawPressed != rawLast) {
      rawLast = rawPressed;
      rawChangeMs = now;
    }
    if ((now - rawChangeMs) >= DEBOUNCE_MS && stable != rawLast) {
      stable = rawLast;
      lastActivityMs = now;
      if (stable) {
        pressStartMs = now;
        longHandled = false;
      } else if (!longHandled) {
        onShortPress(now);
      }
    }
    if (stable && !longHandled && (now - pressStartMs) >= LONG_PRESS_MS) {
      longHandled = true;
      onLongPress(now);
    }

    // 3. Low-battery lock-out release (after charging)
    if (state == STATE_LOW_BATTERY && vccFilt >= LOW_BATT_RECOVER_MV) {
      setState(STATE_OFF, now);
    }

    // 4. Protection while running
    if (isRunning()) {
      if (vccFilt < LOW_BATT_CUTOFF_MV) {
        if (!lowTiming) {
          lowTiming = true;
          lowSinceMs = now;
        } else if ((now - lowSinceMs) >= LOW_BATT_CONFIRM_MS) {
          setState(STATE_LOW_BATTERY, now);
        }
      } else {
        lowTiming = false;
      }
      if (isRunning() && (now - runStartMs) >= AUTO_OFF_MS) {
        setState(STATE_OFF, now);
      }
    } else {
      lowTiming = false;
    }

    // 5. Duty: ramp up slowly, go down immediately
    uint8_t target = dutyFor(state, vccFilt);
    if (target <= dutyNow) {
      dutyNow = target;
    } else if ((now - lastRampMs) >= RAMP_STEP_MS) {
      lastRampMs = now;
      uint8_t gap = (uint8_t)(target - dutyNow);
      dutyNow = (uint8_t)(dutyNow + (gap < RAMP_STEP_DUTY ? gap : RAMP_STEP_DUTY));
    }
  }

private:
  bool rawLast;
  bool stable;
  uint32_t rawChangeMs;
  uint32_t pressStartMs;
  bool longHandled;
  uint32_t runStartMs;
  uint32_t lastRampMs;
  uint32_t lowSinceMs;
  bool lowTiming;
  uint32_t lastActivityMs;
  uint16_t vccFilt;

  void setState(MotorState s, uint32_t now) {
    if (s != state) {
      state = s;
      lastActivityMs = now;
    }
  }

  void onShortPress(uint32_t now) {
    switch (state) {
      case STATE_OFF:
        if (vccFilt < START_MIN_MV) {
          setState(STATE_LOW_BATTERY, now);
        } else {
          runStartMs = now;
          lowTiming = false;
          setState(STATE_SPEED1, now);
        }
        break;
      case STATE_SPEED1: setState(STATE_SPEED2, now); break;
      case STATE_SPEED2: setState(STATE_SPEED3, now); break;
      case STATE_SPEED3: setState(STATE_OFF, now); break;
      case STATE_LOW_BATTERY: break;   // stay locked until charged
    }
  }

  void onLongPress(uint32_t now) {
    if (isRunning()) setState(STATE_OFF, now);
  }
};

#endif // OPENWHISK_SPEED_LOGIC_H
