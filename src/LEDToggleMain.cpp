#include <Arduino.h>

#include "EventChecker.h"

void setup()
{
  SetupLED();
  SetupKeypad();
  Serial.begin(9600);
  char keyInput = ScanKeypad();
  if (keyInput == '\0')
  {
    Serial.println("Keypad Initialized. Ready to operate.");
  }
}

void loop()
{
  StateMachine();
}