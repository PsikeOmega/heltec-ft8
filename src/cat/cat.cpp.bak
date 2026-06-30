#include "cat/cat.h"
#include "radio/radio_state.h"
#include <Arduino.h>

namespace CAT {

constexpr int CAT_BUFFER_SIZE = 32;
char buffer[CAT_BUFFER_SIZE];
int index = 0;

void begin() {
    Serial.println("CAT: initialized");
}

void handleCommand(const char* command) {
    Serial.print("CAT RX: ");
    Serial.println(command);

    radio.catConnected = true;
    radio.dirty = true;
}

void update() {
    while (Serial.available() > 0) {
        char c = Serial.read();

        if (c == ';') {
            buffer[index] = '\0';
            handleCommand(buffer);
            index = 0;
        } else if (index < CAT_BUFFER_SIZE - 1) {
            buffer[index++] = c;
        } else {
            index = 0;
        }
    }
}

}