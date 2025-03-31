#include <Arduino.h>

#include "EventChecker.h"
#include "EventServiceProvider.h"
#include "KeyboardScanner.h"
#include "LEDHandler.h"

void setup()
{
  pinMode(LEDPIN, OUTPUT);
  
  SetupKeypad();
  Serial.begin(9600);
}

void loop()
{
}