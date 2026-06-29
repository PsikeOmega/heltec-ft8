#include "display/display.h"
#include <Arduino.h>
#include <heltec-eink-modules.h>

EInkDisplay_VisionMasterE213V1_1 display;

namespace Display {

void begin() {
    display.begin();
}

void showStartup() {
    display.clear();

    display.setCursor(0, 20);
    display.setTextSize(2);
    display.print("FT8-HELTEC");

    display.setCursor(0, 50);
    display.setTextSize(1);
    display.print("Vision Master E213");

    display.setCursor(0, 70);
    display.print("USB serial OK");

    display.setCursor(0, 90);
    display.print("Firmware v0.0.1");

    display.update();
}

}
