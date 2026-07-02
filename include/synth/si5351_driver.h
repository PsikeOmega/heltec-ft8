#pragma once

#include <stdint.h>
#include <Wire.h>
#include "bsp/vision_master_e213.h"

namespace Si5351Driver {

void begin()
{
    Serial.println("Si5351: initializing I2C");

    // Initialize the ESP32 I²C peripheral
    Wire.begin(BSP::I2C_SDA_PIN, BSP::I2C_SCL_PIN);

    detected = probe();

    if (detected) {
        Serial.println("Si5351: found at 0x60");
    } else {
        Serial.println("Si5351: NOT found at 0x60");
    }
}
void setFrequency(uint32_t frequency);
void enableOutput(bool enabled);

}