# Contributing to OpenWhisk 3S

Thank you for improving OpenWhisk 3S. This repository will be handed to another team in the **design swap**,
so please follow these rules. Everyone can then still build, repair and modify the product.

## 1. Licences you agree to by contributing

| You change… | Licence of your contribution |
|---|---|
| CAD, drawings, BOM, electronics | CERN-OHL-S-2.0 ([`LICENSE`](LICENSE)) — derived designs must stay open, with source |
| Documentation, images, tests | CC BY-SA 4.0 |
| Firmware | MIT ([`firmware/LICENSE`](firmware/LICENSE)) |

Keep [`NOTICE.md`](NOTICE.md). Add yourself as a contributor and state **what** you changed and **when** (CERN-OHL-S §3.3).

## 2. Folder rules

| Put… | in… |
|---|---|
| Native CAD (always — it is the "source" under CERN-OHL-S) | `cad/solidworks/parts`, `/assemblies`, `/drawings` |
| One STEP per custom part + full assembly | `cad/step/` |
| One STL per printed part | `cad/stl/` |
| PDF of every drawing | `drawings/pdf/` |
| Vendor models (only links, unless the licence allows redistribution) | `cad/third_party/README.md` |
| BOM changes | `bom/BOM.csv` **and** `bom/BOM.xlsx` (same content) |
| Test results | `tests/records/` using [`_TEMPLATE.md`](tests/records/_TEMPLATE.md) |
| Photos | `images/YYYYMMDD_description.jpg` + a caption line in `images/README.md` |

## 3. File naming

- CAD: `PART_NAME` in capitals, the **same name** in native, STEP, STL, PDF and BOM (e.g. `INNER_MOUNT.SLDPRT / .STEP / .stl / .pdf`).
- Revisions go in Git history and `CHANGELOG.md`, **not** in file names (`INNER_MOUNT_v2_final.SLDPRT` ✘).
- No spaces in file or folder names.

## 4. How to propose a change

1. **Fork** the repository → create a **branch** (`feature/whisk-head-v2`, `fix/adapter-bore`).
2. Change the native file **and** re-export STEP/STL/PDF.
3. Update `bom/BOM.csv` if parts change, and add a line to `CHANGELOG.md`: *date — change — reason — owner*.
4. Open a **pull request** that describes what changed, why, and which test (`tests/TEST_PLAN.md`) shows it works.
5. Large binary files (> 50 MB): use Git LFS. Current files are all < 10 MB, below GitHub's 100 MB limit, so plain Git is fine.

## 5. Checklist before a pull request

- [ ] Native file + STEP + STL (+ PDF if a drawing changed) committed
- [ ] BOM updated (CSV + XLSX)
- [ ] CHANGELOG entry
- [ ] No vendor CAD model added without a licence that allows it
- [ ] Safety-relevant change (battery, charging, rotating parts)? → tested and recorded in `tests/records/`

Questions: open a GitHub **Issue**.
