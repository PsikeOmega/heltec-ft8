#include <Arduino.h>
#include "bsp/vision_master_e213.h"

void setup() {
    Serial.begin(115200);
    delay(1000);

    BSP::begin();

    Serial.println("FT8-Heltec starting...");
    Serial.print("Board: ");
    Serial.println(BSP::boardName());
    Serial.print("Display: ");
    Serial.println(BSP::displayName());
}

void loop() {
    BSP::update();
    delay(1000);
}
