#include "LEDHandler.h"

uint32_t currentTime;
bool currentLEDState = true;
uint32_t timeOfLastLEDToggle = 0;
uint16_t timeInPreviousLEDState = 0;

void SetupLED()
{
    pinMode(LEDPIN, OUTPUT);
}

void ChangeLEDState()
{
    currentLEDState = !currentLEDState;
    digitalWrite(LEDPIN, currentLEDState);
    currentTime = millis();
}

void DisplayPreviousLEDStateTime()
{
    timeInPreviousLEDState = currentTime - timeOfLastLEDToggle;
    Serial.println(timeInPreviousLEDState);
}

void UpdateLastToggleActivityTime()
{
    timeOfLastLEDToggle = currentTime;
}
