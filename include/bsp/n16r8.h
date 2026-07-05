#pragma once

#include <stdint.h>

namespace BSP {

constexpr const char* BOARD_NAME = "ESP32-S3 N16R8";
constexpr const char* DISPLAY_NAME = "Headless";

constexpr uint8_t I2C_SDA_PIN = 8;
constexpr uint8_t I2C_SCL_PIN = 9;

constexpr uint32_t I2C_FREQ = 400000;

constexpr int8_t SPI_SCK  = -1;
constexpr int8_t SPI_MISO = -1;
constexpr int8_t SPI_MOSI = -1;
constexpr int8_t SPI_CS   = -1;

const char* boardName();
const char* displayName();

void begin();
void update();

float readBatteryVoltage();
int readBatteryPercent();

}