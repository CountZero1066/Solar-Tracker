# Solar-Tracker
Platform for tracking the movement of the sun (or the brightest light source) for optimal solar power production. Solar panel is mounted on a pan-tilt mechanism driven by two SG90s servo motors whose motion is determined by an array of four light dependent resistors separated into four separate quadrants upon a dedicated armature. 
Due to issues arising from the servo motors attempts to rotate beyond the maximum mechanical limits of the mechanisms they drive, a low resistance current shunt resistor was placed into the circuit which allows the code to track when a servo approaches its respective stall current. Thus, informing the code of when a driven servo has reached its maximum rotation angle. 

![IMG_20231205_123534454_HDRa](https://github.com/CountZero1066/Solar-Tracker/assets/32957102/783f5fd7-cd6f-435d-bd8c-7dc0f3bc4173)

# Hardware
- Arduino Nano
- 2.5W 5V/500mAh Solar Panel (130mm x 150mm)
- 2x SG90 servos
- 1x TP4056 based Charging Board
- 1x 3.7v to 5v boost module
- 1x 18650 cell
- 4x GL5516 LDR
- 4x 1KΩ
- 1x 1Ω 5W
- 4x 4x9x4mm ball bearings
- 2mm Acrylic sheets
- Miscellaneous: M2 screws, M2 standoffs, washers, circlips

# Pan-Tilt Mechanism

![Image004a](https://github.com/CountZero1066/Solar-Tracker/assets/32957102/09818094-1f00-4eb5-b55e-5bc87b12d1a2)
![IMG_20220728_213036981_HDR](https://github.com/CountZero1066/Solar-Tracker/assets/32957102/54670307-5a4d-4dfd-8e34-c23630759dcb)
![pt mech](https://github.com/CountZero1066/Solar-Tracker/assets/32957102/d5994caa-a266-4c13-996b-a64a0915a2cd)

# LDR Array Platform
The four GL5516 LDRs mounted on the 'LDR array platform' vary in resistance according to the amount of light falling on each quadrant of the array platform, this generates a voltage drop that is measured by the Arduino Nano's analog pins. This information is used by the Arduino to determine how to move the SG90 servos in order to equalize the resistance of all four LDRs. 

![Image005a](https://github.com/CountZero1066/Solar-Tracker/assets/32957102/7ab12f10-84d6-478d-9df5-fb8f7ec99358)
![ldr plat](https://github.com/CountZero1066/Solar-Tracker/assets/32957102/a411fd70-86c7-43bb-b7d6-7b190435c84e)
 
# Circuit Diagram
U1 is a 5W 1Ω shunt resistor used to measure (by analog pin A0) the relative current draw across the SG90 servos, useful for determining if the SG90 has stalled i.e. has reached the mechanical limits of the pan-tilt mechanism. Ideally, U1 should be a single resistor, however the actual physical circuit uses 5x 1W resistors wired together in parallel.
Pin header J2 connects to the four GL5516 LDRs via Dupont cables and the voltage drop is measured by the analog pins A1-A4. 

![SOLAR SCH](https://github.com/CountZero1066/Solar-Tracker/assets/32957102/f5a2000b-0f7a-4606-86dc-618284fff50b)
![IMG_20221007_182230115](https://github.com/CountZero1066/Solar-Tracker/assets/32957102/71246b4d-8da9-4be8-92cf-b52c093724d1)

