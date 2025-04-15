#include "KeypadScanner.h"

// First 4 bits gives the column, next 4 bits gives the row

#define BUTTON_1_PRESSED 72
#define BUTTON_2_PRESSED 136
#define BUTTON_3_PRESSED 232
#define BUTTON_A_PRESSED 216

#define BUTTON_4_PRESSED 68
#define BUTTON_5_PRESSED 132
#define BUTTON_6_PRESSED 228
#define BUTTON_B_PRESSED 212

#define BUTTON_7_PRESSED 66
#define BUTTON_8_PRESSED 130
#define BUTTON_9_PRESSED 226
#define BUTTON_C_PRESSED 210

#define BUTTON_star_PRESSED 65
#define BUTTON_0_PRESSED    129
#define BUTTON_hash_PRESSED 225
#define BUTTON_D_PRESSED    209

#define FIRST_COLUMN    B01111111
#define SECOND_COLUMN   B10111111
#define THIRD_COLUMN    B11011111
#define FOURTH_COLUMN   B11101111

#define FIRST_ROW   B11110111
#define SECOND_ROW  B11111011
#define THIRD_ROW   B11111101
#define FOURTH_ROW  B11111110

#define debounce 100

uint8_t columnScan[4] = {FIRST_COLUMN, SECOND_COLUMN, THIRD_COLUMN, FOURTH_COLUMN};
uint8_t scan = 0;
uint8_t rowInput = B00000000;
uint8_t keyCode = 0;
char prevKey = '\0';
char newKey = '\0';
uint32_t currentTime = 0;
uint32_t previousTime = 0;

void SetupKeypad()
{
    // pinMode(PORTB, INPUT_PULLUP);  // the whole port B will read 1 by default B11111111
    pinMode(8, INPUT_PULLUP);
    pinMode(9, INPUT_PULLUP);
    pinMode(10, INPUT_PULLUP);
    pinMode(11, INPUT_PULLUP);
    pinMode(12, INPUT_PULLUP);
    pinMode(13, INPUT_PULLUP);
    
    DDRD = B11111111;
    PORTD = B00000000;
}

char ScanKeypad()
{
    currentTime = millis();
    for(scan = 0; scan < 4; scan++)
    {   
        PORTD = columnScan[scan];
        keyCode = PORTD ^ PINB;

        switch (keyCode)
        {
        case BUTTON_0_PRESSED:
            newKey = '0';
        break;
        
        case BUTTON_1_PRESSED:
            newKey = '1';
        break;
        
        case BUTTON_2_PRESSED:
            newKey = '2';
        break;
        
        case BUTTON_3_PRESSED:
            newKey = '3';
        break;
        
        case BUTTON_4_PRESSED:
            newKey = '4';
        break;
        
        case BUTTON_5_PRESSED:
            newKey = '5';
        break;
        
        case BUTTON_6_PRESSED:
            newKey = '6';
        break;
        
        case BUTTON_7_PRESSED:
            newKey = '7';
        break;
        
        case BUTTON_8_PRESSED:
            newKey = '8';
        break;
        
        case BUTTON_9_PRESSED:
            newKey = '9';
        break;

        case BUTTON_star_PRESSED:
            newKey = '*';
        break;
        
        case BUTTON_hash_PRESSED:
            newKey = '#';
        break;
        
        case BUTTON_A_PRESSED:
            newKey = 'A';
        break;
        
        case BUTTON_B_PRESSED:
            newKey = 'B';
        break;
        
        case BUTTON_C_PRESSED:
            newKey = 'C';
        break;
        
        case BUTTON_D_PRESSED:
            newKey = 'D';
        break;

        default:
            newKey = '\0';
        break;
        
        }

        if(newKey != '\0')
        {
            break;
        }
        
    }


    if(prevKey != '\0' && newKey == '\0' && currentTime - previousTime > debounce)
        {
            previousTime = currentTime;
            newKey = prevKey;
            prevKey = '\0';
            return newKey;
        }
        else if(prevKey != newKey)
        {   
            prevKey = newKey;
            previousTime = currentTime;
            return '\0';
        }
        else
        {
            return '\0';
        }
    
    
}
