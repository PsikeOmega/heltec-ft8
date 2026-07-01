#include "synth/si5351_driver.h"
#include <Arduino.h>

namespace Si5351Driver {

void begin() {
    Serial.println("Si5351: initialized placeholder");
}

void setFrequency(uint32_t frequency) {
    Serial.print("Si5351: set frequency ");
    Serial.println(frequency);
}

void enableOutput(bool enabled) {
    Serial.print("Si5351: output ");
    Serial.println(enabled ? "enabled" : "disabled");
}

}