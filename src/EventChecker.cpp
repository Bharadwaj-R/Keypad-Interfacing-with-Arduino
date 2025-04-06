#include "EventChecker.h"

#define TIME_INTERVAL 100

bool flagKeyPress = false;
char prevKeyPress = '\0';
char newKeyPress = '\0';
uint32_t currentTime = 0;
uint32_t lastActivity = 0;

void StateMachine()
{
    switch(State)
    {
        case Init:
            Serial.println("In Init State");
            if (EventKeyPress) ServiceKeyPress();
        break;

        case KeyPressed:
            Serial.println("In KeyPressed State");
            if (EventKeyInput) ServiceKeyInput();
            else if (EventFalseKey()) ServiceFalseKey();
            else if (EventWaitStage()) ServiceWaitStage();
        break;

        case ScanReady:
            Serial.println("In ScanReady State");
            if (EventKeyPress()) ServiceKeyPress();
        break;

        default:
        State = Init;
    }
}


bool EventKeyPress()
{
    newKeyPress = ScanKeypad();
    if (newKeyPress != '\0' && flagKeyPress)
    return true;
    else
    return false;
}


bool EventWaitStage()
{
    if ((currentTime - lastActivity < TIME_INTERVAL) && (prevKeyPress == newKeyPress) && flagKeyPress)
    return true;
    else
    return false;
}


bool EventKeyInput()
{
    if ((currentTime - lastActivity >= TIME_INTERVAL) && (prevKeyPress == newKeyPress) && flagKeyPress)
    return true;
    else 
    return false;
}


bool EventFalseKey()
{
    if ((currentTime - lastActivity < TIME_INTERVAL) && (prevKeyPress != newKeyPress) && flagKeyPress)
    return true;
    else
    return false;
}