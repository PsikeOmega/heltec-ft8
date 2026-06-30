#include "cat/cat.h"
#include "radio/radio_state.h"
#include <Arduino.h>
#include <string.h>
#include <stdlib.h>

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

    if (strcmp(command, "FA") == 0 || strcmp(command, "fa") == 0) {
        char reply[20];
        snprintf(reply, sizeof(reply), "FA%011lu;", radio.frequency);
        Serial.print(reply);
    }
    else if ((command[0] == 'F' || command[0] == 'f') &&
             (command[1] == 'A' || command[1] == 'a')) {
        uint32_t newFreq = strtoul(command + 2, nullptr, 10);

        if (newFreq > 0) {
            radio.frequency = newFreq;
            radio.dirty = true;
        }
    }
    else if (strcmp(command, "MD") == 0 || strcmp(command, "md") == 0) {
        Serial.print("MD2;");
    }
    else if (strcmp(command, "TX") == 0 || strcmp(command, "tx") == 0) {
        radio.ptt = true;
        radio.dirty = true;
    }
    else if (strcmp(command, "RX") == 0 || strcmp(command, "rx") == 0) {
        radio.ptt = false;
        radio.dirty = true;
    }
    else if (strcmp(command, "IF") == 0 || strcmp(command, "if") == 0) {
        Serial.print("IF;");
    }

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