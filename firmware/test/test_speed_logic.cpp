// SPDX-License-Identifier: MIT
// PC unit test for the OpenWhisk 3S control logic (no hardware needed).
// Build & run (any C++ compiler):
//   g++ -std=c++11 -I../OpenWhisk3S_Firmware test_speed_logic.cpp -o test && ./test
// Windows (MSVC "Developer Command Prompt"):
//   cl /EHsc /I..\OpenWhisk3S_Firmware test_speed_logic.cpp && test_speed_logic.exe

#include <stdio.h>
#include "speed_logic.h"

static int failures = 0;
#define CHECK(cond, msg) do { if (!(cond)) { printf("FAIL: %s\n", msg); failures++; } \
                              else { printf("ok  : %s\n", msg); } } while (0)

static uint32_t t = 0;
static SpeedLogic L;

static void run(uint32_t ms, bool pressed, uint16_t vcc) {
  for (uint32_t i = 0; i < ms; i++) { t++; L.update(t, pressed, vcc); }
}
static void shortPress(uint16_t vcc) { run(100, true, vcc); run(100, false, vcc); }

int main() {
  const uint16_t FULL = 4100;

  L.begin(t, FULL);
  run(50, false, FULL);
  CHECK(L.state == STATE_OFF && L.dutyNow == 0, "starts OFF");

  shortPress(FULL);
  CHECK(L.state == STATE_SPEED1, "short press -> SPEED1");
  run(1000, false, FULL);
  CHECK(L.dutyNow == SpeedLogic::dutyFor(STATE_SPEED1, FULL), "soft start reaches level-1 duty");

  shortPress(FULL);
  CHECK(L.state == STATE_SPEED2, "short press -> SPEED2");
  shortPress(FULL);
  CHECK(L.state == STATE_SPEED3, "short press -> SPEED3");
  run(1000, false, FULL);
  uint8_t d3 = L.dutyNow;
  CHECK(d3 > SpeedLogic::dutyFor(STATE_SPEED2, FULL), "level 3 duty > level 2 duty");
  CHECK((uint32_t)d3 * FULL / 255 <= MOTOR_MAX_MV, "average motor voltage <= MOTOR_MAX_MV");

  shortPress(FULL);
  CHECK(L.state == STATE_OFF && L.dutyNow == 0, "short press at SPEED3 -> OFF, duty 0 at once");

  shortPress(FULL); shortPress(FULL);
  CHECK(L.state == STATE_SPEED2, "back to SPEED2");
  run(LONG_PRESS_MS + 100, true, FULL);
  CHECK(L.state == STATE_OFF, "long press -> OFF");
  run(100, false, FULL);
  CHECK(L.state == STATE_OFF, "release after long press does not restart");

  // Bounce: 5 ms pulses must be ignored
  for (int i = 0; i < 10; i++) { run(5, true, FULL); run(5, false, FULL); }
  run(100, false, FULL);
  CHECK(L.state == STATE_OFF, "contact bounce ignored");

  // Voltage compensation: lower cell -> higher duty for the same level
  CHECK(SpeedLogic::dutyFor(STATE_SPEED2, 3400) > SpeedLogic::dutyFor(STATE_SPEED2, 4200),
        "duty compensates for falling cell voltage");

  // Auto-off
  shortPress(FULL);
  run(AUTO_OFF_MS + 10, false, FULL);
  CHECK(L.state == STATE_OFF, "auto-off after AUTO_OFF_MS");

  // Low battery under load
  shortPress(FULL);
  run(200, false, 3100);                       // short dip: still running
  CHECK(L.isRunning(), "short voltage dip tolerated");
  run(LOW_BATT_CONFIRM_MS + 200, false, 3100);
  CHECK(L.state == STATE_LOW_BATTERY && L.dutyNow == 0, "sustained low voltage -> LOW_BATTERY, motor stopped");
  shortPress(3400);
  CHECK(L.state == STATE_LOW_BATTERY, "locked out until charged");
  run(200, false, 3900);
  CHECK(L.state == STATE_OFF, "lock-out released after charging");

  // Refuse to start on an empty cell
  L.begin(t, 3250);
  shortPress(3250);
  CHECK(L.state == STATE_LOW_BATTERY, "refuses to start below START_MIN_MV");

  printf("\n%s (%d failure(s))\n", failures ? "TESTS FAILED" : "ALL TESTS PASSED", failures);
  return failures ? 1 : 0;
}
