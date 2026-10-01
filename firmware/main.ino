#include <Arduino.h>
#include "Adafruit_TinyUSB.h"

// Brief: 2-button USB macro pad
// Button 1 -> GPIO26 -> F13
// Button 2 -> GPIO27 -> F14
// LED 1 -> GPIO28 (active HIGH)
// LED 2 -> GPIO29 (active HIGH)

constexpr uint8_t BTN1 = 26;
constexpr uint8_t BTN2 = 27;
constexpr uint8_t LED1 = 28;
constexpr uint8_t LED2 = 29;

uint8_t const hid_report_desc[] = { TUD_HID_REPORT_DESC_KEYBOARD() };
Adafruit_USBD_HID usb_hid;

bool lastBtn1 = HIGH;
bool lastBtn2 = HIGH;
uint32_t changed1 = 0;
uint32_t changed2 = 0;
constexpr uint32_t DEBOUNCE_MS = 20;

void sendKey(uint8_t keycode, bool pressed) {
  if (!usb_hid.ready()) return;
  uint8_t keycodes[6] = {0};
  if (pressed) keycodes[0] = keycode;
  usb_hid.keyboardReport(0, 0, keycodes);
}

void setup() {
  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  if (!TinyUSBDevice.isInitialized()) TinyUSBDevice.begin(0);
  usb_hid.setPollInterval(2);
  usb_hid.setReportDescriptor(hid_report_desc, sizeof(hid_report_desc));
  usb_hid.begin();
  while (!TinyUSBDevice.mounted()) delay(1);
}

void loop() {
  bool b1 = digitalRead(BTN1);
  bool b2 = digitalRead(BTN2);
  uint32_t now = millis();
  if (b1 != lastBtn1 && now - changed1 >= DEBOUNCE_MS) {
    lastBtn1 = b1; changed1 = now;
    bool pressed = (b1 == LOW);
    digitalWrite(LED1, pressed ? HIGH : LOW);
    if (pressed) sendKey(HID_KEY_F13, true); else usb_hid.keyboardRelease(0);
  }
  if (b2 != lastBtn2 && now - changed2 >= DEBOUNCE_MS) {
    lastBtn2 = b2; changed2 = now;
    bool pressed = (b2 == LOW);
    digitalWrite(LED2, pressed ? HIGH : LOW);
    if (pressed) sendKey(HID_KEY_F14, true); else usb_hid.keyboardRelease(0);
  }
  delay(1);
}
