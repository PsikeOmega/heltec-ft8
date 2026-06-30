#include "radio/radio.h"
#include "radio/radio_state.h"
#include <Arduino.h>
#include "hal/hal.h"

namespace Radio {

void begin() {
    Serial.println("Radio: initialized");
}

void update() {

}

//================
// frequency setters
//================

void setFrequency(uint32_t frequency) {
    radio.frequency = frequency;
    HAL::setFrequency(frequency);
    radio.dirty = true;
}

void setMode(const char* mode) {
    radio.mode = mode;
    HAL::setMode(mode);
    radio.dirty = true;
}

void setPTT(bool enabled) {
    radio.ptt = enabled;
    HAL::setPTT(enabled);
    radio.dirty = true;
}




void setCatConnected(bool connected) {
    radio.catConnected = connected;
    radio.dirty = true;
}

//===============
// frequency getter 
//===============

uint32_t getFrequency() {
    return HAL::getFrequency();
}

const char* getMode() {
    return HAL::getMode();
}

bool getPTT() {
    return HAL::getPTT();
}

bool isCatConnected() {
    return radio.catConnected;
}

}