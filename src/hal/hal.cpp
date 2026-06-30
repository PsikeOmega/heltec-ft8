#include "hal/hal.h"
#include <Arduino.h>

namespace HAL {

void begin() {
    Serial.println("HAL: initialized");
}

void setFrequency(uint32_t frequency) {
    Serial.print("HAL: frequency ");
    Serial.println(frequency);
}

void setPTT(bool enabled) {
    Serial.print("HAL: PTT ");
    Serial.println(enabled ? "TX" : "RX");
}

void setMode(const char* mode) {
    Serial.print("HAL: mode ");
    Serial.println(mode);
}

}