# Design rationale (why we chose what we chose)

Components follow the team's `Action tracker.xlsx` (`BOM updated` + `BOM Criteria`). Numbers marked *estimate* are
not yet test evidence.

## Function structure
Supply power → control speed → generate rotation → transmit torque → hold/change attachment → act on milk/food.
Supporting: recharge, protect user, secure attachment, resist splashes.

## Motor selection

### Step 1 (M2): 030-size motor evaluated
Candidate: **FF-030PK-12135** precious-metal-brush motor (datasheet, 3.0 V): no-load 10 500 rpm / 0.064 A;
max efficiency 8 410 rpm, 0.411 mN·m, 0.231 A, 52 %; max power 0.53 W at 6 265 rpm, 0.946 mN·m;
stall 1.89 mN·m, 0.833 A; Kt = 2.462 mN·m/A; regulation 5 675 rpm/mN·m.

Load estimate (mixing power law P = Np·ρ·n³·D⁵, torque T = P/ω), solved against the motor line n = n0 − 5675·T:

| Head | Np (assumed range) | Loaded speed | Torque | Current @3 V | % of stall torque |
|---|---|---|---|---|---|
| Frother spring Ø22 mm | 0.01 – 0.10 | 9 340 – 5 890 rpm | 0.21 – 0.81 mN·m | 0.15 – 0.39 A | 11 – 43 % |
| Whisk Ø35 mm | 0.01 – 0.10 | 5 850 – 2 440 rpm | 0.82 – 1.42 mN·m | 0.40 – 0.64 A | 43 – 75 % |

Conclusion: foaming feasible, **whisking marginal** with the 030 motor (> 50 % of stall torque risks overheating).
The decision rule was: if marginal → switch to a **130-size motor (same voltage class)**.

### Step 2 (M3): 130-series motor selected (tracker BOM #1)
**DC brushed motor 130 series, 3.7 V** (listing: 3–6 V, 14 500 rpm, with mounting bracket; supplier picture: body 25 × 20 × 15 mm,
shaft Ø2 mm × 7.5 mm), €0.63. A 130 motor is larger than a 030 and has more torque headroom for the whisk.
**Still open (tracker J2, Action #5 Tùng):** datasheet values (no-load/loaded current, stall torque/current). As soon as they are known,
repeat the table above with the 130 motor line. The bench test (current → torque) remains the evidence.

## Speed control (tracker BOM #8, #9 + firmware)
A 12 mm waterproof momentary button + DRV8833 H-bridge. The DRV8833 needs a PWM signal, so an ATtiny85 runs the
[firmware](../firmware/README.md): 3 levels defined as average motor voltage (2.0 / 2.8 / 3.6 V, capped at the 3.7 V
rating), soft start, low-battery cut-off, auto-off. No rpm is claimed until measured (M2 direction ≈ 9 000 / 11 000 / 13 000 rpm).

## Coupling
ADAPTER_ASSEM: press bore on the motor shaft, journal running in a ball bearing (takes side load from the attachment
instead of the motor bearings), 3 mm hex socket transmits torque positively. CLAMP + PUSH + SPRING give tool-free change
and stop the head falling out. ADAPTER and CLAMP are cheap reprintable wear parts.
**To update for M3 (Tùng):** bore Ø1.5 → **Ø2.0 mm** (130 motor shaft). Bearing: CAD uses **W 61700 (10 × 15 × 3)**, the BOM is priced
for **625Z (5 × 16 × 5)**. Choose one and align the ADAPTER journal diameter with it.

## Power (tracker BOM #2)
**Lishen LR1865SK 18650**: 3.65 V nominal, 4.20 V charge, 2600 mAh (min. 2500), max 5.2 A, ~45 g, ≥ 500 cycles → ≈ 9.5 Wh.
Runtime *estimate*: with 80 % usable energy and a 1–3 W motor load → ≈ 2.5–7.5 h of motor time, while frothing takes ≈ 30 s
per use. Hùng confirms this with the measured motor current (Action #7).
Charging: USB-C (BOM #3) + a protected Li-ion charger module (proposed — tracker J3/J4). Cell in a holder with spring
contacts = replaceable without soldering.

## Material & food contact
Only the attachment heads touch food → stainless steel (bought replacement rods MHMF03/07, BOM #5; steel grade to confirm,
tracker J5). Printed PETG parts (Creality Soleyin Basic PETG) stay above the liquid line; ADAPTER/RETAINER are in the splash
zone and are sealed and cleanable. The housing doesn't need a food-contact rating (Action #10, Nga).

## Splash protection
Openings: drive end (RETAINER + seal), USB-C (rubber plug, tracker #14), button (IP65 12 mm button, tracker #8),
OUTER_CAP (O-ring). Target: no water in the electronics after a tap-rinse of the head (test T5, Action #9).

## Rejected options
| Option | Why rejected |
|---|---|
| Injection-moulded PP housing (still named in `BOM Criteria` #4) | not a FabLab process for the prototype → PETG FDM |
| 030 motor (FF-030PK) | whisking marginal on paper → 130 series |
| Buck converter Mini 560 (tracker #10) | needs ~7–20 V input, can't run from one 3.65 V cell (tracker J11) |
| Glued/welded housing | blocks repair and material separation |
| AAA primary batteries | single-use waste |
