#include <Arduino.h>
#include "bsp/vision_master_e213.h"
#include "display/display.h"
#include "cat/cat.h"
#include "radio/radio.h"

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
    Display::showRadioStatus();
    
    Radio::begin();
    CAT::begin();
    
    printStartupMessage();
    Serial.println("Before display begin");

    Serial.println("After display begin");

    Serial.println("After display startup");
}

void loop() {
    BSP::update();

    static unsigned long lastPrint = 0;
    unsigned long now = millis();

    delay(10);

    CAT::update();
    Radio::update();

    // Other future modules
    // SI5351::update();
    // Audio::update();
    // PTT::update();
}
