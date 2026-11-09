# Test record — T2 Motor under load — Whisk (`CAD #2, #6, #8`)
- **Date / place:** 2026-11-08 (M3 analytical baseline) / VGU FabLab (M4 bench run)
- **Tester(s):** Trần Việt Tùng, Võ Sỹ Hùng
- **Design version / commit:** `v0.3-M3` (`ASSEM_INNER 1046.pdf`, `BOM 081126`)
- **Components under test:** `DC Brushed Motor – 130 Series, 3.7 V` (`CAD #2`, `BOM #1`), `SKF W 61700` Ball Bearing (`10 × 15 × 3 mm`, `CAD #8`, `BOM #14`), `WHISKER` (`CAD #6`, `BOM #6`)
- **Equipment:** Digital multimeter, tachometer app, IR thermometer, 2 whole eggs / 100 ml light cream

| Run | Input / condition | Analytical / Expected M3 Baseline | Measured M4 Bench Values | Observation |
|---|---|---|---|---|
| 1 | 2 eggs, 2 min continuous at Level 1 (`~2.50 V` avg, target `~9,000 RPM`) | Previous `030` motor required `43–75%` of stall torque (`0.40–0.64 A`); upgraded `130 Series 3.7 V` motor provides higher stall torque margin | *Pending physical print & bench assembly* | No stall; verify `SKF W 61700` (`CAD #8`) eliminates radial shaft wobble |
| 2 | 100 ml light cream, 2 min at Level 2 (`~3.10 V` avg, target `~11,000 RPM`) | Smooth aeration without stalling; `DRV8833` (`1.5 A` rated) stays well within limit | *Pending physical print & bench assembly* | Check `T_motor < 60 °C` after 2 min continuous run |
| 3 | Side-load check on `WHISKER` (`CAD #6`) | Radial load absorbed by `SKF W 61700` (`10 × 15 × 3 mm`) inside `INNER_MOUNT` (`CAD #1`) | *Pending physical print & bench assembly* | Inspect bearing seat after 2 min run |

**Result:** **M3 DESIGN UPGRADE COMPLETED (`030` $\rightarrow$ `130 Series`) / M4 BENCH PENDING**
**What we learned / design change triggered:** Analytical load calculation on the `FF-030PK` motor showed whisking used up to `75%` of stall torque (marginal). This directly triggered the upgrade to the **`130 Series 3.7 V DC Brushed Motor` (`CAD #2`, `BOM #1`)** and the unification of the **`SKF W 61700` (`10 × 15 × 3 mm`)** ball bearing (`CAD #8`, `BOM #14`).
