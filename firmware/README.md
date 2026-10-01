# Brief firmware

The firmware turns the XIAO RP2040 into a two-key USB HID macro pad.

- SW1: GPIO26 -> F13
- SW2: GPIO27 -> F14
- LED1: GPIO28, follows SW1
- LED2: GPIO29, follows SW2

Buttons use the PCB GPIO-to-GND wiring and internal pull-ups. LEDs are driven through the PCB 1 kΩ current-limiting resistors.

Build with Arduino IDE, XIAO RP2040 board support, and Adafruit TinyUSB. Select the XIAO RP2040 and compile main.ino.
