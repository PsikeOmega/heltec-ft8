#pragma once

#include <stdint.h>

namespace HAL {

void begin();

void setFrequency(uint32_t frequency);
void setPTT(bool enabled);
void setMode(const char* mode);

float getBatteryVoltage();
bool isCharging();

int getRSSI();
float getTemperature();

void audioStart();
void audioStop();

}