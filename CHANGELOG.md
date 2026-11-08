# Changelog

All notable design decisions are recorded here (newest first). Format: date — change — reason — owner.

## v0.3-M3 — 2026-11-08 (design-freeze candidate)

- Repository structured for OSH publication (native CAD, exports, BOM, docs, tests, licences) — M3 requirement — Vân Anh/Thương
- Drive coupling detailed: printed ADAPTER (shaft bore, journal, 3 mm hex socket) + CLAMP/PUSH quick release, ball bearing — secure, tool-free attachment change — Tùng
- Motor 030 (FF-030PK) → **130 series 3.7 V** — whisking marginal with the 030 motor — tracker BOM #1 (CAD ADAPTER bore Ø1.5 → Ø2.0 still to update)
- Battery fixed: **Lishen LR1865SK 18650**, 3.65 V, 2600 mAh — tracker BOM #2
- Speed control: 12 mm waterproof momentary button + **DRV8833** — tracker BOM #8/#9; **firmware v0.1 (ATtiny85)** added to generate the PWM and the 3 speeds — Vân Anh
- Mini 560 step-down flagged as not usable from one 3.65 V cell (needs ~7–20 V in) — tracker BOM #10 J-column
- Housing filament: Creality Soleyin Basic PETG — tracker BOM #4/#12
- BOM replaced by the tracker's `BOM updated` sheet: €13.82 for the priced items, 4 items TBD — old drafts moved to `bom/archive/`
- Official CERN-OHL-S-2.0 text added to `LICENSE`; `CONTRIBUTING.md` and `docs/OSH_COMPLIANCE_CHECKLIST.md` added; broken links fixed; `pdf drawings/pdf` → `drawings/pdf`

## v0.2-M2 — 2026-10-25

- Scope narrowed from "mix food" to "whisk/mix light liquids \+ foam milk".  
- Injection-moulded PP replaced by FDM printing for the prototype (FabLab constraint).  
- Splash protection and food-contact boundary added as explicit requirements.  
- Unvalidated claims (teardown time, resin saving) removed.

## v0.1-M1 — 2026-10-04

- First concept: modular handheld mixer \+ frother, 18650 cell, USB-C, interchangeable tools.