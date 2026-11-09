# Manufacturing (FabLab FDM 3D Printing — `BOM 08.11.2026.xlsx`)

All custom structural parts are manufactured in the FabLab using **FDM 3D printing** in **Creality Soleyin Basic PETG** (`1.75 mm`, **€6.43/kg** in `BOM 081126`; total filament cost across all printed parts = **€1.92**; machine time & printing labor = **€0.00**).

| Part (`ASSEM_INNER 1046` CAD #) | BOM # | Material | Layer Height | Walls | Infill | Supports | Orientation & Fit Notes |
| :---- | :-: | :---- | :---- | :---- | :---- | :---- | :---- |
| **`OUTER_SHELL` (`CAD #3`)** | **5** | PETG | 0.20 mm | 4 ($\ge 1.6\text{ mm}$) | 20 % gyroid | As needed | Print upright; align Z-seam on back side (`OUTER_SHELL` + `OUTER_CAP` = ~200 g + 10% allowance = **€1.42**) |
| **`OUTER_CAP` (`CAD #4`)** | **5** | PETG | 0.15 mm | 4 | 30 % | No | Print with threads facing up |
| **`INNER_MOUNT` (`CAD #1`)** | **13** | PETG | 0.20 mm | 3 | 30 % | Yes | Bearing seat facing up for concentricity with `SKF W 61700` (`10 × 15 × 3 mm`, `CAD #8`) (~25–30 g + 10% = **€0.20**) |
| **`RETAINER` (`CAD #7`), `ADAPTER_CAP`** | **7** | PETG | 0.12 mm | 3 | 100 % | No | Small precision parts — print 2 spares (`ADAPTER_ASSEM` + `RETAINER` = ~15–20 g + 10% = **€0.30**) |
| **`ADAPTER` (`CAD #5` `ADAPTER_ASSEM`)** | **7** | PETG | 0.12 mm | 3 | 100 % | No | Print axis vertical so the **Ø2.0 mm motor shaft bore** (`130 Series Motor`, `CAD #2`), **Ø10.0 mm bearing journal** (`SKF W 61700`, `CAD #8`), and hex socket are concentric |
| **`CLAMP`, `PUSH` (in `CAD #5`)** | **7** | PETG | 0.12 mm | 3 | 100 % | No | Quick-release wear parts — print 2 spares |
| **`BOARD` (internal carrier)** | **13** | PETG | 0.20 mm | 3 | 30 % | No | Print flat on build plate; holds `ESP32-C3 SuperMini` (`CAD #15`) & `DRV8833` (`CAD #16`) |

* **Printer settings:** Any FabLab FDM printer with a `0.4 mm` nozzle, nozzle temperature `230–245 °C`, heated bed `75–85 °C`.
* **Fasteners & Assembly Tools:** 10× `M2 × 0.4 × 3 mm` stainless-steel screws (`CAD #11, #12, #14`, `BOM #8`, **€0.15**), M2 hex / PH1 screwdriver, flush cutter, soldering iron, multimeter.
* **Why PETG:** Printable in any FabLab, tougher and more heat/moisture-resistant than PLA, and single-polymer recyclable (`>PETG<`). All 3D-printed PETG parts stay **outside the direct food-contact zone** (only the stainless-steel `WHISKER` `CAD #6` touches food).