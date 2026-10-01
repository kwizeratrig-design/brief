# Brief design record

## Board
- 40.0 x 60.0 mm
- 2 copper layers
- rectangular sharp-corner outline
- through-hole component design
- assumed PCB thickness: 1.6 mm pending fabrication confirmation
- no mounting holes; enclosure retains the board by its edges
- all seven project components are on the top side

## Placement
- SW1 (11.25, 7.75) mm
- SW2 (27.25, 7.75) mm
- LED1 (4.77, 18.5) mm
- LED2 (20.77, 18.5) mm
- R1 (6.81, 24.5) mm
- R2 (23.81, 24.5) mm
- U1 XIAO RP2040 (20.0, 50.0) mm
- USB-C faces +Y

## Electrical mapping
- SW1 GPIO26
- SW2 GPIO27
- LED1 GPIO28
- LED2 GPIO29
- buttons are GPIO-to-GND with pull-ups
- LEDs use 1 kΩ current-limiting resistors

## Manufacturing
The repository contains the Flux project, Gerbers, drill data, IPC-D-356 netlist, pick-and-place CSV, and manufacturer-specific BOM exports.

## Enclosure
The OpenSCAD source is parametric because final mechanical dimensions for the USB-C opening and XIAO/header stack should be checked against the exported 3D model before fabrication.
