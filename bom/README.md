# Bill of Materials (M3 Design Freeze — `BOM 08.11.2026.xlsx`)

**Source of truth:** [`BOM.xlsx`](BOM.xlsx) (sheet **`BOM 081126`**) and [`BOM.csv`](BOM.csv), synchronized 1-to-1 with the 17-item exploded assembly drawing [`drawings/pdf/ASSEM_INNER.pdf`](../drawings/pdf/ASSEM_INNER.pdf) (`ASSEM_INNER 1046.pdf`).

## 1. Prototype Cost Summary (Action #3 — Completed)
* **Total Prototype Cost:** **€20.64** (all items priced; **0 `TBD` items remaining**).
* **Course Budget Limit:** **≤ €200.00** (**PASS** — prototype uses only **10.3%** of the maximum budget).
* **FabLab 3D Printing Cost:** Filament is costed at **€6.43/kg** (`Creality Soleyin Basic PETG`, ~245 g total across `OUTER_SHELL`, `OUTER_CAP`, `ADAPTER_ASSEM`, `RETAINER`, `INNER_MOUNT` = **€1.92** total). Machine time and printing labor are €0.00.

## 2. Complete 17-CAD-Item Bill of Materials (`BOM 081126`)

| No. | CAD Item # (`ASSEM_INNER`) | Component / Material | Qty | Part Classification | Proposed Model / Specification | Cost (EUR) | Remark |
| :-: | :-: | :--- | :-: | :--- | :--- | :-: | :--- |
| **1** | **2** | **Motor** | 1 | Purchased | **DC Brushed Motor – 130 Series, 3.7 V** (3–6V, 14,500 RPM, w/ bracket) | **0.63** | Target operating speeds: 9k / 11k / 13k rpm |
| **2** | **17** | **Battery** | 1 | Purchased | **Lishen LR1865SK, 18650 Li-ion, 3.65 V, 2600 mAh**, max discharge 5.2 A | **1.22** | Replaceable cell in holder (`CAD #17`); not soldered |
| **3** | **9** | **Charging Interface** | 1 | Purchased | **USB Type-C interface (`TYPE_C.step`)** | **0.06** | Charging/protection integrated into electronics PCB |
| **5** | **3, 4** | **Main Housing** | 1 set (2 parts) | Custom fabricated | **`OUTER_SHELL` + `OUTER_CAP` – PETG prototype** (`Creality Basic PETG`) | **1.42** | ~200 g PETG + 10% contingency; machine/labor = €0 |
| **6** | **6** | **Food-Contact Attachment** | 1 | Custom fabricated | **`WHISKER` – stainless-steel candidate** / commercial reference | **11.00** | Refer quotation of supplier; only food-contact part |
| **7** | **5, 7** | **Tool Connector / Coupling incl. spring** | 1 | Custom fabricated + standard spring | **`ADAPTER_ASSEM` + `RETAINER` + spring** (`Creality Basic PETG`) | **0.30** | ~15–20 g PETG + ~10% allowance; machine/labor = €0 |
| **8** | **11, 12, 14** | **Fasteners** | 10 | Standard hardware | **ASME B18.3.1M / B18.6.7M, M2 × 0.4 × 3 mm** Socket/Flat Head Cap Screws | **0.15** | `CAD #11` (2 pcs), `CAD #12` (6 pcs), `CAD #14` (2 pcs); A2 SS |
| **9** | **10** | **Switch / User Control** | 1 | Purchased | **12 mm waterproof momentary push button with LED** (`BUTTON`) | **1.02** | Intended Low → Medium → High → Off via firmware |
| **10** | **16** | **Speed Control / Motor Driver** | 1 | Purchased | **`DRV8833` motor driver module** (`MOTOR_DRIVER.stp`, 3–10 V, 1.5 A) | **0.52** | Compact DC motor H-bridge PWM driver |
| **11** | **15** | **Controller / Speed Logic** | 1 | Purchased / prototype controller | **`ESP32-C3 SuperMini`** (`MICROCONTROLLER`) | **2.20** | Compact programmable MCU (3-speed PWM + LED control) |
| **13** | **1** | **Inner Mount / Internal Support** | 1 | Custom fabricated | **`INNER_MOUNT` – PETG** (`Creality Basic PETG`) | **0.20** | ~25–30 g PETG @ €6.43/kg + 10% allowance |
| **14** | **8** | **Ball Bearing / Rotational Support** | 1 | Purchased | **`SKF W 61700` – 10 × 15 × 3 mm** (`BALL_BEARING`) | **0.42** | Ø10 mm bore, Ø15 mm OD, 3 mm width |
| **15** | **13** | **Seals / Protective Parts** | 1 | Standard hardware / sealing parts | **USB-C silicone cover** (`RUBBER_COVER`) | **1.50** | Splash protection at liquid-ingress points |
| **16** | **—** | **Prototype Material** | 1 | Consumable material | **PETG filament** (`Creality Soleyin Basic PETG`) | **0.00** | Already included in printed-part costs above |
| **17** | **—** | **Packaging / Documentation** | 1 set | Documentation / consumable | **Digital OSH documentation / GitHub repository** | **0.00** | Public repo under `CERN-OHL-S-2.0` / `CC-BY-SA-4.0` / `MIT` |
| **TOTAL** | **1–17** | **Complete OpenWhisk 3S Prototype** | **17 CAD items** | **All items priced** | **Complies with ≤ €200 Course Budget** | **20.64** | **PASS (10.3% of €200 limit)** |
