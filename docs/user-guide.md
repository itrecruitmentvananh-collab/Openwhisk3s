# User guide (OpenWhisk 3S — v0.3)

- **Charge (`CAD #9, #13, #17`):** Open the **USB-C silicone cover (`RUBBER_COVER`, `CAD #13`)** and plug in any standard 5 V USB-C cable (`CAD #9`) to charge the replaceable **Lishen 18650 Li-ion cell (`CAD #17`)**. Close the silicone cover firmly after charging to keep the port splash-proof.
- **Attach / Swap Tool (`CAD #5, #6`):** Push the hex shank of the stainless-steel **`WHISKER` (`CAD #6`)** into the quick-release coupling (`ADAPTER_ASSEM`, `CAD #5`) until it clicks. To release, press the coupling button and pull the attachment out.
- **3-Speed Operation (`CAD #10, #15, #16`):** Always immerse the attachment head into the liquid **before** switching on. Press the **12 mm Illuminated Waterproof Push Button (`CAD #10`)** controlled by the **`ESP32-C3 SuperMini` (`CAD #15`)**:
  - **1st Press:** **Low Speed (`~9,000 RPM`)** — gentle stirring, eggs, light dressings (Button LED stays **ON**).
  - **2nd Press:** **Medium Speed (`~11,000 RPM`)** — whipping cream, light sauces (Button LED stays **ON**).
  - **3rd Press:** **High Speed (`~13,000 RPM`)** — milk foaming (`100–200 ml` milk in `20–40 s`, Button LED stays **ON**).
  - **4th Press (or Hold $\ge 0.8\text{ s}$ from any speed):** **OFF** (Button LED turns **OFF**). Switch off before lifting the head out of the cup to prevent splashing.
- **Low-Battery & Auto-Off Protection:** After 3 minutes of continuous operation, the `ESP32-C3` automatically stops the motor. When the `18650` battery drops below `3.20 V`, the motor stops and the **12 mm button LED blinks rapidly (`4 Hz`)** until recharged via USB-C.
- **Cleaning:** Detach the stainless-steel **`WHISKER` (`CAD #6`)** and wash/rinse it under the tap or in a dishwasher. Ensure the **USB-C silicone cover (`CAD #13`)** is closed and wipe the 3D-printed PETG body (`OUTER_SHELL` `CAD #3`, `OUTER_CAP` `CAD #4`) with a damp cloth — **do not immerse the motorized body in water**.
- **Safety:** Keep fingers, hair, and loose clothing away from rotating attachments; intended for light liquids and milk foaming only (not heavy dough); do not use a damaged Li-ion cell.
