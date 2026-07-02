#include "synth/si5351_driver.h"

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
    Serial.println("Si5351: initializing I2C");

    Wire.begin();

    detected = probe();

    if (detected) {
        Serial.println("Si5351: found at 0x60");
    }
    else {
        Serial.println("Si5351: NOT found at 0x60");
    }
}

void setFrequency(uint32_t frequency)
{
    Serial.print("Si5351: set frequency ");
    Serial.println(frequency);

    if (!detected) {
        Serial.println("Si5351: skipped, chip not detected");
        return;
    }

    // Real frequency programming comes next.
}

void enableOutput(bool enabled)
{
    Serial.print("Si5351: output ");
    Serial.println(enabled ? "enabled" : "disabled");

    if (!detected) {
        Serial.println("Si5351: skipped, chip not detected");
        return;
    }

    // Real output enable/disable comes next.
}

}