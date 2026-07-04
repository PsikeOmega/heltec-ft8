#pragma once

#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

namespace N16R8 {

// Board identity
constexpr const char* BOARD_NAME = "ESP32-S3-N16R8";
constexpr const char* BOARD_FAMILY = "ESP32-S3";
constexpr const char* BOARD_VARIANT = "generic_n16r8_headless";

// Serial
constexpr uint32_t SERIAL_BAUD = 115200;

// I2C
// ESP32-S3 Arduino default/common pins:
// SDA = GPIO8, SCL = GPIO9
constexpr int I2C_SDA = 8;
constexpr int I2C_SCL = 9;
constexpr uint32_t I2C_FREQ = 400000;

// SPI placeholders only.
// Do not rely on these until we assign hardware.
constexpr int SPI_SCK  = -1;
constexpr int SPI_MISO = -1;
constexpr int SPI_MOSI = -1;
constexpr int SPI_CS   = -1;

// Headless for now
constexpr bool HAS_DISPLAY = false;
constexpr bool HAS_EINK = false;
constexpr bool HAS_TFT = false;

// Radio-related expected hardware
constexpr bool HAS_I2C = true;
constexpr bool HAS_SI5351 = true;

// Lifecycle
void begin();
void printBoardInfo();

// I2C
void beginI2C();
TwoWire& i2c();

// SPI placeholder
bool hasSPI();
void beginSPI();
SPIClass& spi();

} // namespace N16R8