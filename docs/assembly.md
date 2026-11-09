# Assembly instructions (v0.3)

Tools: screwdriver (M2 / PH1), soldering iron (motor & board leads), heat-gun or lighter. Time around 30–45 min first build.

1. **Inserts / Fasteners** — Prepare the printed PETG parts (INNER_MOUNT #1, OUTER_SHELL #3, OUTER_CAP #4, ADAPTER_ASSEM #5, RETAINER #7) and the 10× M2 × 0.4 × 3 mm screws (CAD #11, #12, #14).
2. **Motor (CAD #2)** — Solder the red (+) and black (-) motor leads on the **130 Series 3.7 V DC motor**, add heat-shrink, and slide the motor into INNER_MOUNT (#1, locks into place without glue).
3. **Bearing (CAD #8)** — Press the **SKF W 61700 (10 × 15 × 3 mm)** bearing into INNER_MOUNT (#1) and secure it with RETAINER (#7) using 6× M2 × 0.4 × 3 mm flat-head screws (CAD #12).
4. **Adapter (CAD #5)** — Push the ADAPTER (Ø2.0 mm shaft bore, Ø10.0 mm bearing journal) onto the motor shaft through the bearing, then attach ADAPTER_CAP.
5. **Quick-release (CAD #5)** — Insert the spring and PUSH button, then snap CLAMP into place. Make sure the button springs back on its own.
6. **Electronics (CAD #9, #10, #15, #16)** — Mount and wire the **USB-C connector** (CAD #9), **12 mm waterproof LED push button** (CAD #10), **ESP32-C3 SuperMini microcontroller** (CAD #15), and **DRV8833 motor driver** (CAD #16) following [electronics/wiring.md](../electronics/wiring.md).
7. **Inner assembly & USB-C seal (CAD #3, #11, #13, #14)** — Fit the **RUBBER_COVER USB-C silicone cover** (CAD #13), slide the inner assembly into OUTER_SHELL (#3), align the USB-C port and button, and secure with the M2 × 0.4 × 3 mm socket head cap screws (CAD #11, #14).
8. **Battery (CAD #17) & Cap (CAD #4)** — Insert the **Lishen LR1865SK 18650** cell into the holder (CAD #17, positive side matching the mark) and close OUTER_CAP (#4).
9. **Function check (CAD #6)** — Charge via USB-C, press the 12 mm illuminated button (CAD #10) to cycle through Low (9k) → Medium (11k) → High (13k) → Off, and click the stainless-steel **WHISKER (CAD #6)** into the coupling to verify locking.
