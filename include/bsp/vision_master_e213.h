#pragma once

#include <Arduino.h>

namespace BSP {

constexpr uint8_t I2C_SDA_PIN = 45;
constexpr uint8_t I2C_SCL_PIN = 42;

const char* boardName();
const char* displayName();

void begin();
void update();

float readBatteryVoltage();
int readBatteryPercent();

}
