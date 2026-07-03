#pragma once

#include <stdint.h>

namespace BSP {

constexpr uint8_t I2C_SDA_PIN = 42;
constexpr uint8_t I2C_SCL_PIN = 45;

const char* boardName();
const char* displayName();

void begin();
void update();

float readBatteryVoltage();
int readBatteryPercent();

}
