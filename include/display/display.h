#pragma once

namespace Display {

void begin();

void clear();
void refresh();

void drawText(int x, int y, const char* text);
void drawTitle(const char* text);
void drawStatusLine(const char* left, const char* right);

void showStartup();

void showRadioStatus();

void drawTitleBar(const char* title);

void drawLine(int x0, int y0, int x1, int y1);
void drawRect(int x, int y, int w, int h);
void fillRect(int x, int y, int w, int h);
void drawHorizontalRule(int y);

void drawLabelValue(int x, int y, const char* label, const char* value);
void drawStatusBox(const char* top, const char* bottom);

}