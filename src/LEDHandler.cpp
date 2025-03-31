#include "LEDHandler.h"

uint32_t currentTime;
bool currentLEDState = true;
uint32_t timeOfLastLEDToggle = 0;
uint16_t timeInPreviousLEDState = 0;


void ChangeLEDState()
{
    currentLEDState = !currentLEDState;
    digitalWrite(LEDPIN, currentLEDState);
    currentTime = millis();
}

void DisplayPreviousLEDStateTime()
{
    timeInPreviousLEDState = timeOfLastLEDToggle - currentTime;
    Serial.println(timeInPreviousLEDState);
}

void UpdateLastToggleActivityTime()
{
    timeOfLastLEDToggle = currentTime;
}
