#pragma once

#include <stdint.h>

enum class RadioMode : uint8_t {
    LSB,
    USB,
    CW,
    FM,
    AM,
    DIGI
};

struct RadioState {
    uint32_t frequency = 28074000;
    uint8_t activeBand = 0;

    RadioMode mode = RadioMode::USB;

    bool catConnected = false;
    bool ptt = false;
    bool dirty = true;

    int rssi = 0;
    uint8_t powerLevel = 5;
};

extern RadioState radio;

// Future expansion:
// - Multiple band presets
// - Multiple SI5351 outputs
// - Relay-selected band-pass filters
// - Multiple CAT profiles
// - GPS-disciplined FT8 timing