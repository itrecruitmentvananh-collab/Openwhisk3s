# OSH compliance checklist (M3 — Action #4 — Updated 08.11.2026)

> Owners: **Vân Anh + Thương** (Action tracker #4, completed **08.11.2026**).
> Purpose: verify that this repository contains everything needed for **OpenWhisk 3S** to qualify as **Open Source Hardware** (OSHWA definition / DIN SPEC 3105-1, licensed under `CERN-OHL-S-2.0`).
> Legend: ✅ done · 🟡 physical bench-test pending (M4 prototyping)

## A. Licence & legal

| # | Requirement | Where | Status | Owner |
|---|---|---|---|---|
| A1 | Full, unmodified `CERN-OHL-S-2.0` text in the root | [`LICENSE.txt`](../LICENSE.txt) & [`LICENSE`](../LICENSE) | ✅ Official text included | Vân Anh |
| A2 | Licence for docs (`CC-BY-SA-4.0`) and firmware (`MIT`) stated | [`NOTICE.md`](../NOTICE.md), [`firmware/LICENSE`](../firmware/LICENSE) | ✅ Completed | Vân Anh |
| A3 | Copyright holders + attribution instructions | [`NOTICE.md`](../NOTICE.md) | ✅ All 7 Group 1 members listed | Vân Anh |
| A4 | Source location URL (CERN-OHL-S §4.3) | [`README.md`](../README.md), [`NOTICE.md`](../NOTICE.md) | ✅ `https://github.com/itrecruitmentvananh-collab/Openwhisk3s` | Vân Anh |
| A5 | 2D engineering drawings & 17-item exploded BOM drawing | [`drawings/pdf/ASSEM_INNER.pdf`](../drawings/pdf/ASSEM_INNER.pdf) | ✅ Synchronized with `ASSEM_INNER 1046.pdf` | Tùng / Đông / Quân |
| A6 | Third-party models documented with sourcing URLs | [`cad/third_party/README.md`](../cad/third_party/README.md) | ✅ Updated for all purchased CAD items | Tùng / Vân Anh |

## B. Design files (the "source")

| # | Requirement | Where | Status | Owner |
|---|---|---|---|---|
| B1 | Native editable CAD of all custom parts | [`cad/solidworks/parts/`](../cad/solidworks/parts) (11 `.SLDPRT` files) | ✅ Uploaded | Tùng |
| B2 | Native assemblies + drawings | [`cad/solidworks/assemblies/`](../cad/solidworks/assemblies) (3), [`drawings/`](../cad/solidworks/drawings) (7) | ✅ Uploaded | Tùng |
| B3 | Neutral STEP files for custom assemblies | [`cad/step/`](../cad/step) (`ADAPTER_ASSEM.STEP`, `ASSEM_INNER.STEP`) | ✅ Uploaded | Tùng |
| B4 | Print-ready STL guide & parameters | [`cad/stl/README.md`](../cad/stl/README.md), [`docs/manufacturing.md`](manufacturing.md) | ✅ Documented | Tùng / Hùng |
| B5 | 2D PDF engineering drawings | [`drawings/pdf/`](../drawings/pdf) (7 PDFs incl. 17-item `ASSEM_INNER.pdf`) | ✅ Uploaded | Tùng / Đông / Quân |
| B6 | CAD & BOM unified (`130 Motor`, `SKF W 61700` 10×15×3mm, `ESP32-C3 SuperMini`, `DRV8833`, `RUBBER_COVER`, 10× `M2×3` screws) | [`drawings/pdf/ASSEM_INNER.pdf`](../drawings/pdf/ASSEM_INNER.pdf) & [`bom/BOM.xlsx`](../bom/BOM.xlsx) | ✅ Completed in `ASSEM_INNER 1046` & `BOM 081126` | Tùng / Nga |
| B7 | Electronics block diagram + pin-to-pin wiring | [`electronics/wiring.md`](../electronics/wiring.md) | ✅ Updated for `ESP32-C3 SuperMini` + `DRV8833` + `12mm LED Button` | Vân Anh / Tùng |
| B8 | Firmware source + unit tests + flashing guide | [`firmware/`](../firmware) | ✅ v0.3 ready (`ESP32-C3 SuperMini` USB-C flashing) | Vân Anh |

## C. Bill of materials (`BOM 08.11.2026.xlsx` — Sheet `BOM 081126`)

| # | Requirement | Where | Status | Owner |
|---|---|---|---|---|
| C1 | Complete BOM in open `.CSV` and `.XLSX` formats | [`bom/BOM.csv`](../bom/BOM.csv), [`bom/BOM.xlsx`](../bom/BOM.xlsx) | ✅ 15 BOM rows covering all 17 CAD items | Nga / Vân Anh |
| C2 | Sources/suppliers and complete cost estimate | [`bom/BOM.csv`](../bom/BOM.csv), [`bom/README.md`](../bom/README.md) | ✅ **€20.64 total** (**0 `TBD` items**; ≤ €200 limit) | Nga (Action #3) |
| C3 | Custom / purchased classification | [`bom/README.md`](../bom/README.md) | ✅ Completed (`WHISKER` custom-fabricated @ €11.00) | Tùng / Nga |
| C4 | 1-to-1 CAD item number mapping (`1–17`) | [`bom/BOM.csv`](../bom/BOM.csv) Column B ("CAD item no.") | ✅ Matches `ASSEM_INNER 1046.pdf` balloons `1–17` | Tùng / Vân Anh |

## D. Instructions & evidence

| # | Requirement | Where | Status | Owner |
|---|---|---|---|---|
| D1 | Manufacturing (FDM PETG print settings) | [`docs/manufacturing.md`](manufacturing.md) | ✅ Completed | Hùng |
| D2 | Step-by-step assembly instructions | [`docs/assembly.md`](assembly.md) | ✅ Updated for 17-item `ASSEM_INNER 1046` | Thương |
| D3 | Disassembly / repair / end of life | [`docs/disassembly-repair.md`](disassembly-repair.md) | ✅ Completed (bench timing recorded in M4) | Hùng (Action #12) |
| D4 | User guide incl. safety and cleaning | [`docs/user-guide.md`](user-guide.md) | ✅ Completed | Thương |
| D5 | Design rationale & engineering calculations | [`docs/design-rationale.md`](design-rationale.md) | ✅ Updated for `BOM 081126` | Tùng |
| D6 | Test plan + test record templates | [`tests/TEST_PLAN.md`](../tests/TEST_PLAN.md) | ✅ Plan ready · 🟡 physical test logs in M4 | Tùng / Hùng |
| D7 | Change history (`v0.1` → `v0.2` → `v0.3-M3`) | [`CHANGELOG.md`](../CHANGELOG.md) | ✅ Updated `08.11.2026` | Vân Anh |
| D8 | Contribution rules for the design-swap team | [`CONTRIBUTING.md`](../CONTRIBUTING.md) | ✅ Completed | Vân Anh |

## E. Repository publication (GitHub)

| # | Step | Status | Owner |
|---|---|---|---|
| E1 | Public GitHub repository live at `https://github.com/itrecruitmentvananh-collab/Openwhisk3s` | ✅ Live & Public | Vân Anh |
| E2 | All 90+ CAD, drawing, BOM, firmware, and documentation files uploaded | ✅ Completed | Vân Anh |
| E3 | All 7 Group 1 team members credited in `NOTICE.md` | ✅ Completed | Vân Anh |
| E4 | `Group1_M3.pdf` prepared with repo URL + Concept & Feasibility Review for Moodle upload | ✅ Ready for Moodle (`08.11.2026 23:59`) | Vân Anh / Nga |
