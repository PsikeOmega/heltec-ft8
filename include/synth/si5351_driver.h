#pragma once

#include <stdint.h>

namespace Si5351Driver {

void begin();
void setFrequency(uint32_t frequency);
void enableOutput(bool enabled);

}