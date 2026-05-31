# Water-Dispenser

A custom-built smart drink dispenser that mixes water and blackcurrant concentrate on demand using two independently controlled pumps. The system is powered by an ESP32 and features adjustable mixing ratios, WiFi connectivity, cooling support, and a custom PCB.

## Overview

The dispenser stores water and blackcurrant concentrate in separate containers. When the dispense button is pressed, both pumps activate and mix the liquids through a shared output nozzle. The ESP32 controls the pump speeds, allowing the drink strength to be adjusted either through a potentiometer or a future web interface.

## Features

- Adjustable water-to-syrup ratio
- ESP32-based control system
- Custom PCB designed in KiCad
- Food-safe tubing and liquid path
- Physical dispense button
- Potentiometer for ratio adjustment
- Status LED

---

## Hardware

### Fluid System

- 2L water bottle
- 2L blackcurrant concentrate bottle
- 2× 12V peristaltic pumps
- Food-safe silicone tubing
- Barbed Y-connector
- Single output nozzle

### Electronics

- ESP32-WROOM
- 12V DC barrel jack
- LM2596 buck converter
- 3.3V regulator
- 2× Logic-level MOSFETs
- 2× Flyback diodes
- 2× 100Ω gate resistors
- 2× 10kΩ pull-down resistors
- 10kΩ potentiometer
- Pushbutton
- Status LED
- 220Ω LED resistor
- Decoupling and smoothing capacitors

---

## Electronics Design

The schematic is centered around an ESP32-WROOM module.

Power enters through a 12V barrel jack and is split into two sections. The pumps run directly from the 12V rail, while an LM2596 buck converter steps the voltage down before a 3.3V regulator supplies power to the ESP32.

Each pump is controlled by a dedicated MOSFET driver circuit. A 100Ω gate resistor is used between the ESP32 and MOSFET gate, while a 10kΩ pull-down resistor ensures the pumps remain off during boot. Flyback diodes protect the electronics from motor-induced voltage spikes.

A pushbutton is connected using the ESP32's internal pull-up resistor, while a 10k potentiometer provides live adjustment of the syrup ratio. A status LED indicates operating state.

All grounds are shared throughout the system, and capacitors are used for voltage smoothing and noise reduction.

---

## PCB Design

The PCB was designed in KiCad.

### Design Process

1. Created the schematic and assigned footprints.
2. Performed the initial PCB layout.
3. Routed all traces.
4. Ran DRC checks and fixed any issues.
5. Ensured nothing was placed inside the ESP32 keep-out zone.
6. Exported the PCB as a STEP file.
7. Imported the PCB into Fusion 360.

---

## Enclosure Design

The enclosure was designed around the PCB and bottle mounting system.

### Design Changes

- Moved the LED, potentiometer, and button to the opposite side for better usability and appearance.
- Added a cutout for the barrel jack.
- Flipped the PCB orientation after discovering the bottle mounts blocked access to the power connector.
- Designed a dedicated PCB housing.
- Created a removable rear panel.
- Added mounting points for both pumps.
- Designed bottle mounts that allow the dispenser assembly to sit above the bottles.
- Added a central passage for routing outlet tubing.
- Planned to reverse one pump orientation to simplify tube routing.

---

## Current Status

### Completed

- [x] Project planning
- [x] Schematic design
- [x] PCB design and routing
- [x] DRC validation
- [x] STEP export
- [x] Fusion 360 integration
- [x] Enclosure design
- [x] Pump mounts
- [x] Bottle mounting system
- [x] Rear access panel

### Future Work

- [ ] Manufacture PCB
- [ ] Assemble electronics
- [ ] 3D print enclosure components
- [ ] Install tubing and pumps
- [ ] Develop firmware
- [ ] Create WiFi web interface
- [ ] Calibrate dispensing ratios
- [ ] Test cooling performance
- [ ] Improve bottle mount stability

---

## Project Goals

The aim of this project is to create a compact, professional-looking drink dispenser that can accurately mix and dispense flavoured drinks while serving as a complete electronics, PCB design, firmware, and mechanical CAD project.

## Gallery

### PCB

<img width="527" height="526" alt="Screenshot 2026-05-22 135122" src="https://github.com/user-attachments/assets/64c1f4f8-7c44-429c-a267-11b5a599167e" />


### CAD

<img width="958" height="692" alt="Screenshot 2026-05-22 205002" src="https://github.com/user-attachments/assets/403b5f7e-53fd-4681-a4f8-519dc9a29d4a" />


