#pragma once

#include <stdint.h>

struct RadioState {
    uint32_t frequency = 28074000;
    // Future: select among SI5351 outputs/band presets
    uint8_t activeBand = 0;
    bool catConnected = false;
    bool ptt = false;

    const char* mode = "USB";
};

bool dirty = true;

extern RadioState radio;

// Future expansion:
// - Multiple band presets
// - Multiple SI5351 outputs
// - Relay-selected band-pass filters
// - Multiple CAT profiles
// - GPS-disciplined FT8 timing