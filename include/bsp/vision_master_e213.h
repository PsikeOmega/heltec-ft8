#pragma once

#include <Arduino.h>

namespace BSP {

const char* boardName();
const char* displayName();

void begin();
void update();

float readBatteryVoltage();
int readBatteryPercent();

}
