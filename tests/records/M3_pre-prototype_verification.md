# M3 pre-prototype verification

- **Date:** 10 Nov 2026
- **Design version:** v0.3-M3 — `ASSEM_INNER` drawing (17 items), `BOM 08.11.2026.xlsx` (sheet `BOM 081126`)
- **Prototype status:** **No physical prototype yet.** All physical tests in [`../TEST_PLAN.md`](../TEST_PLAN.md) are *not yet tested*.
- **Checked by:** _(fill in names of the team members who review / confirm each item)_

This record lists only what can be checked **without** a prototype: calculations from datasheet values, consistency between drawing and BOM, and items still open. Nothing here is a measurement on real hardware.

## 1. Done — document & calculation checks

| # | Check | Method | Result | Related test |
|---|---|---|---|---|
| 1 | Drawing and BOM list the same parts | Compared `ASSEM_INNER` item table (17 items) with `BOM 081126` rows | Consistent: motor, battery + holder, USB-C, button, ESP32-C3, DRV8833, bearing W 61700, `RUBBER_COVER`, fasteners 2 + 6 + 2 = 10 pcs | all |
| 2 | Bearing size is the same everywhere | Drawing item 8 vs. BOM item 14 vs. SKF catalogue | W 61700 = 10 × 15 × 3 mm in drawing, BOM and catalogue | T2, T3 |
| 3 | Prototype cost within course limit | Sum of `BOM 081126` | €20.64 ≤ €200 (all items priced, no TBD) | — |
| 4 | Battery energy (estimate) | Datasheet: 3.65 V × 2.6 Ah | ≈ 9.5 Wh. With 80 % usable and an **assumed** 1–3 W motor load → ≈ 2.5–7.5 h motor time. The motor load is not measured yet, so this is **not** evidence for T4 | T4 |
| 5 | Controller can run from one 18650 cell | Datasheet ranges | ESP32-C3 SuperMini, DRV8833 (2.7–10.8 V) and 3.7 V motor are compatible with a 3.0–4.2 V cell; the earlier Mini 560 buck module (7–20 V input) was not, so it was replaced | T8, T9 |
| 6 | Firmware speed logic — PC unit test (T9, software part) | Compiled and ran `firmware/test/test_speed_logic.cpp` on 10 Nov 2026 with g++ 16.2.0 (MinGW-w64 / WinLibs), `-std=c++11 -Wall`, no compiler warnings | **19 / 19 checks `ok`, 0 failures, exit code 0** — full output below | T9 |

### Output of check 6 (copied exactly)

```text
g++.exe (MinGW-W64 x86_64-ucrt-posix-seh, built by Brecht Sanders, r3) 16.2.0
ok  : starts OFF
ok  : short press -> SPEED1
ok  : soft start reaches level-1 duty
ok  : short press -> SPEED2
ok  : short press -> SPEED3
ok  : level 3 duty > level 2 duty
ok  : average motor voltage <= MOTOR_MAX_MV
ok  : short press at SPEED3 -> OFF, duty 0 at once
ok  : back to SPEED2
ok  : long press -> OFF
ok  : release after long press does not restart
ok  : contact bounce ignored
ok  : duty compensates for falling cell voltage
ok  : auto-off after AUTO_OFF_MS
ok  : short voltage dip tolerated
ok  : sustained low voltage -> LOW_BATTERY, motor stopped
ok  : locked out until charged
ok  : lock-out released after charging
ok  : refuses to start below START_MIN_MV

ALL TESTS PASSED (0 failure(s))
```

**What this proves:** the button / speed / soft-start / auto-off / low-battery logic in `speed_logic.h` behaves as designed.
**What it does not prove:** the ESP32-C3 pin mapping, PWM output, button LED behaviour (in `OpenWhisk3S_Firmware.ino`), real battery voltage reading, or actual motor speeds. Those need the hardware test (T9 physical part, M4).

## 2. Not done yet — can be done before the prototype

| # | Check | How | Owner | Status |
|---|---|---|---|---|
| 7 | Motor load estimate for the **130 motor** | Repeat the P = Np·ρ·n³·D⁵ estimate in `docs/design-rationale.md` with the 130 motor datasheet (stall torque, no-load current). The existing numbers are for the earlier FF-030PK motor | Tùng | Open — needs 130 motor datasheet |
| 8 | Fit check in CAD | In SolidWorks: ADAPTER bore vs. motor shaft Ø2.0 mm, ADAPTER journal vs. bearing bore Ø10 mm, *Interference Detection* on `ASSEM_INNER` | Tùng | Open |
| 9 | Splash openings in CAD | List every opening in `OUTER_SHELL` / `OUTER_CAP` and the part that seals it (button, `RUBBER_COVER`, `RETAINER`) | Đông | Open |

## 3. Needs the physical prototype (M4)

T1 motor frother · T2 motor whisk · T3 coupling cycles · T4 runtime · T5 splash · T6 cleaning · T7 timed disassembly · T8 charging · T9 on hardware.
Each run gets its own record file using [`_TEMPLATE.md`](_TEMPLATE.md), with real measured values, date, testers and a photo.
