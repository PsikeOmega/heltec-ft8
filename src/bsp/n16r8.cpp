#include "bsp/n16r8.h"

namespace N16R8 {

static TwoWire* i2cBus = &Wire;
static SPIClass* spiBus = &SPI;

void begin() {
    Serial.begin(SERIAL_BAUD);
    delay(300);

    printBoardInfo();
    beginI2C();

    Serial.println("[N16R8] BSP ready.");
}

void printBoardInfo() {
    Serial.println();
    Serial.println("================================");
    Serial.println("[N16R8] Board startup");

    Serial.print("[N16R8] Board: ");
    Serial.println(BOARD_NAME);

    Serial.print("[N16R8] Family: ");
    Serial.println(BOARD_FAMILY);

    Serial.print("[N16R8] Variant: ");
    Serial.println(BOARD_VARIANT);

    Serial.print("[N16R8] Chip model: ");
    Serial.println(ESP.getChipModel());

    Serial.print("[N16R8] Chip revision: ");
    Serial.println(ESP.getChipRevision());

    Serial.print("[N16R8] CPU MHz: ");
    Serial.println(ESP.getCpuFreqMHz());

    Serial.print("[N16R8] Flash size bytes: ");
    Serial.println(ESP.getFlashChipSize());

    Serial.print("[N16R8] PSRAM size bytes: ");
    Serial.println(ESP.getPsramSize());

    Serial.print("[N16R8] Display enabled: ");
    Serial.println(HAS_DISPLAY ? "yes" : "no");

    Serial.println("================================");
}

void beginI2C() {
    Serial.print("[N16R8] Starting I2C SDA GPIO");
    Serial.print(I2C_SDA);
    Serial.print(", SCL GPIO");
    Serial.println(I2C_SCL);

    i2cBus->begin(I2C_SDA, I2C_SCL, I2C_FREQ);

    Serial.println("[N16R8] I2C ready.");
}

TwoWire& i2c() {
    return *i2cBus;
}

bool hasSPI() {
    return SPI_SCK >= 0 && SPI_MISO >= 0 && SPI_MOSI >= 0;
}

void beginSPI() {
    if (!hasSPI()) {
        Serial.println("[N16R8] SPI pins are not assigned yet. Skipping SPI begin.");
        return;
    }

    spiBus->begin(SPI_SCK, SPI_MISO, SPI_MOSI, SPI_CS);
    Serial.println("[N16R8] SPI ready.");
}

SPIClass& spi() {
    return *spiBus;
}

} // namespace N16R8