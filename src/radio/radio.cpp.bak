#include "radio/radio.h"
#include "radio/radio_state.h"
#include <Arduino.h>

namespace Radio {

void begin() {
    Serial.println("Radio: initialized");
}

void update() {

}

void setFrequency(uint32_t frequency) {
    radio.frequency = frequency;
    radio.dirty = true;
}

void setMode(const char* mode) {
    radio.mode = mode;
    radio.dirty = true;
}

void setPTT(bool enabled) {
    radio.ptt = enabled;
    radio.dirty = true;
}

void setCatConnected(bool connected) {
    radio.catConnected = connected;
    radio.dirty = true;
}

}