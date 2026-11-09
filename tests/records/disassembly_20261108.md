# Test record — T7 Non-destructive disassembly & repair (`CAD #11, #12, #14`)
- **Date / place:** 2026-11-08 (M3 CAD exploded verification) / VGU FabLab (M4 timed teardown)
- **Tester(s):** Võ Sỹ Hùng, Phạm Hoài Thương
- **Design version / commit:** `v0.3-M3` (`ASSEM_INNER 1046.pdf`, `docs/disassembly-repair.md`)
- **Components under test:** Complete 17-item assembly (`CAD #1`–`#17`), `10× M2 × 0.4 × 3 mm` stainless screws (`CAD #11` [2 pcs], `CAD #12` [6 pcs], `CAD #14` [2 pcs], `BOM #8`, `€0.15`)
- **Equipment:** M2 hex / PH1 screwdriver, stopwatch

| Run | Disassembly / Repair Operation | Fasteners / Mechanism (`ASSEM_INNER 1046`) | Measured M4 Time | Observation |
|---|---|---|---|---|
| 1 | Attachment swap (`WHISKER` `CAD #6`) | Tool-free quick-release (`PUSH` + `CLAMP` + `SPRING` in `CAD #5`) | *Target $< 5\text{ s}$* | Zero tools required |
| 2 | Battery replacement (`Lishen 18650` `CAD #17`) | Unscrew threaded `OUTER_CAP` (`CAD #4`) by hand; lift cell from spring holder (`CAD #17`) | *Target $< 15\text{ s}$* | Zero tools, zero desoldering required |
| 3 | Full teardown to replace `MOTOR` (`#2`), `BALL_BEARING` (`#8`), `ESP32-C3` (`#15`), or `DRV8833` (`#16`) | Remove 4× housing screws (`CAD #11, #14`) $\rightarrow$ slide out `INNER_MOUNT` (`#1`) $\rightarrow$ remove 6× retainer screws (`CAD #12`) | *Pending 3 timed repetitions on physical print* | Zero glue, zero ultrasonic welding; 100% reversible |

**Result:** **M3 CAD REVERSIBILITY VERIFIED (`10× M2×3` SCREWS, 0 GLUE) / M4 STOPWATCH LOG PENDING**
**What we learned / design change triggered:** Standardized all mechanical fasteners to **10× `M2 × 0.4 × 3 mm` stainless-steel screws (`CAD #11, #12, #14`, `BOM #8`)** and removed the unvalidated M1 `< 90 s` marketing claim until 3 physical stopwatch runs are logged in M4.
