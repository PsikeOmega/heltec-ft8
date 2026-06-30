#pragma once

#include <stdint.h>

    struct RadioState {
        uint32_t frequency = 28074000;
        uint8_t activeBand = 0;

        bool catConnected = false;
        bool ptt = false;
        bool dirty = true;

        const char* mode = "USB";
};
// Future: select among SI5351 outputs/band presets
extern RadioState radio;

// Future expansion:
// - Multiple band presets
// - Multiple SI5351 outputs
// - Relay-selected band-pass filters
// - Multiple CAT profiles
// - GPS-disciplined FT8 timing