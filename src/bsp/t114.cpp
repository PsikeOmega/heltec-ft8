#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

#include "bsp/t114.h"

namespace BSP {

const char* boardName() {
    return BOARD_NAME;
}

const char* displayName() {
    return DISPLAY_NAME;
}

void begin() {
    Serial.println();
    Serial.println("[T114] BSP startup");
    Serial.println(BOARD_NAME);

    beginI2C();

    Serial.println("[T114] I2C ready");
    Serial.println("[T114] BSP ready");
}

void update() {
}

void beginI2C() {
    Wire.begin();
}

void beginSPI() {
    SPI.begin();
}

float readBatteryVoltage() {
    return -1.0f;
}

int readBatteryPercent() {
    return -1;
}

}
