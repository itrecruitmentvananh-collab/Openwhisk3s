# Disassembly, repair & end of life (`ASSEM_INNER 1046.pdf`)

All joints use `M2 × 0.4 × 3 mm` screws (`CAD #11, #12, #14`), threaded caps (`CAD #4`), snap-fits, or plug connectors — **no glue, no ultrasonic welding**, making every step 100% reversible.

| Task | Steps | Tools | Parts freed (`ASSEM_INNER 1046` CAD #) |
|---|---|---|---|
| Change attachment | Press quick-release button on `ADAPTER_ASSEM` (`#5`), pull attachment out | None | `WHISKER` (`CAD #6`, `BOM #6`) |
| Replace battery | Unscrew/twist `OUTER_CAP` (`#4`), lift cell out of holder (`#17`) | None | `Lishen LR1865SK 18650` cell (`CAD #17`, `BOM #2`) |
| Replace coupling or bearing | Open `OUTER_CAP` (`#4`) → remove 4× M2 housing screws (`#11, #14`) → slide out `INNER_MOUNT` (`#1`) → remove 6× M2 retainer screws (`#12`) → pull `ADAPTER_ASSEM` (`#5`) and `SKF W 61700` (`#8`) | M2 hex / PH1 driver | `ADAPTER_ASSEM` (`#5`), `RETAINER` (`#7`), `BALL_BEARING` (`#8`) |
| Replace motor or electronics | Slide out `INNER_MOUNT` (`#1`), unplug motor/board connectors, remove `MOTOR` (`#2`), `ESP32-C3 SuperMini` (`#15`), `DRV8833` (`#16`), or `BUTTON` (`#10`) | M2 hex / PH1 driver | `MOTOR` (`#2`), `TYPE_C` (`#9`), `BUTTON` (`#10`), `MICROCONTROLLER` (`#15`), `MOTOR_DRIVER` (`#16`) |

Measured disassembly time and condition of parts after re-assembly are recorded in `tests/records/disassembly_*.md`.

## End of life — circular material separation
| Stream | Parts (`ASSEM_INNER 1046` CAD #) |
|---|---|
| **Plastics (`PETG`, code 1 / `>PETG<`)** | `INNER_MOUNT` (`#1`), `OUTER_SHELL` (`#3`), `OUTER_CAP` (`#4`), `ADAPTER_ASSEM` (`#5`), `RETAINER` (`#7`) — reprint or recycle into PETG filament |
| **Metals (Stainless steel & bearing steel)** | `WHISKER` (`#6`), `BALL_BEARING` (`#8`), 10× `M2×3` screws (`#11, #12, #14`), coupling spring |
| **Elastomers / Seals** | `RUBBER_COVER` USB-C silicone plug (`#13`) |
| **WEEE electronics** | `MOTOR` (`#2`), `TYPE_C` (`#9`), `BUTTON` (`#10`), `ESP32-C3 SuperMini` (`#15`), `DRV8833` (`#16`) |
| **Battery collection** | `Lishen LR1865SK 18650` Li-ion cell (`#17`) — remove tool-free before WEEE disposal |
