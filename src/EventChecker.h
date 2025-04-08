#include <Arduino.h>
#include "EventServiceProvider.h"
#include "KeypadScanner.h"

void StateMachine();

bool EventKeyPress();
bool EventKeyInput();
bool EventWaitStage();
bool EventFalseKey();