#include <Arduino.h>
#include "bsp/vision_master_e213.h"
#include "display/display.h"

void printStartupMessage() {
    Serial.println();
    Serial.println("FT8-Heltec starting...");
    Serial.print("Board: ");
    Serial.println(BSP::boardName());
    Serial.print("Display: ");
    Serial.println(BSP::displayName());
}

void setup() {
    Serial.begin(115200);
    delay(1000);

    BSP::begin();

    Display::begin();
    Display::showStartup();

    printStartupMessage();
}

void loop() {
    BSP::update();

    static unsigned long lastPrint = 0;
    unsigned long now = millis();

    if (now - lastPrint >= 6000) {
        lastPrint = now;
        printStartupMessage();
    }

    delay(10);
}
