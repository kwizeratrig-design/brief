# Brief — 2-Button USB Macro Pad

Brief is a compact, beginner-friendly USB macro pad built around a Seeed XIAO RP2040. It features two tactile buttons and two indicator LEDs, all on a 40 × 60 mm, 2-layer PCB.

## Features

* 40 × 60 mm PCB
* 2-layer through-hole-friendly design
* Seeed XIAO RP2040 controller
* 2 tactile macro buttons
* 2 red 5 mm indicator LEDs
* 2 × 1 kΩ LED current-limiting resistors
* USB-C through the XIAO RP2040
* Compact custom enclosure
* USB HID keyboard functionality

## Hardware

| Component              | Function              |
| ---------------------- | --------------------- |
| U1 — Seeed XIAO RP2040 | Main controller       |
| SW1                    | Macro Button 1        |
| SW2                    | Macro Button 2        |
| LED1                   | Button 1 indicator    |
| LED2                   | Button 2 indicator    |
| R1                     | LED1 current limiting |
| R2                     | LED2 current limiting |

### GPIO Mapping

| Function |   GPIO | Action      |
| -------- | -----: | ----------- |
| SW1      | GPIO26 | F13         |
| SW2      | GPIO27 | F14         |
| LED1     | GPIO28 | Follows SW1 |
| LED2     | GPIO29 | Follows SW2 |

The buttons are connected between their GPIO pins and GND and use the RP2040's internal pull-up resistors.

## PCB Design

The PCB is a 40 × 60 mm rectangular 2-layer board.

The layout places all seven components on the top side:

* Buttons are positioned at the low-Y end.
* LEDs and resistors are positioned above the buttons.
* The XIAO RP2040 is positioned toward the high-Y end.
* The USB-C connector faces the +Y edge.
* The PCB has no mounting holes.

The enclosure therefore retains the PCB using its edges rather than screws through mounting holes.

PCB thickness is currently assumed to be 1.6 mm and should be confirmed with the PCB manufacturer before fabrication.

## Firmware

The firmware turns the XIAO RP2040 into a USB HID keyboard.

Pressing SW1 sends F13, while pressing SW2 sends F14. The corresponding LED turns on while its button is pressed.

The firmware includes basic button debouncing.

### Build

The firmware can be built using Arduino IDE with:

* Seeed XIAO RP2040 board support
* Adafruit TinyUSB

Select the XIAO RP2040 board and compile `firmware/main.ino`.

## Enclosure

The `enclosure/` directory contains a parametric OpenSCAD enclosure.

Because the PCB export does not provide every mechanical dimension, the enclosure includes adjustable parameters for dimensions such as:

* PCB thickness
* Wall thickness
* USB-C opening
* Internal clearance

The final USB-C opening and XIAO/header clearance should be checked against the PCB's 3D model before fabrication.

## Manufacturing Files

The repository contains the production files exported from Flux:

* Gerber copper layers
* Solder mask
* Silkscreen
* Paste layers
* Board outline
* Excellon drill file
* IPC-D-356 netlist
* Pick-and-place CSV
* Manufacturer-specific BOM files

## Project Structure

```text
Brief/
├── README.md
├── firmware/
│   ├── main.ino
│   └── README.md
├── enclosure/
│   └── brief_enclosure.scad
├── documentation/
│   └── DESIGN.md
├── kwizeraluc-brief.flx
├── Gerber files
├── brief.drl
├── brief.d356
├── pick_and_place.csv
└── BOM files
```

## Design Source

The Flux project is the authoritative source for the PCB schematic and layout.

Flux project:

https://www.flux.ai/kwizeraluc/brief~o2

## Status

**Hardware design:** Complete
**PCB layout:** Complete
**Manufacturing files:** Exported
**Firmware:** Complete
**Enclosure CAD:** Complete
**Documentation:** Complete
**Submission:** Ready
<img width="334" height="405" alt="image" src="https://github.com/user-attachments/assets/7c100600-188a-42e3-a2e3-5f48a68a509f" />
