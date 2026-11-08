# OSH compliance checklist (M3 — Action #4)

> Owners: **Vân Anh + Thương** (Action tracker #4, due 05.11, status **N → in progress**).
> Purpose: show that this repository contains everything needed for the product to qualify as **open source hardware**
> (M3 requirement, OSHWA definition / DIN SPEC 3105 principles, CERN-OHL-S-2.0).
> Legend: ✅ done · 🟡 partly · ❌ missing · owner = who closes it.

## A. Licence & legal

| # | Requirement | Where | Status | Owner |
|---|---|---|---|---|
| A1 | Full, unmodified CERN-OHL-S-2.0 text in the root | [`LICENSE`](../LICENSE) | ✅ official text (ohwr.org) | Vân Anh |
| A2 | Licence for docs (CC BY-SA 4.0) and firmware (MIT) stated | [`NOTICE.md`](../NOTICE.md), [`firmware/LICENSE`](../firmware/LICENSE) | ✅ | Vân Anh |
| A3 | Copyright holders + how to credit | [`NOTICE.md`](../NOTICE.md) | ✅ (team names to be confirmed, see E3) | Vân Anh |
| A4 | Source location URL (CERN-OHL-S §4.3) | README, NOTICE | 🟡 replace `<team-account>` with the real GitHub account after creating the repo | Vân Anh |
| A5 | Licence note in the CAD drawing title blocks ("CERN-OHL-S-2.0") | `cad/solidworks/drawings` | ❌ | Tùng |
| A6 | Third-party models not redistributed, sources listed | [`cad/third_party/README.md`](../cad/third_party/README.md) | 🟡 table done, exact URLs TODO | Tùng |

## B. Design files (the "source")

| # | Requirement | Where | Status | Owner |
|---|---|---|---|---|
| B1 | Native editable CAD of all custom parts | `cad/solidworks/parts` (11 parts) | ✅ | Tùng |
| B2 | Native assemblies + drawings | `cad/solidworks/assemblies` (3), `/drawings` (7) | ✅ | Tùng |
| B3 | STEP per custom part + full assembly | `cad/step/` | 🟡 only `ADAPTER_ASSEM.STEP`, `ASSEM_INNER.STEP` | Tùng |
| B4 | STL for every printed part | `cad/stl/` | ❌ 8 STL to export (list in `cad/stl/README.md`) | Tùng / Hùng |
| B5 | PDF drawings | `drawings/pdf/` | ❌ 7 PDFs to export | Tùng |
| B6 | CAD updated to the tracker components (130 motor Ø2 mm shaft, bearing choice) | `ASSEM_INNER`, `ADAPTER` | ❌ tracker remark L11 | Tùng |
| B7 | Electronics: block diagram + wiring | [`electronics/wiring.md`](../electronics/wiring.md) | ✅ | Vân Anh / Tùng |
| B8 | Firmware source + build instructions | [`firmware/`](../firmware) | ✅ v0.1 (not yet bench-tested) | Vân Anh |

## C. Bill of materials

| # | Requirement | Where | Status | Owner |
|---|---|---|---|---|
| C1 | BOM in an open format with all items | [`bom/BOM.csv`](../bom/BOM.csv) | ✅ 16 items = tracker `BOM updated` | Vân Anh |
| C2 | Sources/suppliers and cost | BOM.csv | 🟡 €13.82 priced, 4 items TBD | Nga (Action #3) |
| C3 | Custom / purchased classification (≤ 2 purchased) | [`bom/README.md`](../bom/README.md) | ✅ (Action #2 Y), WHISKER classification open | Tùng |
| C4 | BOM item names = CAD file names | BOM.csv "CAD item no." | ✅ | — |

## D. Instructions & evidence

| # | Requirement | Where | Status | Owner |
|---|---|---|---|---|
| D1 | Manufacturing (print settings) | [`docs/manufacturing.md`](manufacturing.md) | ✅ | Hùng |
| D2 | Assembly instructions | [`docs/assembly.md`](assembly.md) | ✅ text · ❌ photos | Thương |
| D3 | Disassembly / repair / end of life | [`docs/disassembly-repair.md`](disassembly-repair.md) | ✅ text · ❌ measured times | Hùng (Action #12) |
| D4 | User guide incl. safety and cleaning | [`docs/user-guide.md`](user-guide.md) | ✅ | Thương |
| D5 | Design rationale (why) | [`docs/design-rationale.md`](design-rationale.md) | ✅ | Tùng |
| D6 | Test plan + records | [`tests/`](../tests) | ✅ plan · ❌ records | Tùng / Hùng |
| D7 | Change history | [`CHANGELOG.md`](../CHANGELOG.md) | ✅ | Vân Anh |
| D8 | Contribution rules for the swap team | [`CONTRIBUTING.md`](../CONTRIBUTING.md) | ✅ | Vân Anh |

## E. Repository publication (GitHub)

| # | Step | Status | Owner |
|---|---|---|---|
| E1 | Create **public** repo `OpenWhisk-3S`, add all lecturers/team as collaborators | ❌ | Vân Anh |
| E2 | Upload all files (largest: ASSEM_INNER.SLDASM 8 MB < GitHub 100 MB limit, so no Git LFS needed) | ❌ | Vân Anh |
| E3 | **Confirm the team names**: README/NOTICE names differ from the M2 meeting-minutes names | ❌ | Vân Anh |
| E4 | Open every file once from GitHub (download → open) to check it is readable/editable | ❌ | Vân Anh + Thương |
| E5 | Add repo topics: `open-source-hardware`, `cern-ohl-s`, `circular-economy`, `fablab` | ❌ | Vân Anh |
| E6 | Tag release `v0.3-M3` and submit the URL + M2 review to Moodle by **08.11.2026 23:59** | ❌ | Vân Anh / Nga |

### Upload commands (Git Bash / PowerShell)
```
cd OpenWhisk-3S
git init
git add .
git commit -m "v0.3-M3 design freeze candidate"
git branch -M main
git remote add origin https://github.com/<team-account>/OpenWhisk-3S.git
git push -u origin main
git tag v0.3-M3 && git push origin v0.3-M3
```
