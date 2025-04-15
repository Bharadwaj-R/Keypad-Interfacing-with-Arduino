#include "EventChecker.h"
#include "StateVariable.h" 

char newKeyPress = '\0';

void StateMachine()
{
    switch(State)
    {

        case ScanReady:
        newKeyPress = ScanKeypad();
        if(newKeyPress == '\0')
        {
            return;
        }
        ServiceScanReady();
        Serial.println(newKeyPress);
        State = KeyPressed;
        break;

        
        case KeyPressed:
        ServiceKeyPressed();
        State = ScanReady;
        break;

        
        default:
        State = ScanReady;
    }
    
}


