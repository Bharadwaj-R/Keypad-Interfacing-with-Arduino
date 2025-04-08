#include "EventServiceProvider.h"
#include "LEDHandler.h" 

void ServiceKeyPress()
{
    State = KeyPressed; // Waiting for the correct key
}

void ServiceKeyInput(char keyInput)
{
    Serial.println(keyInput);
    ChangeLEDState();
    DisplayPreviousLEDStateTime();
    UpdateLastToggleActivityTime();
    State = ScanReady;  // Move from Key Pressed to Scan Ready for the next input
}

void ServiceWaitStage()
{
    State = KeyPressed; // Retain the Key Pressed State
}

void ServiceFalseKey()
{
    State = ScanReady;  // Reject the key and scan for next key input
}