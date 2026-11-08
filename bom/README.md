# Bill of materials

**Source of truth:** the team's `Action tracker.xlsx` → sheet **`BOM updated`** (16 items). The tracker's
`BOM Criteria` sheet gives the selection guidelines behind it.
[`BOM.csv`](BOM.csv) (opens in any spreadsheet) and [`BOM.xlsx`](BOM.xlsx) copy those 16 rows with their CAD item numbers
(`ASSEM_INNER` exploded view). They add a classification column for the course rules.

## Cost (Action #3 — owner Nga, status open)

| | EUR |
|---|---|
| Sum of the 12 priced items in `BOM updated` | **13.82** |
| Items without a price yet (TBD) | #8 push button · #10 Mini 560 step-down · #14 seal / USB-C cover · #16 packaging (digital docs = 0.00) |
| Budget limit | 200.00 |

Printing machine time and labour are provided free of charge (tracker remark). Filament is costed at €6.43/kg
(Creality Soleyin Basic PETG, EuroSupplies) plus about 10 % allowance. Prices are online listings (Shopee, Desertcart, local
electronics shops), Oct–Nov 2026. They will be replaced by receipts after purchase.

## Classification (Action #1 and #2 — owner Tùng, status **Y**)

| Class | Items (BOM No.) | Counts toward "≤ 2 purchased parts"? |
|---|---|---|
| Purchased functional part | #1 motor 130 series 3.7 V · #2 Lishen LR1865SK 18650 | **Yes → 2** |
| Custom (FabLab 3D print, PETG) | #4 OUTER_SHELL + OUTER_CAP · #6 ADAPTER_ASSEM + RETAINER · #12 INNER_MOUNT | No |
| Bought attachment | #5 WHISKER (replacement stainless rods MHMF03/07) | **Open:** tracker J6 asks "purchased or custom-made?" To confirm with the lecturers |
| Standard component | #3 USB-C · #8 button · #9 DRV8833 · #10 step-down · #13 bearing · #14 seal | To confirm with the lecturers (same rule as the module question) |
| Standard consumable / fixture | #7 screws · #11 wire + JST | No |

**Part count with the CAD item list (3–8 rule):** counted parts = INNER_MOUNT (1), motor (2), battery (3), OUTER_SHELL (4),
OUTER_CAP (5), ADAPTER_ASSEM (6), WHISKER (7), RETAINER (8) → **8 parts**. Standard components (9 bearing, 10 driver, 11
step-down, 12 USB-C, 13 button) and fasteners/wires count as standard components/fixtures. *(Tùng's result for Action #1 is the official count. Update this line if it differs.)*

## Open points carried from the tracker (column J)

| BOM # | Open point | Owner |
|---|---|---|
| 1 | Shaft diameter/length, no-load/loaded current, torque. The supplier picture shows a **Ø2 mm × 7.5 mm shaft, 25 × 20 × 15 mm body**. The current CAD ADAPTER has a Ø1.5 mm bore (from the 030 motor) and must be updated | Tùng |
| 2 | Bare or protected cell? Holder dimensions? Separate BMS? | Hùng |
| 3 | Is "TYPE_C" only the connector or part of a charging circuit? **A Li-ion charger is required.** See below | Tùng / Hùng |
| 5 | Whisk diameter, length, shaft diameter, steel grade. Purchased or custom? | Hùng (quotation) |
| 9 | Motor stall current vs DRV8833 rating (~1.5 A) | Tùng (T1/T2) |
| 10 | **Mini 560 (5 V) needs ~7–20 V input. It can't run from one 3.65 V cell** → architecture rechecked in [`electronics/wiring.md`](../electronics/wiring.md) | Tùng |
| 13 | Price picked for **625Z (5 mm bore)**, but CAD uses **W 61700 (10 mm bore)**. Tech team to choose and align CAD/BOM | Tùng |
| 14 | Seal location/geometry/material. Rubber plug for the USB-C port | Tùng |

## Proposed additions (not yet in the tracker, no price) — for team decision

These follow from the open points above. They are **not** included in the €13.82.

| Item | Why it's needed | Decide / quote |
|---|---|---|
| Microcontroller ATtiny85 (DIP-8) + IC socket + 100 nF capacitor | The DRV8833 needs a PWM signal, and the momentary button can't make 3 speeds by itself. See [`firmware/README.md`](../firmware/README.md) | Nga (price), Tùng (part count) |
| Protected USB-C Li-ion charger module (4.2 V CC/CV, DW01-type protection) | Safe charging + over-discharge/short protection. Answers tracker J3/J4. Could replace #10 Mini 560 | Hùng / Nga |
| 18650 holder with spring contacts | Replaceable cell without soldering (tracker J3, docs) | Tùng |
