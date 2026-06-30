#pragma once

#include <stdint.h>

namespace HAL {

void begin();

void setFrequency(uint32_t frequency);
void setPTT(bool enabled);
void setMode(const char* mode);

uint32_t getFrequency();
bool getPTT();
const char* getMode();

float getBatteryVoltage();
bool isCharging();

}