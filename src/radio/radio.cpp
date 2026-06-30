#include "radio/radio.h"
#include "radio/radio_state.h"
#include <Arduino.h>

namespace Radio {

void begin() {
    Serial.println("Radio: initialized");
}

void update() {
    static uint32_t lastUpdate = 0;

    if (millis() - lastUpdate > 1000) {
        lastUpdate = millis();

        radio.catConnected = !radio.catConnected;
        radio.dirty = true;
    }
}

}