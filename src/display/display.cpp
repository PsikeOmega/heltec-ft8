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

    display.drawString(10, 20, "FT8-HELTEC");
    display.drawString(10, 45, "Vision Master E213");
    display.drawString(10, 65, "ESP32-S3 / USB OK");
    display.drawString(10, 85, "Display OK");

    Serial.println("Display: draw");
    display.display();

    Serial.println("Display: done");
}

}