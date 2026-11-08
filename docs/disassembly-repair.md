# Disassembly, repair & end of life

All joints are screws, snap-fits or plugs — **no glue, no welding**, so every step is reversible.

| Task | Steps | Tools | Parts freed |
|---|---|---|---|
| Change attachment | Press PUSH, pull attachment | none | whisk / frother head |
| Replace cell | Unscrew/twist OUTER_CAP, take cell out of holder | none | 18650 cell |
| Replace wear parts of coupling | Open OUTER_CAP → remove screws → slide out ASSEM_INNER → unclip CLAMP, PUSH, SPRING → pull ADAPTER off shaft | PH1 | ADAPTER, CLAMP, PUSH, SPRING, bearing |
| Replace motor / electronics | As above, unplug JST connectors, slide motor/BOARD out | PH1 | motor, charger, PWM, button |

Measured disassembly time and condition of parts after re-assembly are recorded in `tests/records/disassembly_*.md`.

## End of life — separation
| Stream | Parts |
|---|---|
| Plastics (PETG, code 1 / >PETG<) | all printed parts — reprint or recycle into filament |
| Metals | stainless attachments, bearing, screws, inserts |
| WEEE electronics | motor, charger, PWM module, button, wires |
| Battery collection | 18650 cell (never in household waste) |
