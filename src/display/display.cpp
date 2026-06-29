#include "display/display.h"
#include <Arduino.h>
#include "HT_E0213A367.h"

HT_E0213A367 display(3, 2, 5, 1, 4, 6, -1, 6000000);
// rst, dc, cs, busy, sck, mosi, miso, frequency

namespace Display {

void begin() {
    Serial.println("Display: power");

    // Enable display power
    pinMode(18, OUTPUT);
    digitalWrite(18, HIGH);

    // Enable ADC control
    pinMode(46, OUTPUT);
    digitalWrite(46, HIGH);

    delay(100);

    Serial.println("Display: init");
    display.init();

    Serial.println("Display: ready");
}

void showStartup() {
    Serial.println("Display: clear");
    display.clear();

    Serial.println("Display: text");

    display.setFont(ArialMT_Plain_16);
    display.drawString(0, 0, "FT8-HELTEC");

    display.setFont(ArialMT_Plain_10);
    display.drawString(0, 24, "Heltec Vision Master E213");
    display.drawString(0, 40, "ESP32-S3");
    display.drawString(0, 56, "USB serial OK");
    display.drawString(0, 72, "Display OK");
    display.drawString(0, 96, "v0.0.1 bringup");

    Serial.println("Display: draw");
    display.display();

    Serial.println("Display: done");
}

}