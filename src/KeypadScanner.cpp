#include "KeypadScanner.h"

// First 4 bits give the column, next 4 bits give the row

#define BUTTON_1_PRESSED B10001000
#define BUTTON_2_PRESSED B01001000
#define BUTTON_3_PRESSED B00101000
#define BUTTON_A_PRESSED B00011000

#define BUTTON_4_PRESSED B10000100
#define BUTTON_5_PRESSED B01000100
#define BUTTON_6_PRESSED B00100100
#define BUTTON_B_PRESSED B00010100

#define BUTTON_7_PRESSED B10000010
#define BUTTON_8_PRESSED B01000010
#define BUTTON_9_PRESSED B00100010
#define BUTTON_C_PRESSED B00010010

#define BUTTON_star_PRESSED B10000001
#define BUTTON_0_PRESSED    B01000001
#define BUTTON_hash_PRESSED B00100001
#define BUTTON_D_PRESSED    B00010001

#define TIME_INTERVAL 200

#define FIRST_COLUMN    B01111111
#define SECOND_COLUMN   B10111111
#define THIRD_COLUMN    B11011111
#define FOURTH_COLUMN   B11101111

#define FIRST_ROW   B11110111
#define SECOND_ROW  B11111011
#define THIRD_ROW   B11111101
#define FOURTH_ROW  B11111110


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
    pinMode(PORTB, INPUT_PULLUP);  // the whole port B will read 1 by default B11111111
    pinMode(PORTD, OUTPUT);
    digitalWrite(PORTD, B11110000);
    digitalWrite(PORTD, B00000000);
}

char ScanKeypad()
{
    while(true)
    {   
        if(scan = 255) scan = 3; 
        digitalWrite(PORTD, columnScan[scan%4]);
        rowInput = PINB;
        keyCode = columnScan[scan%4] ^ rowInput;

        currentTime = millis();
        

        switch (keyCode)
        {
        case BUTTON_0_PRESSED:
        if(currentTime - lastActivity > TIME_INTERVAL && flagButton_0_Pressed)
        {
            flagButton_0_Pressed = false;
            lastActivity = currentTime;
            return('0');
        }
        flagButton_0_Pressed = true;
        break;
        
        case BUTTON_1_PRESSED:
        if(currentTime - lastActivity > TIME_INTERVAL && flagButton_1_Pressed)
        {
            flagButton_1_Pressed = false;
            lastActivity = currentTime;
            return('1');
        }
        flagButton_1_Pressed = true;
        break;
        
        case BUTTON_2_PRESSED:
        if(currentTime - lastActivity > TIME_INTERVAL && flagButton_2_Pressed)
        {
            flagButton_2_Pressed = false;
            lastActivity = currentTime;
            return('2');
        }
        flagButton_2_Pressed = true;
        break;
        
        case BUTTON_3_PRESSED:
        if(currentTime - lastActivity > TIME_INTERVAL && flagButton_3_Pressed)
        {
            flagButton_3_Pressed = false;
            lastActivity = currentTime;
            return('3');
        }
        flagButton_3_Pressed = true;
        break;
        
        case BUTTON_4_PRESSED:
        if(currentTime - lastActivity > TIME_INTERVAL && flagButton_4_Pressed)
        {
            flagButton_4_Pressed = false;
            lastActivity = currentTime;
            return('4');
        }
        flagButton_4_Pressed = true;
        break;
        
        case BUTTON_5_PRESSED:
        if(currentTime - lastActivity > TIME_INTERVAL && flagButton_5_Pressed)
        {
            flagButton_5_Pressed = false;
            lastActivity = currentTime;
            return('5');
        }
        flagButton_5_Pressed = true;
        break;
        
        case BUTTON_6_PRESSED:
        if(currentTime - lastActivity > TIME_INTERVAL && flagButton_6_Pressed)
        {
            flagButton_6_Pressed = false;
            lastActivity = currentTime;
            return('6');
        }
        flagButton_6_Pressed = true;
        break;
        
        case BUTTON_7_PRESSED:
        if(currentTime - lastActivity > TIME_INTERVAL && flagButton_7_Pressed)
        {
            flagButton_7_Pressed = false;
            lastActivity = currentTime;
            return('7');
        }
        flagButton_7_Pressed = true;
        break;
        
        case BUTTON_8_PRESSED:
        if(currentTime - lastActivity > TIME_INTERVAL && flagButton_8_Pressed)
        {
            flagButton_8_Pressed = false;
            lastActivity = currentTime;
            return('8');
        }
        flagButton_8_Pressed = true;
        break;
        
        case BUTTON_9_PRESSED:
        if(currentTime - lastActivity > TIME_INTERVAL && flagButton_9_Pressed)
        {
            flagButton_9_Pressed = false;
            lastActivity = currentTime;
            return('9');
        }
        flagButton_9_Pressed = true;
        break;

        case BUTTON_star_PRESSED:
        if(currentTime - lastActivity > TIME_INTERVAL && flagButton_star_Pressed)
        {
            flagButton_star_Pressed = false;
            lastActivity = currentTime;
            return('*');
        }
        flagButton_star_Pressed = true;
        break;
        
        case BUTTON_hash_PRESSED:
        if(currentTime - lastActivity > TIME_INTERVAL && flagButton_hash_Pressed)
        {
            flagButton_hash_Pressed = false;
            lastActivity = currentTime;
            return('#');
        }
        flagButton_hash_Pressed = true;
        break;
        
        case BUTTON_A_PRESSED:
        if(currentTime - lastActivity > TIME_INTERVAL && flagButton_A_Pressed)
        {
            flagButton_A_Pressed = false;
            lastActivity = currentTime;
            return('A');
        }
        flagButton_A_Pressed = true;
        break;
        
        case BUTTON_B_PRESSED:
        if(currentTime - lastActivity > TIME_INTERVAL && flagButton_B_Pressed)
        {
            flagButton_B_Pressed = false;
            lastActivity = currentTime;
            return('B');
        }
        flagButton_B_Pressed = true;
        break;
        
        case BUTTON_C_PRESSED:
        if(currentTime - lastActivity > TIME_INTERVAL && flagButton_C_Pressed)
        {
            flagButton_C_Pressed = false;
            lastActivity = currentTime;
            return('C');
        }
        flagButton_C_Pressed = true;
        break;
        
        case BUTTON_D_PRESSED:
        if(currentTime - lastActivity > TIME_INTERVAL && flagButton_D_Pressed)
        {
            flagButton_D_Pressed = false;
            lastActivity = currentTime;
            return('D');
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
        scan++;
        lastActivity = currentTime;
        break;
        
        }
    }
}