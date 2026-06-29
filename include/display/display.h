#pragma once

namespace Display {

void begin();

void clear();
void refresh();

void drawText(int x, int y, const char* text);
void drawTitle(const char* text);
void drawStatusLine(const char* left, const char* right);

void showStartup();

}