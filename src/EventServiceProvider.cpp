#include "EventServiceProvider.h" 

void ServiceScanReady()
{
    Serial.print("Key Pressed : ");
    return;
}

void ServiceKeyPressed()
{
    ChangeLEDState();
    DisplayPreviousLEDStateTime();
    UpdateLastToggleActivityTime();
    return;
}