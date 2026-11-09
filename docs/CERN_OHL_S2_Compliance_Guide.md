<!--
SPDX-FileCopyrightText: 2026 OpenWhisk 3S Team - Group 1 (VGU & TU Berlin GPE 2026/27)
SPDX-License-Identifier: CC-BY-SA-4.0
-->

# How OpenWhisk 3S Complies with `CERN-OHL-S-2.0` (`ASSEM_INNER 1046` & `BOM 081126`)

## 1. Important Clarification: Do You Need to "Apply" to CERN?
**NO!** You do **not** submit an application form to CERN or pay any fee to use `CERN-OHL-S-2.0`.  
Just like the `MIT` or `GPL` license for software, **`CERN-OHL-S-2.0` is a self-applied open-source hardware license**:
- You legally apply it yourself simply by placing the official `CERN-OHL-S-2.0` license files ([`LICENSE`](../LICENSE) and [`LICENSE.txt`](../LICENSE.txt)) and attribution notice ([`NOTICE.md`](../NOTICE.md)) inside your public GitHub repository (`https://github.com/itrecruitmentvananh-collab/Openwhisk3s`) and complying with its 4 rules below.

---

## 2. How OpenWhisk 3S Satisfies All 4 Rules of `CERN-OHL-S-2.0`

### Rule 1: Official License Files & Attribution Notice in Repository Root
1. [`LICENSE`](../LICENSE) and [`LICENSE.txt`](../LICENSE.txt) — Full, unmodified official text of `CERN-OHL-S-2.0` in the repository root.
2. [`firmware/LICENSE`](../firmware/LICENSE) and [`firmware/LICENSE.txt`](../firmware/LICENSE.txt) — `MIT` License covering the `ESP32-C3 SuperMini` firmware.
3. [`NOTICE.md`](../NOTICE.md) — Credits all 7 members of GPE 2026/27 Group 1, states the 3-layer licensing (`CERN-OHL-S-2.0` for hardware, `CC-BY-SA-4.0` for documentation, `MIT` for firmware), and records the official Product Source URL (`https://github.com/itrecruitmentvananh-collab/Openwhisk3s`) required by `CERN-OHL-S-2.0` §4.3.

### Rule 2: "Complete Source" in Preferred Editable Formats + Neutral Exports (Clause 1.8)
Under `CERN-OHL-S-2.0` Clause 1.8, exporting only `.STL` or `.PDF` is insufficient. Our repository provides both native editable files and neutral fabrication files:
* **Mechanical CAD ([`cad/`](../cad)):**
  * **Editable Native Source:** 11 SolidWorks parts (`.SLDPRT`), 3 assemblies (`.SLDASM`), and 7 drawings (`.SLDDRW`) in [`cad/solidworks/`](../cad/solidworks).
  * **Neutral & Fabrication Exports:** Neutral `.STEP` assemblies in [`cad/step/`](../cad/step), 2D `.PDF` engineering drawings (including the 17-item exploded assembly [`drawings/pdf/ASSEM_INNER.pdf`](../drawings/pdf/ASSEM_INNER.pdf)), and FDM print parameters in [`docs/manufacturing.md`](manufacturing.md).
* **Electronics ([`electronics/wiring.md`](../electronics/wiring.md)):**
  * Complete block diagram, pin-to-pin wiring table, and component mapping for the `ESP32-C3 SuperMini` (`CAD #15`), `DRV8833` (`CAD #16`), `12 mm Waterproof LED Button` (`CAD #10`), `USB-C` (`CAD #9`), `Lishen 18650` cell (`CAD #17`), and `130 Series 3.7 V Motor` (`CAD #2`).
* **Embedded Firmware ([`firmware/`](../firmware)):**
  * Commented Arduino C++ source code ([`OpenWhisk3S_Firmware.ino`](../firmware/OpenWhisk3S_Firmware/OpenWhisk3S_Firmware.ino), [`config.h`](../firmware/OpenWhisk3S_Firmware/config.h), [`speed_logic.h`](../firmware/OpenWhisk3S_Firmware/speed_logic.h)) and 19 automated PC unit tests ([`test_speed_logic.cpp`](../firmware/test/test_speed_logic.cpp)) for the `ESP32-C3 SuperMini`.

### Rule 3: Declare "Available Components" & Their Interfaces (Clause 1.7)
Under `CERN-OHL-S-2.0` Clause 1.7, standard off-the-shelf parts qualify as **Available Components** and do not require custom manufacturing blueprints—only clear specifications, CAD item mapping, and supplier links:
* All purchased/standard items in the 17-item assembly (`130 Series 3.7 V Motor` `CAD #2`, `SKF W 61700` bearing `CAD #8`, `USB Type-C` `CAD #9`, `12 mm Waterproof LED Button` `CAD #10`, `10× M2×3 Screws` `CAD #11, #12, #14`, `USB-C Silicone Cover` `CAD #13`, `ESP32-C3 SuperMini` `CAD #15`, `DRV8833` `CAD #16`, and `Lishen LR1865SK 18650` `CAD #17`) are fully specified and priced (**€20.64 total**, 0 `TBD`) in [`bom/BOM.csv`](../bom/BOM.csv), [`bom/BOM.xlsx`](../bom/BOM.xlsx), and [`cad/third_party/README.md`](../cad/third_party/README.md).

### Rule 4: Complete Build, Repair, and Verification Instructions
* **Manufacture & Assembly:** [`docs/manufacturing.md`](manufacturing.md) & [`docs/assembly.md`](assembly.md)
* **Non-Destructive Disassembly & Circularity:** [`docs/disassembly-repair.md`](disassembly-repair.md) & [`docs/circularity.md`](circularity.md)
* **Verification Test Plan:** [`tests/TEST_PLAN.md`](../tests/TEST_PLAN.md)
