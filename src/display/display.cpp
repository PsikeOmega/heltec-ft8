#include "display/display.h"
#include <Arduino.h>
#include "HT_lCMEN2R13EFC1.h"

HT_ICMEN2R13EFC1 display(6, 5, 4, 7, 3, 2, -1, 6000000);

namespace Display {

void begin() {
    Serial.println("Display: official Heltec driver selected");
}

void showStartup() {
    Serial.println("Display: init");
    display.init();

    Serial.println("Display: clear");
    display.clear();

    Serial.println("Display: draw");
    display.display();

    Serial.println("Display: done");
}

}