#include "KeypadScanner.h"

// First 4 bits gives the column, next 4 bits gives the row

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

/*
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
*/

void SetupKeypad()
{
    pinMode(PORTB, INPUT_PULLUP);  // the whole port B will read 1 by default B11111111
    pinMode(PORTD, OUTPUT);
    digitalWrite(PORTD, B11110000);
    digitalWrite(PORTD, B00000000);
}

char ScanKeypad()
{
    for(scan = 0; scan < 4; scan++)
    {   
        digitalWrite(PORTD, columnScan[scan%4]);
        rowInput = PINB;
        keyCode = columnScan[scan%4] ^ rowInput;        

        switch (keyCode)
        {
        case BUTTON_0_PRESSED:
            return '0';
        break;
        
        case BUTTON_1_PRESSED:
            return '1';
        break;
        
        case BUTTON_2_PRESSED:
            return '2';
        break;
        
        case BUTTON_3_PRESSED:
            return '3';
        break;
        
        case BUTTON_4_PRESSED:
            return '4';
        break;
        
        case BUTTON_5_PRESSED:
            return '5';
        break;
        
        case BUTTON_6_PRESSED:
            return '6';
        break;
        
        case BUTTON_7_PRESSED:
            return '7';
        break;
        
        case BUTTON_8_PRESSED:
            return '8';
        break;
        
        case BUTTON_9_PRESSED:
            return '9';
        break;

        case BUTTON_star_PRESSED:
            return '*';
        break;
        
        case BUTTON_hash_PRESSED:
            return '#';
        break;
        
        case BUTTON_A_PRESSED:
            return 'A';
        break;
        
        case BUTTON_B_PRESSED:
            return 'B';
        break;
        
        case BUTTON_C_PRESSED:
            return 'C';
        break;
        
        case BUTTON_D_PRESSED:
            return 'D';
        break;

        default:
            return '\0';
        break;
        
        }
    }
}