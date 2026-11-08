<!--
SPDX-FileCopyrightText: 2026 OpenWhisk 3S Team - Group 1 (VGU & TU Berlin GPE 2026/27)
SPDX-License-Identifier: CC-BY-SA-4.0
-->

# How to Align & License OpenWhisk 3S Under `CERN-OHL-S-2.0`

## 1. Important Clarification: Do You Need to "Apply" to CERN?
**NO!** You do **not** submit an application form to CERN or pay any fee to use `CERN-OHL-S-2.0`.  
Just like the `MIT` or `GPL` license for software, **`CERN-OHL-S-2.0` is a self-applied open-source hardware license**:
- You legally apply it yourself simply by placing the official `CERN-OHL-S-2.0` license files and notices inside your GitHub repository and complying with its 4 conditions.
- *(Note: Why wasn't `CERN-OHL-S-2.0` in GitHub's dropdown menu when you created your repo? Because GitHub's dropdown only lists ~15 software licenses like MIT/Apache. For Open Source Hardware, you leave the GitHub dropdown as **"None"** when creating the repo, and upload the files in this folder!)*

---

## 2. The 4 Requirements to Make OpenWhisk 3S 100% Compliant with `CERN-OHL-S-2.0`

To satisfy **CERN-OHL-S v2** and the **TU Berlin GPE Module evaluation (Kick-off Slides 39, 41, 49, 51)**, your product and GitHub repository must fulfill these 4 rules:

### Rule 1: Upload the License Files & `REUSE.toml` to Your GitHub Root
Copy the files from this pack directly into the root of your GitHub repository:
1. `LICENSE` (goes in the main root folder `/` — GitHub will automatically detect it and show a license tab!).
2. `LICENSES/CERN-OHL-S-2.0.txt`, `LICENSES/MIT.txt`, `LICENSES/CC-BY-SA-4.0.txt` (goes in `/LICENSES/`).
3. `REUSE.toml` (goes in the main root folder `/` — this automatically tells the `reuse lint` tool and the TU Berlin lecturers that all your `.SLDPRT`, `.STEP`, `.STL`, and `.kicad_pcb` files are licensed under `CERN-OHL-S-2.0`!).

### Rule 2: Provide "Complete Source" in Preferred Editable Formats (Clause 1.8)
Under `CERN-OHL-S-2.0` Clause 1.8 (and Kick-off Slide 39), exporting **only** `.STL` or `.PDF` files is **not allowed** because others cannot easily modify an STL mesh. For every subsystem, you must push **2 layers of files**:
* **Mechanical CAD (`/cad`):**
  * **Editable Source:** Your native SolidWorks (`.SLDPRT`, `.SLDASM`) or FreeCAD (`.FCStd`) files.
  * **Neutral / Fabrication Export:** `.STEP` (`AP203`/`AP214`) for CAD exchange + `.STL` for 3D printing + `.PDF` 2D drawings.
* **Electronics (`/electronics`):**
  * **Editable Source:** Native `KiCad` project files (`.kicad_pro`, `.kicad_sch`, `.kicad_pcb`).
  * **Fabrication Export:** Schematic `.PDF` + `Gerber` zip + PCB BOM `.csv`.
* **Firmware (`/firmware`):**
  * **Editable Source:** Commented C++ / Arduino `.ino` or PlatformIO source code.

### Rule 3: Declare "Available Components" & Their Interfaces (Clause 1.7)
Because `CERN-OHL-S-2.0` is **Strongly Reciprocal**, every part of your product must either have open-source blueprints **OR** qualify as an **"Available Component"** (a standard COTS part anyone can buy, like your `Mabuchi FF-180SH` motor, `18650` battery, `SKF W 61700` bearing, and `M3` screws).  
* **How we complied:** We created `docs/interfaces.md` (included in this pack!) which defines Interfaces `I-1` to `I-4` and explicitly lists all COTS parts under Clause 1.7.

### Rule 4: Put the License Identifier on Drawings, PCBs & Physical Product (Clause 3 & 4)
1. **On your KiCad PCB Silkscreen (`BOARD.SLDPRT`) and Schematic Title Block:**  
   Add the text: `OpenWhisk 3S v2.0 | CERN-OHL-S-2.0`
2. **On your 2D CAD Drawing Title Blocks:**  
   Add the text: `Licensed under CERN-OHL-S-2.0 — Group 1 (VGU/TUB)`
3. **On the Physical Prototype / Dock (Clause 4.1):**  
   Emboss `CERN-OHL-S-2.0` or stick a small QR code on the bottom of the Countertop Dock pointing to your GitHub repository URL!

---

## 3. Copy-Paste License Badge Block for Your `README.md`

Paste this block at the top or bottom of your main GitHub `README.md`:

```markdown
## License & Open Source Hardware Compliance

**OpenWhisk 3S** is certified-ready Open Source Hardware compliant with the [OSHWA Definition](https://www.oshwa.org/definition.html) and the [REUSE Specification v3.2](https://reuse.software/):

* **Hardware Designs (CAD, STEP, STL, KiCad PCB, BOM):** Licensed under the [**CERN Open Hardware Licence Version 2 - Strongly Reciprocal (`CERN-OHL-S-2.0`)**](LICENSE).
* **Embedded Firmware & Scripts:** Licensed under the [**MIT License (`MIT`)**](LICENSES/MIT.txt).
* **Documentation, Manuals & Media:** Licensed under [**Creative Commons Attribution-ShareAlike 4.0 (`CC-BY-SA-4.0`)**](LICENSES/CC-BY-SA-4.0.txt).
```
