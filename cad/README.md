# CAD files (`ASSEM_INNER 1046.pdf` & `BOM 08.11.2026.xlsx`)

## 1. Product Structure (17-Item Exploded Assembly — `ASSEM_INNER 1046.pdf`)

```
ASSEM_INNER (Complete 17-Item OpenWhisk 3S Assembly — Total Prototype Cost: €20.64)
├── #1  INNER_MOUNT             (Custom FDM PETG — BOM #13, €0.20)
├── #2  MOTOR                   (130 Series 3.7 V DC Brushed Motor — BOM #1, €0.63)
├── #3  OUTER_SHELL             (Custom FDM PETG — BOM #5, €1.42 with OUTER_CAP)
├── #4  OUTER_CAP               (Custom FDM PETG — BOM #5)
├── #5  ADAPTER_ASSEM           (Custom FDM PETG: ADAPTER + CLAMP + PUSH + ADAPTER_CAP + SPRING — BOM #7, €0.30)
├── #6  WHISKER                 (Custom-Fabricated 304 Stainless-Steel Attachment — BOM #6, €11.00)
├── #7  RETAINER                (Custom FDM PETG — BOM #7)
├── #8  BALL_BEARING            (SKF W 61700, 10 × 15 × 3 mm, Ø10 mm bore — BOM #14, €0.42)
├── #9  TYPE_C.step             (USB Type-C PCB Connector — BOM #3, €0.06)
├── #10 BUTTON                  (12 mm Waterproof Momentary Push Button with LED — BOM #9, €1.02)
├── #11 socket head cap screw   (2× M2 × 0.4 × 3 mm Socket Cap Screws — BOM #8, €0.15 total for 10 pcs)
├── #12 B18.6.7M M2×0.4×3 FHMS  (6× M2 × 0.4 × 3 mm Cross-Recessed Flat Head Screws — BOM #8)
├── #13 RUBBER_COVER            (USB-C Silicone Dust/Splash Cover — BOM #15, €1.50)
├── #14 B18.3.1M M2×0.4×3 SHCS  (2× M2 × 0.4 × 3 mm Hex Socket Head Cap Screws — BOM #8)
├── #15 MICROCONTROLLER         (ESP32-C3 SuperMini Programmable MCU — BOM #11, €2.20)
├── #16 MOTOR_DRIVER.stp        (DRV8833 Dual H-Bridge Motor Driver Module — BOM #10, €0.52)
└── #17 battery 18650+holder    (Lishen LR1865SK 18650 3.65 V 2600 mAh Li-ion Cell + Holder — BOM #2, €1.22)
```

## 2. Folders in `cad/`

| Folder | Content | Format |
|---|---|---|
| [`solidworks/parts/`](solidworks/parts) | Editable native CAD for all custom parts (`ADAPTER`, `ADAPTER_CAP`, `BOARD`, `CLAMP`, `INNER_MOUNT`, `OUTER_CAP`, `OUTER_SHELL`, `PUSH`, `RETAINER`, `SPRING`, `WHISKER`) | SolidWorks (`.SLDPRT`) |
| [`solidworks/assemblies/`](solidworks/assemblies) | Editable native sub-assemblies and top-level assembly (`ADAPTER_ASSEM`, `ASSEM_INNER`, `BUTTON`) | SolidWorks (`.SLDASM`) |
| [`solidworks/drawings/`](solidworks/drawings) | Editable native 2D engineering drawings | SolidWorks (`.SLDDRW`) |
| [`step/`](step) | Neutral CAD exchange files (`ADAPTER_ASSEM.STEP`, `ASSEM_INNER.STEP`) for FreeCAD / Fusion / Onshape | STEP (`AP203`/`AP214`) |
| [`stl/`](stl) | Print-ready mesh export guide for FabLab FDM 3D printing | `.STL` / `.3MF` |
| [`third_party/`](third_party) | Sourcing & reference links for off-the-shelf `Available Components` (`CERN-OHL-S-2.0` §1.7) | Markdown |

## 3. Opening and Exporting Files
* **With SolidWorks:** Open `solidworks/assemblies/ASSEM_INNER.SLDASM`. Reference models for off-the-shelf parts are listed in [`third_party/README.md`](third_party/README.md).
* **With FreeCAD / Fusion 360 / Onshape:** Open `step/ASSEM_INNER.STEP` or `step/ADAPTER_ASSEM.STEP` directly (`File → Open`).
* **2D PDF Drawings:** Ready-to-view PDFs (including the 17-item exploded assembly drawing [`ASSEM_INNER.pdf`](../drawings/pdf/ASSEM_INNER.pdf)) are located in [`drawings/pdf/`](../drawings/pdf).
