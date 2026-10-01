# Brief — 2-button USB macro pad

Brief is a compact two-button USB macro pad built around a Seeed XIAO RP2040.

## Hardware
- PCB: 40 x 60 mm, 2-layer
- Controller: Seeed XIAO RP2040
- Inputs: 2 tactile switches
- Indicators: 2 red 5 mm LEDs
- LED resistors: 2 x 1 kΩ
- USB: XIAO RP2040 onboard USB-C
- No PCB mounting holes; enclosure retains the board by its edges
- Assumed PCB thickness: 1.6 mm

## Firmware
SW1 / GPIO26 -> F13; SW2 / GPIO27 -> F14; LED1 / GPIO28 follows SW1; LED2 / GPIO29 follows SW2.

## Repository contents
Gerbers, drill data, IPC-D-356 netlist, pick-and-place CSV, Flux source, manufacturer BOM CSVs, firmware source, parametric OpenSCAD enclosure source, and design documentation.

## Design note
The Flux source remains the authoritative PCB design. Mechanical values not present in the PCB export remain parameterized in the enclosure source and should be checked against the real 3D model before fabrication.

Flux project: https://www.flux.ai/kwizeraluc/brief~o2
