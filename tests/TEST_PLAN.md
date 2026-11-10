# Test plan (M3 → M4)

> **Status at M3 (10 Nov 2026): no physical prototype exists yet.**
> This plan defines *how* the product will be verified. Physical tests are run in M4 once the first prototype is printed and assembled.
> What can already be checked before the prototype (analysis, CAD inspection, software) is recorded in
> [`records/M3_pre-prototype_verification.md`](records/M3_pre-prototype_verification.md).

Design basis: `ASSEM_INNER` drawing (17 CAD items) and `BOM 08.11.2026.xlsx` (sheet `BOM 081126`, €20.64).

**Verification methods:** **A** = analysis / calculation · **C** = CAD inspection · **S** = software test on PC · **P** = physical test on prototype

| ID | Test | Method (P = how it will be done on the prototype) | Pass criterion | Pre-prototype check (M3) | Physical test | Owner | Record |
|---|---|---|---|---|---|---|---|
| **T1** | Motor under load — frother (`CAD #2, #6`) | **A** + **P**: 150 ml milk, 30 s at High; measure current (multimeter), speed (tachometer/strobe app), motor temperature | Foam formed in ≤ 30 s, no stall, T_motor < 60 °C | A: load estimate (method only — numbers were made for an earlier motor) | Not yet tested | Tùng | `records/motor_frother_YYYYMMDD.md` |
| **T2** | Motor under load — whisk (`CAD #2, #6, #8`) | **A** + **P**: 2 eggs or 100 ml light cream, 2 min at Low/Medium | No stall, no visible wobble, T_motor < 60 °C | A: same as T1 | Not yet tested | Tùng | `records/motor_whisk_YYYYMMDD.md` |
| **T3** | Coupling retention & tool-free swap (`CAD #5, #7, #8`) | **C** + **P**: 20 attach/detach cycles; pull test; 2 min at full speed | No self-release, swap by hand < 5 s, no visible wear | C: bore / journal / bearing fit in SolidWorks | Not yet tested | Tùng | `records/coupling_YYYYMMDD.md` |
| **T4** | Battery runtime & low-battery cut-off (`CAD #17`) | **A** + **P**: full cell, frother load until firmware cut-off | Runtime ≥ 60 min; motor stops at cut-off voltage | A: energy budget from cell datasheet | Not yet tested | Hùng | `records/runtime_YYYYMMDD.md` |
| **T5** | Splash protection (`CAD #7, #10, #13`) | **C** + **P**: close `RUBBER_COVER`, rinse head 10 s under tap, open housing, check with dry tissue | No water inside electronics/battery zone | C: openings and seal positions in CAD | Not yet tested | Tùng | `records/splash_YYYYMMDD.md` |
| **T6** | Cleanability & food-contact boundary (`CAD #5, #6`) | **C** + **P**: use with milk/egg, wash head, inspect coupling for residue | No visible residue on head / socket | C: only `WHISKER` below liquid line | Not yet tested | Tùng / Nga | `records/cleaning_YYYYMMDD.md` |
| **T7** | Disassembly / reassembly (`CAD #11, #12, #14`) | **C** + **P**: full teardown and rebuild with screwdriver only, 3 repetitions, timed | No broken part, works after rebuild; time recorded | C: all joints screws / snap-fits, no glue | Not yet tested | Hùng | `records/disassembly_YYYYMMDD.md` |
| **T8** | USB-C charging & thermal safety (`CAD #9, #17`) | **P**: 5 V USB-C, charge depleted cell to full | Charges, cuts off at full, no part > 45 °C | — (needs hardware) | Not yet tested | Hùng | `records/charging_YYYYMMDD.md` |
| **T9** | Firmware speed logic & LED (`CAD #10, #15, #16`) | **S**: compile and run `firmware/test/test_speed_logic.cpp` on a PC · **P**: flash ESP32-C3 and check button sequence, LED, auto-off | S: all 19 checks print `ok`, 0 `FAIL` · P: Low → Medium → High → Off works on hardware | S: **PASS — 19/19 checks ok (10 Nov 2026, g++ 16.2.0)** | Not yet tested | Vân Anh / Tùng | `records/firmware_YYYYMMDD.md` |

## Rules for test records
- One file per test run, named `records/<test>_YYYYMMDD.md`, using [`records/_TEMPLATE.md`](records/_TEMPLATE.md).
- Write only values that were actually measured, with the date and the people who did the test. Add a photo of the set-up in `images/`.
- A failed or partial result is still a valid record — write what was learned and which design change it triggered (add it to `CHANGELOG.md`).
