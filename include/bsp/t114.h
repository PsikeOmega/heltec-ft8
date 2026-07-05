#pragma once

#include <stdint.h>

namespace BSP {

constexpr const char* BOARD_NAME = "Heltec Mesh Node T114";
constexpr const char* DISPLAY_NAME = "OLED";

// T114 I2C pins come from the nRF52 board variant.
// nRF52 uses Wire.begin() with no explicit SDA/SCL arguments.
constexpr uint8_t I2C_SDA_PIN = 0;
constexpr uint8_t I2C_SCL_PIN = 0;

const char* boardName();
const char* displayName();

void begin();
void update();

void beginI2C();
void beginSPI();

float readBatteryVoltage();
int readBatteryPercent();

}
