#pragma once

#include <stdint.h>

namespace BSP {

// Verified by continuity testing and live I2C communication
// External JST I2C connector:
// SDA -> GPIO39
// SCL -> GPIO38
constexpr uint8_t I2C_SDA_PIN = 39;
constexpr uint8_t I2C_SCL_PIN = 38;

const char* boardName();
const char* displayName();

void begin();
void update();

float readBatteryVoltage();
int readBatteryPercent();

}
