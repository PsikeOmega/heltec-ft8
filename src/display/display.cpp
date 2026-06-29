#include "display/display.h"
#include <Arduino.h>
#include "HT_E0213A367.h"

HT_E0213A367 display(3, 2, 5, 1, 4, 6, -1, 6000000);
// rst, dc, cs, busy, sck, mosi, miso, frequency

namespace Display {

void begin() {
    Serial.println("Display: power");

    pinMode(18, OUTPUT);
    digitalWrite(18, HIGH);

    pinMode(46, OUTPUT);
    digitalWrite(46, HIGH);

    delay(100);

    Serial.println("Display: init");
    display.init();

    Serial.println("Display: ready");
}

void clear() {
    display.clear();
}

void refresh() {
    display.update(COLOR_BUFFER);
    display.display();
}

void drawText(int x, int y, const char* text) {
    display.drawString(x, y, text);
}

void drawTitle(const char* text) {
    display.drawString(10, 20, text);
}

void drawStatusLine(const char* left, const char* right) {
    display.drawString(10, 105, left);
    display.drawString(85, 105, right);
}

void showStartup() {
    Serial.println("Display: startup screen");

    clear();

    drawTitle("FT8-HELTEC");
    drawText(10, 45, "Vision Master E213");
    drawText(10, 65, "ESP32-S3 / USB OK");
    drawText(10, 85, "Display OK");

    refresh();

    Serial.println("Display: done");
}

void showRadioStatus() {
    Serial.println("Display: radio status");

    clear();

    drawTitle("FT8-HELTEC");

    drawText(10, 45, "28.074.000 MHz");
    drawText(10, 65, "10m USB");

    drawText(10, 90, "CAT: WAITING");
    drawText(10, 110, "PTT: RX");

    refresh();

    Serial.println("Display: done");
}

}