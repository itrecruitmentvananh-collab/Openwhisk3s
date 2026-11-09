# **Design Rationale**

## **1\. Functional Architecture**

The current product architecture follows the functional flow:

**Supply power → control speed → generate rotation → transmit torque → hold/change attachment → act on milk/food**

Supporting functions include battery charging, user control, secure attachment retention, splash protection, repairability and non-destructive disassembly.

The latest ASSEM\_INNER drawing defines the internal architecture including the motor, battery, housing, attachment, coupling, bearing, USB-C interface, button, microcontroller and motor driver.

## **2\. Main Design Decisions**

| Area | Current Design | Rationale |
| :---- | :---- | :---- |
| **Motor** | 130-series brushed DC motor, 3.7 V | Compact, low cost and suitable for a handheld whisk/frother architecture |
| **Target speed** | 9k / 11k / 13k rpm | Provides three operating levels for light mixing and milk frothing |
| **Battery** | Lishen LR1865SK, 18650, 3.65 V, 2600 mAh | Rechargeable, replaceable and provides adequate discharge capability |
| **Charging interface** | USB Type-C | Common, compact and convenient charging interface |
| **Controller** | ESP32-C3 SuperMini | Provides button input, PWM speed logic and LED/status control in a compact programmable platform |
| **Motor driver** | DRV8833 | Provides the power-driving stage between the controller and brushed DC motor |
| **User control** | 12 mm waterproof momentary push button with LED | Enables simple one-button operation, visual indication and improved splash resistance |
| **Attachment** | Stainless-steel WHISKER | Corrosion-resistant, durable and cleanable for intended food-contact use |
| **Coupling** | ADAPTER\_ASSEM \+ RETAINER \+ spring | Enables secure torque transfer, tool-free attachment change and replaceable wear parts |
| **Bearing** | SKF W 61700, 10 × 15 × 3 mm | Supports radial load, reduces friction and helps reduce attachment wobble |
| **Housing** | OUTER\_SHELL \+ OUTER\_CAP, PETG prototype | Suitable for FDM/FabLab manufacturing, low cost and easy design iteration |
| **Inner mount** | PETG INNER\_MOUNT | Provides accurate positioning and structural support for internal components |
| **Fasteners** | CAD items 11, 12 and 14; 10 pcs total | Supports repeated, non-destructive assembly and disassembly |
| **Splash protection** | RUBBER\_COVER \+ sealed button; additional seals if required | Reduces liquid ingress at critical openings without claiming full waterproofing |
| **Internal wiring** | Direct-soldered wiring | Reduces connector count and simplifies the prototype electrical architecture |
| **Charging/protection electronics** | Integrated into electronics PCB | Reduces separate modules and supports a compact electrical architecture |

## **3\. Control Architecture**

The current control chain is:

**Push button → ESP32-C3 → DRV8833 → 130-series DC motor**

The intended operating sequence is:

**Low → Medium → High → Off**

The three target operating speeds are:

* **Low:** 9,000 rpm  
* **Medium:** 11,000 rpm  
* **High:** 13,000 rpm

These values are current design targets and will be confirmed during prototype testing.

## **4\. Mechanical Architecture**

The latest ASSEM\_INNER drawing defines:

* Item 1 — INNER\_MOUNT  
* Item 2 — MOTOR  
* Items 3–4 — OUTER\_SHELL / OUTER\_CAP  
* Item 5 — ADAPTER\_ASSEM  
* Item 6 — WHISKER  
* Item 7 — RETAINER  
* Item 8 — BALL\_BEARING  
* Item 9 — TYPE\_C  
* Item 10 — BUTTON  
* Items 11, 12, 14 — FASTENERS  
* Item 13 — RUBBER\_COVER  
* Item 15 — MICROCONTROLLER  
* Item 16 — MOTOR\_DRIVER  
* Item 17 — 18650 battery \+ holder.

This architecture supports modular assembly and allows major components to be replaced without permanent joining methods.

## **5\. Material and Food-Contact Concept**

The WHISKER is the primary food-contact component and is designed in stainless steel.

The prototype housing, inner mount and selected coupling components use PETG because it is suitable for FDM manufacturing and rapid prototype iteration.

Printed structural components are intended to remain outside direct food contact where practicable.

## **6\. Repairability and Circularity**

The design avoids permanent glue or welded housing joints where practical.

Major serviceable components include:

**battery, motor, attachment, coupling, bearing, button, controller and motor driver.**

Mechanical fasteners support non-destructive disassembly, while printed wear parts can be reproduced individually rather than replacing the complete device.

This supports the OpenWhisk 3S principles:

**Simple · Sustainable · Serviceable**

## **7\. Preliminary Load Assessment**

A preliminary load-estimation approach was developed using the mixing power relationship:

**P \= Np · ρ · n³ · D⁵**

with torque derived from:

**T \= P / ω**

This approach is retained as an engineering method for evaluating the relative load of the frother and whisk heads.

Previous numerical calculations were based on an earlier motor candidate and are therefore not treated as final evidence for the current 130-series motor.

The final motor assessment will be based on the selected motor data and prototype measurements of loaded speed, current, temperature and functional performance.

&nbsp;

&nbsp;