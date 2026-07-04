#pragma once

#include "radio/radio_state.h"

#include <stdint.h>

namespace Radio {

void begin();
void update();

void setFrequency(uint32_t frequency);
void setMode(RadioMode mode);
RadioMode getMode();
void setPTT(bool enabled);
void setCatConnected(bool connected);

//===============
// frequency getter
//===============

uint32_t getFrequency();
bool getPTT();
bool isCatConnected();

const char* modeToString(RadioMode mode);

}