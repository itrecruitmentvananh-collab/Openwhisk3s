# Test plan (M3 → final)

| ID | Test | Method | Pass criterion | Owner | Record |
|---|---|---|---|---|---|
| T1 | Motor under load — frother | 150 ml milk, 30 s, 3 V; measure current (multimeter), speed (phone strobe/tacho app), motor temperature | foam formed, I < 0.45 A, T_motor < 60 °C | Tung | records/motor_frother_*.md |
| T2 | Motor under load — whisk | 2 eggs / 100 ml cream, 2 min | no stall, I < 0.45 A, T_motor < 60 °C | Tung | records/motor_whisk_*.md |
| T3 | Coupling retention & change | 20 attach/detach cycles; pull test with luggage scale; run 2 min at full speed | no self-release, change by hand < 5 s, no visible wear | Tung | records/coupling_*.md |
| T4 | Runtime | full cell, frother load, continuous until cut-off | ≥ 60 min | Hung | records/runtime_*.md |
| T5 | Splash | rinse head 10 s under tap, wipe, open housing, check with tissue paper | no water inside electronics zone | Tung | records/splash_*.md |
| T6 | Cleanability | use with milk, rinse + wash head, inspect coupling for residue | no visible residue on head / socket | Tung | records/cleaning_*.md |
| T7 | Disassembly / reassembly | full teardown and rebuild with PH1 only, 3 repetitions | no broken part, works after rebuild; time recorded | Hung | records/disassembly_*.md |
| T8 | Charging | USB-C 5 V, measure time to full | charges, cuts off at full, no heating > 45 °C | Hung | records/charging_*.md |
