#include <Arduino.h>

#include "EventChecker.h"

void setup()
{
  SetupLED();
  SetupKeypad();
  Serial.begin(115200);
  Serial.println("!! Please do not press any key !!");
  char keyInput = ScanKeypad();
  if (keyInput == '\0')
  {
    Serial.println("Keypad Initialized. Ready to take input.");
  }
  digitalWrite(LEDPIN, HIGH);
  State = ScanReady;
}

void loop()
{
  StateMachine();
}