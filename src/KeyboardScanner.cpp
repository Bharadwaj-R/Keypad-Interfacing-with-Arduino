#include "KeyboardScanner.h"

#define BUTTON_1_PRESSED B01110111
#define BUTTON_2_PRESSED B10110111
#define BUTTON_3_PRESSED B11010111
#define BUTTON_A_PRESSED B11100111

#define BUTTON_4_PRESSED B01111011
#define BUTTON_5_PRESSED B10111011
#define BUTTON_6_PRESSED B11011011
#define BUTTON_B_PRESSED B11101011

#define BUTTON_7_PRESSED B01111101
#define BUTTON_8_PRESSED B10111101
#define BUTTON_9_PRESSED B11011101
#define BUTTON_C_PRESSED B11101101

#define BUTTON_star_PRESSED B01111110
#define BUTTON_0_PRESSED    B10111110
#define BUTTON_hash_PRESSED B11011110
#define BUTTON_D_PRESSED    B11101110

#define TIME_INTERVAL 200

#define FIRST_COLUMN B01110000
#define SECOND_COLUMN B10110000
#define THIRD_COLUMN B11010000
#define FOURTH_COLUMN B11100000


uint8_t columnScan[4] = {FIRST_COLUMN, SECOND_COLUMN, THIRD_COLUMN, FOURTH_COLUMN};
uint8_t scan = 0;
uint8_t rowInput = B00000000;
uint8_t keyCode = 0;
uint32_t lastActivity = 0;
uint32_t currentTime = 0;

bool flagButton_0_Pressed = false;
bool flagButton_1_Pressed = false;
bool flagButton_2_Pressed = false;
bool flagButton_3_Pressed = false;
bool flagButton_4_Pressed = false;
bool flagButton_5_Pressed = false;
bool flagButton_6_Pressed = false;
bool flagButton_7_Pressed = false;
bool flagButton_8_Pressed = false;
bool flagButton_9_Pressed = false;
bool flagButton_star_Pressed = false;
bool flagButton_hash_Pressed = false;
bool flagButton_A_Pressed = false;
bool flagButton_B_Pressed = false;
bool flagButton_C_Pressed = false;
bool flagButton_D_Pressed = false;

void SetupKeypad()
{
    pinMode(PORTB, INPUT_PULLUP);
    pinMode(PORTC, OUTPUT);
}

char DecodeKey()
{

}

