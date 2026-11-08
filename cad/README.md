# CAD files

## Product structure (from `step/ASSEM_INNER.STEP`, exported 13 Oct 2026)

```
ASSEM_INNER  (complete device)
├── OUTER_SHELL
├── OUTER_CAP
├── INNER_MOUNT
├── RETAINER
├── BEARING               (third-party: SKF W 61700)
├── Standard Motor 030    (third-party)
├── battery 18650 + holder (third-party: cell + 2 contacts)
├── WHISKER               (attachment)
└── ADAPTER_ASSEM
    ├── ADAPTER
    ├── CLAMP
    └── PUSH
```

Parts added after the 13 Oct export (present as SLDPRT/SLDASM, **not yet in the STEP**): `ADAPTER_CAP`, `BOARD`, `SPRING`, `BUTTON.SLDASM`, USB-C connector.
→ **Re-export all STEP files after the design freeze** so native and neutral files match.

## Folders

| Folder | Content | Format |
|---|---|---|
| `solidworks/parts` | Team-designed parts | SLDPRT (SolidWorks 2021) |
| `solidworks/assemblies` | Assemblies | SLDASM |
| `solidworks/drawings` | 2D drawings | SLDDRW |
| `step/` | One STEP per custom part + full assembly | STEP AP203/AP214 |
| `third_party/` | Links to vendor models | README only |

## Opening the assembly
SolidWorks will ask for the missing third-party parts (motor, cell, bearing, connectors). Download them from the links in `third_party/README.md`, place them in `third_party/`, and point SolidWorks to that folder. Without SolidWorks, open `step/ASSEM_INNER.STEP` in FreeCAD (File → Open).

## How to export (SolidWorks)
1. **STEP:** open part → *File → Save As → STEP AP214 (*.step)* → save into `cad/step/` with the same name.
2. **Assembly STEP:** open `ASSEM_INNER.SLDASM` → *Save As → STEP AP214* → option *"Export as one file"*.
3. **STL:** open part → *Save As → STL* → *Options*: units mm, resolution *Fine* → save into `manufacturing/stl/`.
4. **PDF drawing:** open SLDDRW → *Save As → Adobe PDF* → save into `manufacturing/drawings_pdf/`.
