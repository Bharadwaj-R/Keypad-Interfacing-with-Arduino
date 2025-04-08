#include "EventChecker.h"

#define TIME_INTERVAL 100

bool flagKeyPress = false;
char prevKeyPress = '\0';
char newKeyPress = '\0';
uint32_t currentTime = 0;
uint32_t lastActivity = 0;

void StateMachine()
{
    currentTime = millis();
    newKeyPress = ScanKeypad();

    switch(State)
    {
        case KeyPressed:
            Serial.println(State);
            if (EventKeyInput()) 
            {
                ServiceKeyInput(newKeyPress);
                flagKeyPress = false;
                lastActivity = currentTime;
            }
            
            else if (EventFalseKey()) 
            {
                ServiceFalseKey();
                flagKeyPress = false;
                lastActivity = currentTime;
            }
            
            else if (EventWaitStage()) ServiceWaitStage();
        break;

        case ScanReady:
            Serial.println(State);
            if (EventKeyPress() && !flagKeyPress) 
            {
                ServiceKeyPress();
                flagKeyPress = true;
                lastActivity = currentTime;
                prevKeyPress = newKeyPress;
            }
        break;

        default:
            State = ScanReady;
    }
}


bool EventKeyPress()
{
    if (newKeyPress != '\0')
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