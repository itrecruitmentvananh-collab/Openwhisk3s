# Test record — T1 Motor under load — Frother (`CAD #2, #6`)
- **Date / place:** 2026-11-08 (M3 analytical baseline) / VGU FabLab (M4 bench run)
- **Tester(s):** Trần Việt Tùng, Võ Sỹ Hùng
- **Design version / commit:** `v0.3-M3` (`ASSEM_INNER 1046.pdf`, `BOM 081126`)
- **Components under test:** `DC Brushed Motor – 130 Series, 3.7 V` (`CAD #2`, `BOM #1`), `DRV8833` (`CAD #16`, `BOM #10`), `WHISKER` (`CAD #6`, `BOM #6`)
- **Equipment:** Digital multimeter (current `I`), optical tachometer / strobe app (RPM), IR thermometer (`T_motor`), 150 ml milk in beaker

| Run | Input / condition | Analytical / Expected M3 Baseline | Measured M4 Bench Values | Observation |
|---|---|---|---|---|
| 1 | 150 ml milk, 30 s, Level 3 (`~3.65 V` avg PWM, target `~13,000 RPM`) | Power law $P = N_p \rho n^3 D^5$: `0.15–0.39 A` (`11–43%` of 030 stall; lower % on 130 series) | *Pending physical print & bench assembly* | Stable foam expected in $\le 30\text{ s}$, $T_{\text{motor}} < 60\text{ °C}$ |
| 2 | 150 ml milk, 30 s, Level 2 (`~3.10 V` avg PWM, target `~11,000 RPM`) | Moderate vortex & micro-foam, `I < 0.35 A` | *Pending physical print & bench assembly* | Verify splash-free start via `0.5 s` firmware soft-start ramp |
| 3 | 150 ml milk, 30 s, repeat thermal check | $T_{\text{motor}} < 60\text{ °C}$ | *Pending physical print & bench assembly* | Check `INNER_MOUNT` (`CAD #1`) PETG temperature |

**Result:** **M3 ANALYTICAL PASS / M4 PHYSICAL BENCH PENDING**
**What we learned / design change triggered:** Power-law modeling confirmed milk foaming is well within torque limits; `130 Series 3.7 V` motor (`CAD #2`) selected in `BOM 081126` (`€0.63`) to ensure thermal headroom across all 3 speeds (`9k / 11k / 13k RPM`).
