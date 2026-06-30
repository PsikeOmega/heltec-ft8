#include "display/display.h"
#include <Arduino.h>
#include "HT_E0213A367.h"

HT_E0213A367 display(3, 2, 5, 1, 4, 6, -1, 6000000);
// rst, dc, cs, busy, sck, mosi, miso, frequency

namespace {
constexpr int SCREEN_W = 250;
constexpr int SCREEN_H = 122;

constexpr int HEADER_X = 0;
constexpr int HEADER_Y = 0;
constexpr int HEADER_W = SCREEN_W;
constexpr int HEADER_H = 28;

constexpr int LEFT_X = 10;
constexpr int STATUS_BOX_X = 160;
constexpr int STATUS_BOX_Y = 40;
constexpr int STATUS_BOX_W = 75;
constexpr int STATUS_BOX_H = 70;
}

namespace Display {

// display lifecycle 

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

// primitive graphics

void drawText(int x, int y, const char* text) {
    display.drawString(x, y, text);
}

void drawStatusLine(const char* left, const char* right) {
    display.drawString(10, 105, left);
    display.drawString(85, 105, right);
}

void drawLine(int x0, int y0, int x1, int y1) {
    display.drawLine(x0, y0, x1, y1);
}

void drawRect(int x, int y, int w, int h) {
    display.drawRect(x, y, w, h);
}

void fillRect(int x, int y, int w, int h) {
    display.fillRect(x, y, w, h);
}

void drawHorizontalRule(int y) {
    display.drawLine(0, y, STATUS_BOX_X - 5, y);
}

// Widgets

void drawTitle(const char* text) {
    drawText(10, 20, text);
}

void drawTitleBar(const char* title) {
    drawRect(HEADER_X, HEADER_Y, HEADER_W, HEADER_H);
    drawText(LEFT_X, 7, title);
}

void drawLabelValue(int x, int y, const char* label, const char* value) {
    drawText(x, y, label);
    drawText(x + 55, y, value);
}

void drawStatusBox(const char* top, const char* bottom) {
    drawRect(STATUS_BOX_X, STATUS_BOX_Y, STATUS_BOX_W, STATUS_BOX_H);

    drawText(STATUS_BOX_X + 22, STATUS_BOX_Y + 14, top);
    drawText(STATUS_BOX_X + 14, STATUS_BOX_Y + 38, bottom);
}

void drawFrequency(const char* frequency) {
    drawText(10, 40, frequency);
}

void drawModeLine(const char* mode) {
    drawText(10, 68, mode);
}

void drawCatStatus(const char* status) {
    drawLabelValue(10, 88, "CAT:", status);
}

void drawPttStatus(const char* status) {
    drawLabelValue(10, 108, "PTT:", status);
}

void drawAudioStatus(const char* status) {
    drawLabelValue(10, 68, "AUDIO:", status);
}

// screens

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

    drawTitleBar("FT8-HELTEC");

    drawFrequency("28.074.000 MHz");
    drawHorizontalRule(58);

    drawModeLine("USB / FT8");
    drawCatStatus("WAITING");
    drawPttStatus("RX");

    drawStatusBox("RX", "READY");

    refresh();

    Serial.println("Display: done");
}

}