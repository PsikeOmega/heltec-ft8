#include "display/display.h"
#include <Arduino.h>
#include <heltec-eink-modules.h>

EInkDisplay_VisionMasterE213 display;

namespace Display {

void begin() {
    // The heltec-eink-modules library initializes all-in-one Vision Master
    // displays automatically. Calling display.begin() appears to hang here.

}

void showStartup() {
    Serial.println("Display: clear");
    display.clear();

    Serial.println("Display: text 1");
    display.setCursor(0, 20);
    display.setTextSize(2);
    display.print("FT8-HELTEC");

    Serial.println("Display: text 2");
    display.setCursor(0, 50);
    display.setTextSize(1);
    display.print("Vision Master E213");

    Serial.println("Display: text 3");
    display.setCursor(0, 70);
    display.print("USB serial OK");

    Serial.println("Display: text 4");
    display.setCursor(0, 90);
    display.print("Firmware v0.0.1");

    Serial.println("Display: update");
    display.update();

    Serial.println("Display: done");
}

}
