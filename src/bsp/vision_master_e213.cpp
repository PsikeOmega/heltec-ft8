#include "bsp/vision_master_e213.h"

namespace BSP {

static constexpr const char* BOARD_NAME = "Heltec Vision Master E213";
static constexpr const char* DISPLAY_NAME = "2.13in E-Paper 250x122";

const char* boardName() {
    return BOARD_NAME;
}

const char* displayName() {
    return DISPLAY_NAME;
}

void begin() {
    pinMode(36, OUTPUT);
    digitalWrite(36, LOW);   // Heltec Vext ON is often active-low
    delay(100);
}

void update() {
    // Board-specific periodic tasks will live here.
}

float readBatteryVoltage() {
    // TODO: add Vision Master E213 battery ADC pin and voltage divider math.
    return -1.0f;
}

int readBatteryPercent() {
    // TODO: estimate from Li-ion voltage later.
    return -1;
}

}