char ScanKeypad()
{
    for(;;scan++)
    {   
        if(scan = 255) { scan = 3;} 
        rowInput = PINB;

        keyCode = columnScan[scan%4] ^ rowInput;

        currentTime = millis();
        
        
        switch (keyCode)
        {
        case BUTTON_0_PRESSED:
        if(currentTime - lastActivity > TIME_INTERVAL && flagButton_0_Pressed)
        {
            flagButton_0_Pressed = false;
            return(DecodeKey());
        }
        flagButton_0_Pressed = true;
        break;
        
        case BUTTON_1_PRESSED:
        if(currentTime - lastActivity > TIME_INTERVAL && flagButton_1_Pressed)
        {
            flagButton_1_Pressed = false;
            return(DecodeKey());
        }
        flagButton_1_Pressed = true;
        break;
        
        case BUTTON_2_PRESSED:
        if(currentTime - lastActivity > TIME_INTERVAL && flagButton_2_Pressed)
        {
            flagButton_2_Pressed = false;
            return(DecodeKey());
        }
        flagButton_2_Pressed = true;
        break;
        
        case BUTTON_3_PRESSED:
        if(currentTime - lastActivity > TIME_INTERVAL && flagButton_3_Pressed)
        {
            flagButton_3_Pressed = false;
            return(DecodeKey());
        }
        flagButton_3_Pressed = true;
        break;
        
        case BUTTON_4_PRESSED:
        if(currentTime - lastActivity > TIME_INTERVAL && flagButton_4_Pressed)
        {
            flagButton_4_Pressed = false;
            return(DecodeKey());
        }
        flagButton_4_Pressed = true;
        break;
        
        case BUTTON_5_PRESSED:
        if(currentTime - lastActivity > TIME_INTERVAL && flagButton_5_Pressed)
        {
            flagButton_5_Pressed = false;
            return(DecodeKey());
        }
        flagButton_5_Pressed = true;
        break;
        
        case BUTTON_6_PRESSED:
        if(currentTime - lastActivity > TIME_INTERVAL && flagButton_6_Pressed)
        {
            flagButton_6_Pressed = false;
            return(DecodeKey());
        }
        flagButton_6_Pressed = true;
        break;
        
        case BUTTON_7_PRESSED:
        if(currentTime - lastActivity > TIME_INTERVAL && flagButton_7_Pressed)
        {
            flagButton_7_Pressed = false;
            return(DecodeKey());
        }
        flagButton_7_Pressed = true;
        break;
        
        case BUTTON_8_PRESSED:
        if(currentTime - lastActivity > TIME_INTERVAL && flagButton_8_Pressed)
        {
            flagButton_8_Pressed = false;
            return(DecodeKey());
        }
        flagButton_8_Pressed = true;
        break;
        
        case BUTTON_9_PRESSED:
        if(currentTime - lastActivity > TIME_INTERVAL && flagButton_9_Pressed)
        {
            flagButton_9_Pressed = false;
            return(DecodeKey());
        }
        flagButton_9_Pressed = true;
        break;

        case BUTTON_star_PRESSED:
        if(currentTime - lastActivity > TIME_INTERVAL && flagButton_star_Pressed)
        {
            flagButton_star_Pressed = false;
            return(DecodeKey());
        }
        flagButton_star_Pressed = true;
        break;
        
        case BUTTON_hash_PRESSED:
        if(currentTime - lastActivity > TIME_INTERVAL && flagButton_hash_Pressed)
        {
            flagButton_hash_Pressed = false;
            return(DecodeKey());
        }
        flagButton_hash_Pressed = true;
        break;
        
        case BUTTON_A_PRESSED:
        if(currentTime - lastActivity > TIME_INTERVAL && flagButton_A_Pressed)
        {
            flagButton_A_Pressed = false;
            return(DecodeKey());
        }
        flagButton_A_Pressed = true;
        break;
        
        case BUTTON_B_PRESSED:
        if(currentTime - lastActivity > TIME_INTERVAL && flagButton_B_Pressed)
        {
            flagButton_B_Pressed = false;
            return(DecodeKey());
        }
        flagButton_B_Pressed = true;
        break;
        
        case BUTTON_C_PRESSED:
        if(currentTime - lastActivity > TIME_INTERVAL && flagButton_C_Pressed)
        {
            flagButton_C_Pressed = false;
            return(DecodeKey());
        }
        flagButton_C_Pressed = true;
        break;
        
        case BUTTON_D_PRESSED:
        if(currentTime - lastActivity > TIME_INTERVAL && flagButton_D_Pressed)
        {
            flagButton_D_Pressed = false;
            return(DecodeKey());
        }
        flagButton_D_Pressed = true;
        break;

        default:
        flagButton_0_Pressed =      false;
        flagButton_1_Pressed =      false;
        flagButton_2_Pressed =      false;
        flagButton_3_Pressed =      false;
        flagButton_4_Pressed =      false;
        flagButton_5_Pressed =      false;
        flagButton_6_Pressed =      false;
        flagButton_7_Pressed =      false;
        flagButton_8_Pressed =      false;
        flagButton_9_Pressed =      false;
        flagButton_star_Pressed =   false;
        flagButton_hash_Pressed =   false;
        flagButton_A_Pressed =      false;
        flagButton_B_Pressed =      false;
        flagButton_C_Pressed =      false;
        flagButton_D_Pressed =      false;
        break;
        
        }

        rowInput = 0;
    }
}