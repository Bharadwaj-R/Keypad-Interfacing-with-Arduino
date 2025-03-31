#include <Arduino.h>

#define LEDPIN 0

void SetupLED();
void ChangeLEDState();
void UpdateLastToggleActivityTime();
void DisplayPreviousLEDStateTime();