#include <Arduino.h>

#include "EventChecker.h"
#include "EventServiceProvider.h"
#include "KeypadScanner.h"
#include "LEDHandler.h"

void setup()
{
  SetupLED();
  SetupKeypad();
  Serial.begin(9600);
}

void loop()
{
  char keyInput = ScanKeypad();
  Serial.println(keyInput);
}