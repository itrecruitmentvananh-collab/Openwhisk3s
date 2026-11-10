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

## 2. Not done yet — can be done before the prototype

| # | Check | How | Owner | Status |
|---|---|---|---|---|
| 6 | Motor load estimate for the **130 motor** | Repeat the P = Np·ρ·n³·D⁵ estimate in `docs/design-rationale.md` with the 130 motor datasheet (stall torque, no-load current). The existing numbers are for the earlier FF-030PK motor | Tùng | Open — needs 130 motor datasheet |
| 7 | Fit check in CAD | In SolidWorks: ADAPTER bore vs. motor shaft Ø2.0 mm, ADAPTER journal vs. bearing bore Ø10 mm, *Interference Detection* on `ASSEM_INNER` | Tùng | Open |
| 8 | Firmware logic test on a PC | Install a C++ compiler (e.g. MSYS2 / MinGW `g++`), then in `firmware/test/` run `g++ -std=c++11 -I../OpenWhisk3S_Firmware test_speed_logic.cpp -o test` and `./test`. Paste the full output here | Vân Anh | **Not run yet** (no compiler on the team laptop, 10 Nov 2026) |
| 9 | Splash openings in CAD | List every opening in `OUTER_SHELL` / `OUTER_CAP` and the part that seals it (button, `RUBBER_COVER`, `RETAINER`) | Đông | Open |

## 3. Needs the physical prototype (M4)

T1 motor frother · T2 motor whisk · T3 coupling cycles · T4 runtime · T5 splash · T6 cleaning · T7 timed disassembly · T8 charging · T9 on hardware.
Each run gets its own record file using [`_TEMPLATE.md`](_TEMPLATE.md), with real measured values, date, testers and a photo.
