#pragma once

#include <stdint.h>

namespace Radio {

void begin();
void update();

void setFrequency(uint32_t frequency);
void setMode(const char* mode);
void setPTT(bool enabled);
void setCatConnected(bool connected);

//===============
// frequency getter
//===============

uint32_t getFrequency();
const char* getMode();
bool getPTT();
bool isCatConnected();


}