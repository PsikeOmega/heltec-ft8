#include "synth/si5351_driver.h"
#include "bsp/vision_master_e213.h"

#include <Arduino.h>
#include <Wire.h>

namespace Si5351Driver {

constexpr uint8_t SI5351_ADDR = 0x60;

static bool detected = false;

static bool probe()
{
    Wire.beginTransmission(SI5351_ADDR);
    return Wire.endTransmission() == 0;
}

void begin()
{
    Serial.println("***** SI5351 DRIVER V2 *****");

    Wire.begin(BSP::I2C_SDA_PIN, BSP::I2C_SCL_PIN);
    delay(100);

    Serial.println("Scanning I2C bus...");

    bool foundAny = false;

    for (uint8_t addr = 1; addr < 127; addr++) {
        Wire.beginTransmission(addr);
        if (Wire.endTransmission() == 0) {
            Serial.print("I2C device found at 0x");
            if (addr < 16) Serial.print('0');
            Serial.println(addr, HEX);
            foundAny = true;
        }
    }

    if (!foundAny) {
        Serial.println("No I2C devices found");
    }

    detected = probe();

    if (detected) {
        Serial.println("Si5351: found at 0x60");
    } else {
        Serial.println("Si5351: NOT found at 0x60");
    }
}

void setFrequency(uint32_t frequency)
{
    Serial.print("Si5351: set frequency ");
    Serial.println(frequency);
}

void enableOutput(bool enabled)
{
    Serial.print("Si5351: output ");
    Serial.println(enabled ? "enabled" : "disabled");
}

}