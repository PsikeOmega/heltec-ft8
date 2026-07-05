#pragma once

#include <stdint.h>

namespace BSP {

constexpr const char* BOARD_NAME = "Heltec Mesh Node T114";
constexpr const char* DISPLAY_NAME = "OLED";

// T114 I2C pins should come from the nRF52 board variant.
// Keep these here for shared code, but nRF52 should use Wire.begin().
constexpr uint8_t I2C_SDA_PIN = 0;
constexpr uint8_t I2C_SCL_PIN = 0;

const char* boardName();
const char* displayName();

void begin();
void update();

float readBatteryVoltage();
int readBatteryPercent();

}