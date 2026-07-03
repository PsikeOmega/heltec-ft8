#include "hal/hal.h"
#include "synth/si5351_driver.h"
#include <Arduino.h>

namespace HAL {

void begin() {
    Serial.println("HAL: initialized");
    Serial.println("HAL: about to call Si5351Driver::begin()");
    Si5351Driver::begin();
    Serial.println("HAL: returned from Si5351Driver::begin()");
}

void setFrequency(uint32_t frequency) {
    Serial.print("HAL: frequency ");
    Serial.println(frequency);

    Si5351Driver::setFrequency(frequency);
}

void setPTT(bool enabled) {
    Serial.print("HAL: PTT ");
    Serial.println(enabled ? "TX" : "RX");

    Si5351Driver::enableOutput(enabled);
}

void setMode(const char* mode) {
    Serial.print("HAL: mode ");
    Serial.println(mode);
}

float getBatteryVoltage() {
    return 0.0f;
}

bool isCharging() {
    return false;
}

int getRSSI() {
    return 0;
}

float getTemperature() {
    return 0.0f;
}

void audioStart() {
    Serial.println("HAL: audio start");
}

void audioStop() {
    Serial.println("HAL: audio stop");
}

}