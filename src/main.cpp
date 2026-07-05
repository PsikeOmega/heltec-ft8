#include <Arduino.h>

#if defined(Vision_Master_E213)
#include "bsp/vision_master_e213.h"
#elif defined(ESP32_S3_N16R8)
#include "bsp/n16r8.h"
#elif defined(HELTEC_T114)
#include "bsp/t114.h"
#else
#error "No BSP selected"
#endif

#include "display/display.h"
#include "cat/cat.h"
#include "radio/radio.h"
#include "radio/radio_state.h"
#include "hal/hal.h"

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
    delay(8000); //milliseconds before serial begin
    Serial.println("MAIN: setup entered");

    BSP::begin();
    HAL::begin();
    
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
    if (radio.dirty) {
    Display::showRadioStatus();
    radio.dirty = false;
}

    // Other future modules
    // SI5351::update();
    // Audio::update();
    // PTT::update();
}
