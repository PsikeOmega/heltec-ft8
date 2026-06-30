#include "cat/cat.h"
#include "radio/radio_state.h"
#include <Arduino.h>
#include <string.h>
#include <stdlib.h>
#include "radio/radio.h"

namespace CAT {

//===========
// Private data
//===========

constexpr int CAT_BUFFER_SIZE = 32;
char buffer[CAT_BUFFER_SIZE];
int index = 0;

//====================
// private helper functions
//====================

static void reply(const char* text)
{
    Serial.print(text);
}

static void handleCommand(const char* command) {
    Serial.printf("CAT RX: %s\n", command);

    Radio::setCatConnected(true);

    if (strcmp(command, "FA") == 0 || strcmp(command, "fa") == 0) {
        char response[20];
        snprintf(response, sizeof(response), "FA%011lu;", radio.frequency);
        reply(response);
    }
    else if ((command[0] == 'F' || command[0] == 'f') &&
             (command[1] == 'A' || command[1] == 'a')) {
        uint32_t newFreq = strtoul(command + 2, nullptr, 10);

        if (newFreq > 0) {
            Radio::setFrequency(newFreq);
        }
    }
    else if (strcmp(command, "MD") == 0 || strcmp(command, "md") == 0) {
        reply("MD2;");
    }
    else if (strcmp(command, "TX") == 0 || strcmp(command, "tx") == 0) {
        Radio::setPTT(true);
    }
    else if (strcmp(command, "RX") == 0 || strcmp(command, "rx") == 0) {
        Radio::setPTT(false);
    }
    else if (strcmp(command, "IF") == 0 || strcmp(command, "if") == 0) {
        reply("IF;");
    }
    
}


//===============
// Public functions 
//===============


void begin() {
    Serial.println("CAT: initialized");
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