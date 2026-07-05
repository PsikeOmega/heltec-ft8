#include "bsp/n16r8.h"

namespace BSP {

static TwoWire* i2cBus = &Wire;
static SPIClass* spiBus = &SPI;

const char* boardName() {
    return N16R8::BOARD_NAME;
}

const char* displayName() {
    return "Headless";
}

void begin() {
    Serial.println();
    Serial.println("[N16R8] BSP startup");
    Serial.println(N16R8::BOARD_NAME);

    i2cBus->begin(N16R8::I2C_SDA, N16R8::I2C_SCL, N16R8::I2C_FREQ);

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
    return N16R8::SPI_SCK >= 0 &&
           N16R8::SPI_MISO >= 0 &&
           N16R8::SPI_MOSI >= 0;
}

void beginSPI() {
    if (!hasSPI()) {
        Serial.println("[N16R8] SPI pins are not assigned yet");
        return;
    }

    spiBus->begin(
        N16R8::SPI_SCK,
        N16R8::SPI_MISO,
        N16R8::SPI_MOSI,
        N16R8::SPI_CS
    );
}

SPIClass& spi() {
    return *spiBus;
}

}