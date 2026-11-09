# Test Records — OpenWhisk 3S (`tests/records/`)

This folder contains the verification test records corresponding to [`tests/TEST_PLAN.md`](../TEST_PLAN.md) for the **OpenWhisk 3S** 17-item assembly (`ASSEM_INNER 1046.pdf` & `BOM 08.11.2026.xlsx`).

## Summary of Test Records (`T1` – `T9`)

| Test ID | Record File | Component / Subsystem Under Test | Status at M3 | Owner |
| :-: | :--- | :--- | :--- | :--- |
| **T1** | [`motor_frother_20261108.md`](motor_frother_20261108.md) | `130 Series 3.7 V Motor` (`CAD #2`) + `WHISKER` (`CAD #6`) — Milk Frothing Load | **Analytical Pre-Check PASS** · Physical bench logging scheduled (M4) | Trần Việt Tùng |
| **T2** | [`motor_whisk_20261108.md`](motor_whisk_20261108.md) | `130 Series 3.7 V Motor` (`CAD #2`) + `SKF W 61700` (`CAD #8`) — Whisking Load | **Analytical Upgrade (`030` → `130`)** · Physical bench logging scheduled (M4) | Trần Việt Tùng |
| **T3** | [`coupling_20261108.md`](coupling_20261108.md) | `ADAPTER_ASSEM` (`CAD #5`) + `RETAINER` (`CAD #7`) + `SKF W 61700` (`CAD #8`) | **CAD Fit Verified (`Ø2.0 mm` / `Ø10.0 mm`)** · 20-cycle test scheduled (M4) | Trần Việt Tùng |
| **T4** | [`runtime_20261108.md`](runtime_20261108.md) | `Lishen LR1865SK 18650 3.65 V 2600 mAh` (`CAD #17`) Runtime & `3.20 V` Cutoff | **Energy Budget Verified (`9.49 Wh`)** · Discharge test scheduled (M4) | Võ Sỹ Hùng |
| **T5** | [`splash_20261108.md`](splash_20261108.md) | `RUBBER_COVER` USB-C Seal (`CAD #13`) + `12 mm Waterproof Button` (`CAD #10`) | **Seal Geometry Verified in CAD** · Tap-rinse test scheduled (M4) | Trần Việt Tùng |
| **T6** | [`cleaning_20261108.md`](cleaning_20261108.md) | Stainless `WHISKER` (`CAD #6`) & Non-Food-Contact PETG Housing (`CAD #3, #4`) | **Boundary Defined** · Residue check scheduled (M4) | Trần Việt Tùng / Trần Thiên Nga |
| **T7** | [`disassembly_20261108.md`](disassembly_20261108.md) | `10× M2 × 0.4 × 3 mm` Screws (`CAD #11, #12, #14`) & Solderless Holder (`CAD #17`) | **17-Item Exploded Sequence Verified** · Stopwatch timing scheduled (M4) | Võ Sỹ Hùng |
| **T8** | [`charging_20261108.md`](charging_20261108.md) | `USB Type-C` (`CAD #9`) + Integrated PCB Charging & `18650` Cell (`CAD #17`) | **Architecture Verified** · Thermal & cutoff test scheduled (M4) | Võ Sỹ Hùng |
| **T9** | [`firmware_20261108.md`](firmware_20261108.md) | `ESP32-C3 SuperMini` (`CAD #15`) + `DRV8833` (`CAD #16`) + `12 mm LED Button` (`CAD #10`) | **PASS (19/19 Automated Unit Tests Verified)** | Lê Thị Vân Anh / Trần Việt Tùng |
