#pragma once

#include <stdint.h>

struct RadioState {
    uint32_t frequency = 28074000;

    bool catConnected = false;
    bool ptt = false;

    const char* mode = "USB";
};

extern RadioState radio;
