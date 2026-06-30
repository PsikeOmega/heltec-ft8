#include "hal/hal.h"
#include <Arduino.h>

namespace HAL {

static uint32_t currentFrequency = 28074000;
static bool currentPTT = false;
static const char* currentMode = "USB";

void begin() {
    Serial.println("HAL: initialized");
}

void setFrequency(uint32_t frequency) {
    currentFrequency = frequency;

    Serial.print("HAL: frequency ");
    Serial.println(frequency);
}

void setPTT(bool enabled) {
    currentPTT = enabled;

    Serial.print("HAL: PTT ");
    Serial.println(enabled ? "TX" : "RX");
}

void setMode(const char* mode) {
    currentMode = mode;

    Serial.print("HAL: mode ");
    Serial.println(mode);
}

uint32_t getFrequency() {
    return currentFrequency;
}

bool getPTT() {
    return currentPTT;
}

const char* getMode() {
    return currentMode;
}

float getBatteryVoltage() {
    return 0.0f; // Placeholder until ADC battery read is added
}

bool isCharging() {
    return false; // Placeholder until charge-status pin is known
}

}