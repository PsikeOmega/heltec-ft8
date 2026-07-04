#include "cat/cat.h"
#include "radio/radio.h"

#include <Arduino.h>
#include <string.h>
#include <stdlib.h>

namespace CAT {

//===========
// Private data
//===========

constexpr int CAT_BUFFER_SIZE = 32;
char buffer[CAT_BUFFER_SIZE];
int index = 0;

//====================
// Private helper functions
//====================

static void reply(const char* text)
{
    Serial.print(text);
}

static bool isCommand(const char* command, const char* target)
{
    return strcmp(command, target) == 0;
}

static bool startsWith(const char* command, const char* prefix)
{
    return strncmp(command, prefix, strlen(prefix)) == 0;
}

//====================
// FA - VFO A Frequency
//====================

static void handleFA(const char* command)
{
    if (strlen(command) == 2) {
        char response[20];
        snprintf(response, sizeof(response),
                 "FA%011lu;",
                 Radio::getFrequency());

        reply(response);
        return;
    }

    uint32_t newFreq = strtoul(command + 2, nullptr, 10);

    if (newFreq > 0) {
        Radio::setFrequency(newFreq);
    }
}

//====================
// FB - VFO B Frequency
// For now, mirror VFO A.
//====================

static void handleFB(const char* command)
{
    if (strlen(command) == 2) {
        char response[20];
        snprintf(response, sizeof(response),
                 "FB%011lu;",
                 Radio::getFrequency());

        reply(response);
        return;
    }

    uint32_t newFreq = strtoul(command + 2, nullptr, 10);

    if (newFreq > 0) {
        Radio::setFrequency(newFreq);
    }
}

//====================
// MD - Operating Mode
//====================

static void handleMD(const char* command)
{
    if (strlen(command) == 2) {
        switch (Radio::getMode()) {
            case RadioMode::LSB:  reply("MD1;"); break;
            case RadioMode::USB:  reply("MD2;"); break;
            case RadioMode::CW:   reply("MD3;"); break;
            case RadioMode::FM:   reply("MD4;"); break;
            case RadioMode::AM:   reply("MD5;"); break;
            case RadioMode::DIGI: reply("MD9;"); break;
            default:              reply("MD2;"); break;
        }
        return;
    }

    if (isCommand(command, "MD1")) {
        Radio::setMode(RadioMode::LSB);
    }
    else if (isCommand(command, "MD2")) {
        Radio::setMode(RadioMode::USB);
    }
    else if (isCommand(command, "MD3")) {
        Radio::setMode(RadioMode::CW);
    }
    else if (isCommand(command, "MD4")) {
        Radio::setMode(RadioMode::FM);
    }
    else if (isCommand(command, "MD5")) {
        Radio::setMode(RadioMode::AM);
    }
    else if (isCommand(command, "MD9")) {
        Radio::setMode(RadioMode::DIGI);
    }
}

//====================
// TX - Enter Transmit
//====================

static void handleTX()
{
    Radio::setPTT(true);
}

//====================
// RX - Return to Receive
//====================

static void handleRX()
{
    Radio::setPTT(false);
}

//====================
// IF - Transceiver Status
//====================

static void handleIF()
{
    char response[40];

    snprintf(response, sizeof(response),
             "IF%011lu00000000002000000%c0;",
             Radio::getFrequency(),
             Radio::getPTT() ? '1' : '0');

    reply(response);
}

//====================
// ID - Radio ID
//====================

static void handleID()
{
    reply("ID020;");
}

//====================
// OF - Offset
//====================

static void handleOF()
{
    reply("OF000000000;");
}

//===================
// AI - Auto Information 
//===================

static void handleAI(const char* command)
{
    if (strlen(command) == 2) {
        reply("AI0;");
        return;
    }
    // Accept AI0 / AI1 / AI2 but don't do anything yet.
}

//================
// PS - Power Status 
//================

static void handlePS()
{
    reply("PS1;");
}

//============
// AG - AF Gain
//============

static void handleAG()
{
    reply("AG000;");
}

//============
// RG - RF Gain
//============

static void handleRG()
{
    reply("RG000;");
}

//=================
// PC - Power Control 
//=================

static void handlePC()
{
    reply("PC005;");
}

//====================
// Command dispatcher
//====================

static void handleCommand(const char* command)
{
    Serial.printf("CAT RX: %s\n", command);

    Radio::setCatConnected(true);

    if (startsWith(command, "FA")) {
        handleFA(command);
    }
    else if (startsWith(command, "FB")) {
        handleFB(command);
    }
    else if (startsWith(command, "MD")) {
        handleMD(command);
    }
    else if (isCommand(command, "TX")) {
        handleTX();
    }
    else if (isCommand(command, "RX")) {
        handleRX();
    }
    else if (isCommand(command, "IF")) {
        handleIF();
    }
    else if (isCommand(command, "ID")) {
        handleID();
    }
    else if (isCommand(command, "OF")) {
        handleOF();
    }
    else if (startsWith(command, "AI")) {
        handleAI(command);
    }
    else if (isCommand(command, "PS")) {
        handlePS();
    }
    else if (isCommand(command, "AG")) {
        handleAG();
    }
    else if (isCommand(command, "RG")) {
        handleRG();
    }
    else if (isCommand(command, "PC")) {
        handlePC();
    }
}

//===============
// Public functions
//===============

void begin()
{
    Serial.println("CAT: initialized");
}

void update()
{
    while (Serial.available() > 0) {
        char c = Serial.read();

        if (c == ';') {
            buffer[index] = '\0';
            handleCommand(buffer);
            index = 0;
        }
        else if (index < CAT_BUFFER_SIZE - 1) {
            buffer[index++] = c;
        }
        else {
            index = 0;
        }
    }
}

}