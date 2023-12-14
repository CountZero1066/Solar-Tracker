# Solar-Tracker
Platform for tracking the movement of the sun (or the brightest light source) for optimal solar power production. Solar panel is mounted on a pan-tilt mechanism driven by two SG90s servo motors whose motion is determined by an array of four light dependent resistors separated into four separate quadrants upon a dedicated armature. 
Due to issues arising from the servo motors attempts to rotate beyond the maximum mechanical limits of the mechanisms they drive, a low resistance current shunt resistor was placed into the circuit which allows the code to track when a servo approaches its respective stall current. Thus, informing the code of when a driven servo has reached its maximum rotation angle. 

![IMG_20231205_123534454_HDRa](https://github.com/CountZero1066/Solar-Tracker/assets/32957102/783f5fd7-cd6f-435d-bd8c-7dc0f3bc4173)

# Hardware
- Arduino Nano 
- 2x SG90 servos
- 1x TP4056 based Charging Board
- 1x 3.7v to 5v boost module 
- 4x GL5516 LDR
- 4x 1KΩ
- 1x 1Ω 5W
- 4x 4x9x4mm ball bearings
- 2mm Acrylic sheets

# Pan-Tilt Mechanism

![Image004a](https://github.com/CountZero1066/Solar-Tracker/assets/32957102/09818094-1f00-4eb5-b55e-5bc87b12d1a2)
![IMG_20220728_213036981_HDR](https://github.com/CountZero1066/Solar-Tracker/assets/32957102/54670307-5a4d-4dfd-8e34-c23630759dcb)
![pt mech](https://github.com/CountZero1066/Solar-Tracker/assets/32957102/d5994caa-a266-4c13-996b-a64a0915a2cd)

# LDR Array Platform

![Image005a](https://github.com/CountZero1066/Solar-Tracker/assets/32957102/7ab12f10-84d6-478d-9df5-fb8f7ec99358)
![ldr plat](https://github.com/CountZero1066/Solar-Tracker/assets/32957102/a411fd70-86c7-43bb-b7d6-7b190435c84e)
 
# Circuit Diagram
![SOLAR SCH](https://github.com/CountZero1066/Solar-Tracker/assets/32957102/f5a2000b-0f7a-4606-86dc-618284fff50b)
