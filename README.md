# OpenWhisk 3S — open-source handheld whisk & milk frother

**Simple · Sustainable · Serviceable.** OpenWhisk 3S is a compact, rechargeable kitchen device with one motor platform and interchangeable attachments: a **milk-frother spring head** and a **small whisk** for eggs, cream and light sauces. It is designed to be built in a FabLab (FDM 3D printing + simple hand assembly), repaired with one screwdriver, and modified by anyone.

> GPE Project 2026/27 — *Open Source Hardware for a Circular Economy* (TU Berlin × VGU), **Group 1**.
> Status: **M3 – Design freeze candidate (v0.3, 08 Nov 2026)**. Some functions are still being validated — see [Status & known gaps](#status--known-gaps).

![Concept visual](images/concept-poster.png)
*Concept visual from M1/M2 (AI-assisted rendering, not a photo of the prototype). Real prototype photos are added to `images/` as they are taken.*

---

## Repository map

| Folder | What is inside | Format |
|---|---|---|
| [`cad/solidworks/`](cad/solidworks) | Original, editable design files (parts, assemblies, drawings) | SolidWorks 2021 (`.SLDPRT/.SLDASM/.SLDDRW`) |
| [`cad/step/`](cad/step) | Neutral exchange files for any CAD tool (FreeCAD, Fusion, Onshape…) | STEP AP203/AP214 |
| [`cad/stl/`](cad/stl) | Print-ready meshes for every 3D-printed part | STL / 3MF |
| [`cad/third-party/`](cad/third-party) | Links to the vendor models of purchased parts (not redistributed) | Markdown |
| [`drawings/pdf/`](drawings/pdf) | Ready-to-view 2D drawings | PDF |
| [`bom/`](bom) | Bill of materials with part numbers, sources, cost, classification | CSV |
| [`electronics/`](electronics) | Block diagram, wiring table, component notes | Markdown (+ Mermaid) |
| [`firmware/`](firmware) | Not required in v0.3 (analogue PWM module); placeholder for a future MCU version | — |
| [`docs/`](docs) | Manufacturing, assembly, disassembly/repair, user guide, design rationale, circularity | Markdown |
| [`tests/`](tests) | Test plan and test records (motor, coupling, splash, cleaning, disassembly) | Markdown / CSV |
| [`images/`](images) | Photos and renders with captions | PNG / JPG |

## Quick start — build one

1. **Print** the custom parts listed in [`bom/BOM.csv`](bom/BOM.csv) from `cad/stl/` (settings: [`docs/manufacturing.md`](docs/manufacturing.md)).
2. **Buy** the purchased/standard items in the BOM (motor, 18650 cell, electronics, fasteners).
3. **Wire** the electronics following [`electronics/wiring.md`](electronics/wiring.md).
4. **Assemble** with [`docs/assembly.md`](docs/assembly.md) — one PH1 screwdriver, no glue, no welding.
5. **Test** with [`tests/TEST_PLAN.md`](tests/TEST_PLAN.md) and record the results in `tests/records/`.

To repair or recycle it, follow [`docs/disassembly-repair.md`](docs/disassembly-repair.md).

## Key facts (v0.3)

| Item | Value | Status |
|---|---|---|
| Main functions | Foam milk; whisk/mix light liquid ingredients | Defined |
| Drive | Precious-metal-brush DC micro motor, 030 size (FF-030PK-12135, 3.0 V nominal, 1–4 V range) | Selected, bench test pending |
| Coupling | Printed adapter on Ø1.5 mm motor shaft, Ø10 mm journal in a 61700 ball bearing, 3 mm hex socket for attachments, push-to-release clamp | CAD done, retention test pending |
| Power | 1 × 18650 Li-ion cell (replaceable, in holder), USB-C charging | Concept, runtime estimated |
| Speed control | PWM, user button | Concept |
| Housing | FDM-printed PETG (prototype) | Selected |
| Food contact | Stainless-steel attachments; printed parts outside the food zone | Boundary defined, material docs pending |
| Prototype cost | Estimated well below €200 (see BOM) | Estimate, quotes pending |
| Licence | CERN-OHL-S-2.0 (hardware) · CC BY-SA 4.0 (docs) | Applied |

## Status & known gaps

We document decisions and failures as we go. Open items at M3 (tracked in [`CHANGELOG.md`](CHANGELOG.md) and the test records):

- Motor torque for the **whisk** attachment is marginal on paper (see [`docs/design-rationale.md`](docs/design-rationale.md#motor-selection)); bench test decides whether we keep the 030 motor or move to a 130-size motor.
- Splash protection, cleanability and non-destructive disassembly still need test evidence.
- STEP/STL/PDF exports of every native file are being completed (see checklist in [`CONTRIBUTING.md`](CONTRIBUTING.md)).

## How to contribute / upgrade it

This repository is part of a **design swap**: another team will upgrade this product. Read [`CONTRIBUTING.md`](CONTRIBUTING.md) for the folder rules, file naming, and how to propose changes (fork → branch → pull request). Please keep every derived design open under the same licence.

## Licence

- **Hardware** (CAD, drawings, BOM, electronics): [CERN Open Hardware Licence Version 2 – Strongly Reciprocal](LICENSE) (`CERN-OHL-S-2.0`).
- **Documentation and images**: [Creative Commons Attribution-ShareAlike 4.0](https://creativecommons.org/licenses/by-sa/4.0/) (`CC-BY-SA-4.0`).
- **Software/firmware** (if added later): MIT.
- Third-party vendor models are **not** covered by these licences and are not redistributed — see [`cad/third_party/README.md`](cad/third_party/README.md).

Source location (required by CERN-OHL-S §4.3): `https://github.com/itrecruitmentvananh-collab/Openwhisk3s`

See [`NOTICE.md`](NOTICE.md) for copyright holders and how to credit the project.

## Team (Group 1)

| Member | Main role |
|---|---|
| Trần Thiên Nga | Sourcing, BOM costing, compliance QA |
| Lê Thị Vân Anh | Project management, platform, repository |
| Phạm Hoài Thương | Technical documentation, assembly manual |
| Lê Văn Đông | Requirements, mechanical CAD |
| Võ Sỹ Hùng | Testing, manufacturability |
| Ngô Hoàng Quân | Mechanical CAD |
| Trần Việt Tùng | Mechanical CAD, architecture, drive & coupling |

Lecturers: Valentin Eingartner, Felix von Amelunxen.
