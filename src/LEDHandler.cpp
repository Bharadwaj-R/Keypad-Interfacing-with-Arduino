#include "LEDHandler.h"

#define LEDPIN A5

uint32_t currentLEDTime;
bool currentLEDState = true;
uint32_t timeOfLastLEDToggle = 0;
uint16_t timeInPreviousLEDState = 0;

void SetupLED()
{
    pinMode(LEDPIN, OUTPUT);
    digitalWrite(LEDPIN, HIGH);
}

void ChangeLEDState()
{
    currentLEDState = !currentLEDState;
    digitalWrite(LEDPIN, currentLEDState);
    currentLEDTime = millis();
}

void DisplayPreviousLEDStateTime()
{
    timeInPreviousLEDState = currentLEDTime - timeOfLastLEDToggle;
    Serial.print("Seconds In LED Previous State : ");
    Serial.println(timeInPreviousLEDState/1000.0);
    Serial.println();
}

void UpdateLastToggleActivityTime()
{
    timeOfLastLEDToggle = currentLEDTime;
}
