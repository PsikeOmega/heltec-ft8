# Heltec FT8 CAT Radio Controller

Experimental ESP32-S3 firmware for using a Heltec Paper 213 as a simple FT8-only radio controller.

Initial goals:

- USB CDC serial CAT control
- truSDX/Kenwood-style CAT command responses
- fixed USB mode
- frequency state tracking
- TX/RX state tracking
- later: e-paper display, battery monitor, Si5351 control, PTT GPIO

Default frequency: 28.074 MHz, 10m FT8.
