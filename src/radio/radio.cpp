#include "radio/radio.h"
#include "radio/radio_state.h"
#include "hal/hal.h"
#include "display/display.h"

#include <Arduino.h>

namespace Radio {

// Initialize the radio state manager.
// Hardware initialization lives in HAL; this layer owns operator-facing state.
void begin() {
    Serial.println("Radio: initialized");
    radio.dirty = true;
}

// Central radio update point.
// If anything changed, refresh dependent systems here.
void update() {
    if (!radio.dirty) {
        return;
    }

    Display::showRadioStatus();

    radio.dirty = false;
}

// Set operating frequency in Hz.
// Radio owns the state; HAL applies it to hardware.
void setFrequency(uint32_t frequency) {
    radio.frequency = frequency;
    HAL::setFrequency(frequency);
    radio.dirty = true;
}

// Set operating mode.
// CAT/UI should translate commands into RadioMode before calling this.
void setMode(RadioMode mode) {
    radio.mode = mode;
    radio.dirty = true;
}

// Set push-to-talk state.
// Radio owns TX/RX state; HAL applies the hardware change.
void setPTT(bool enabled) {
    radio.ptt = enabled;
    HAL::setPTT(enabled);
    radio.dirty = true;
}

// Track CAT connection state for display/status.
void setCatConnected(bool connected) {
    radio.catConnected = connected;
    radio.dirty = true;
}

// Current frequency in Hz.
uint32_t getFrequency() {
    return radio.frequency;
}

// Current operating mode.
RadioMode getMode() {
    return radio.mode;
}

// True when transmitting.
bool getPTT() {
    return radio.ptt;
}

// True when CAT/USB control is connected.
bool isCatConnected() {
    return radio.catConnected;
}

const char* modeToString(RadioMode mode) {
    switch (mode) {
        case RadioMode::LSB:  return "LSB";
        case RadioMode::USB:  return "USB";
        case RadioMode::CW:   return "CW";
        case RadioMode::FM:   return "FM";
        case RadioMode::AM:   return "AM";
        case RadioMode::DIGI: return "DIGI";
        default:              return "UNK";
    }
}

}