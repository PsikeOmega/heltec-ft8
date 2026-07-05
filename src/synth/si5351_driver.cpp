#include "synth/si5351_driver.h"

#if defined(Vision_Master_E213)
#include "bsp/vision_master_e213.h"
#elif defined(ESP32_S3_N16R8)
#include "bsp/n16r8.h"
#elif defined(HELTEC_T114)
#include "bsp/t114.h"
#else
#error "No BSP selected for Si5351 driver"
#endif

#include <Arduino.h>
#include <Wire.h>

namespace Si5351Driver {

constexpr uint8_t SI5351_ADDR = 0x60;
constexpr uint32_t PLL_FREQ  = 900000000UL;

static bool detected = false;
static bool outputEnabled = false;
static uint32_t currentFrequency = 28074000UL;

static void writeReg(uint8_t reg, uint8_t value)
{
    Wire.beginTransmission(SI5351_ADDR);
    Wire.write(reg);
    Wire.write(value);
    Wire.endTransmission();
}

static bool probe()
{
    Wire.beginTransmission(SI5351_ADDR);
    return Wire.endTransmission() == 0;
}

static void writeParams(uint8_t base, uint32_t p1, uint32_t p2, uint32_t p3)
{
    writeReg(base + 0, (p3 >> 8) & 0xFF);
    writeReg(base + 1, p3 & 0xFF);
    writeReg(base + 2, (p1 >> 16) & 0x03);
    writeReg(base + 3, (p1 >> 8) & 0xFF);
    writeReg(base + 4, p1 & 0xFF);
    writeReg(base + 5, ((p3 >> 12) & 0xF0) | ((p2 >> 16) & 0x0F));
    writeReg(base + 6, (p2 >> 8) & 0xFF);
    writeReg(base + 7, p2 & 0xFF);
}

static void setPLL()
{
    uint32_t a = 36;
    uint32_t p1 = 128 * a - 512;

    writeParams(26, p1, 0, 1);
}

static void setCLK0(uint32_t frequency)
{
    uint32_t dividerInteger = PLL_FREQ / frequency;
    uint32_t remainder = PLL_FREQ % frequency;

    uint32_t a = dividerInteger;
    uint32_t c = 1000000UL;
    uint32_t b = ((uint64_t)remainder * c) / frequency;

    uint32_t p1 = 128 * a + ((128 * b) / c) - 512;
    uint32_t p2 = 128 * b - c * ((128 * b) / c);
    uint32_t p3 = c;

    writeParams(42, p1, p2, p3);

    writeReg(16, 0x0F);
    writeReg(177, 0x20);
}

void begin()
{
    Serial.println("***** SI5351 DRIVER V3 RF OUTPUT *****");

    BSP::beginI2C();
    delay(100);

    detected = probe();

    if (detected) {
        Serial.println("Si5351: found at 0x60");

        writeReg(3, 0xFF);

        setPLL();
        setCLK0(currentFrequency);

        if (outputEnabled) {
            enableOutput(true);
        }

        Serial.print("Si5351: CLK0 prepared at ");
        Serial.println(currentFrequency);
    } else {
        Serial.println("Si5351: NOT found at 0x60");
    }
}

void setFrequency(uint32_t frequency)
{
    currentFrequency = frequency;

    Serial.print("Si5351: set CLK0 frequency ");
    Serial.println(frequency);

    if (!detected) {
        Serial.println("Si5351: not detected, frequency not applied");
        return;
    }

    setCLK0(frequency);
}

void enableOutput(bool enabled)
{
    outputEnabled = enabled;

    Serial.print("Si5351: CLK0 output ");
    Serial.println(enabled ? "enabled" : "disabled");

    if (!detected) {
        Serial.println("Si5351: not detected, output state not applied");
        return;
    }

    if (enabled) {
        writeReg(3, 0xFE);
    } else {
        writeReg(3, 0xFF);
    }
}

}
