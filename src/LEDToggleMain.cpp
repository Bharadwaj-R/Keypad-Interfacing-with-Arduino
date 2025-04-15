#include <Arduino.h>

#include "EventChecker.h"

void setup()
{
  SetupLED();
  SetupKeypad();
  Serial.begin(2000000);
}

void loop()
{
  StateMachine();
}