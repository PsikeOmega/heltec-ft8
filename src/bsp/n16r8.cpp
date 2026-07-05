#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

#include "bsp/n16r8.h"

namespace BSP {

static TwoWire* i2cBus = &Wire;
static SPIClass* spiBus = &SPI;

const char* boardName() {
    return BOARD_NAME;
}

const char* displayName() {
    return DISPLAY_NAME;
}

void begin() {
    Serial.println();
    Serial.println("[N16R8] BSP startup");
    Serial.println(BOARD_NAME);

    i2cBus->begin(I2C_SDA_PIN, I2C_SCL_PIN, I2C_FREQ);

    Serial.println("[N16R8] I2C ready");
    Serial.println("[N16R8] BSP ready");
}

void update() {
}

float readBatteryVoltage() {
    return -1.0f;
}

int readBatteryPercent() {
    return -1;
}

TwoWire& i2c() {
    return *i2cBus;
}

bool hasSPI() {
    return SPI_SCK >= 0 &&
           SPI_MISO >= 0 &&
           SPI_MOSI >= 0;
}

void beginSPI() {
    if (!hasSPI()) {
        Serial.println("[N16R8] SPI disabled");
        return;
    }

    spiBus->begin(SPI_SCK, SPI_MISO, SPI_MOSI, SPI_CS);
}

SPIClass& spi() {
    return *spiBus;
}

}