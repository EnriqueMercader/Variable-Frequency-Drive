#include "sevenSegmentDisplay.h"

void sevenSegmentDisplay(char number){
    switch (number) {
        case 0:
            SegmentA = 1;
            SegmentB = 1;
            SegmentC = 1;
            SegmentD = 1;
            SegmentE = 1;
            SegmentF = 1;
            SegmentG = 0;
            break;
        case 1:
            SegmentA = 0;
            SegmentB = 1;
            SegmentC = 1;
            SegmentD = 0;
            SegmentE = 0;
            SegmentF = 0;
            SegmentG = 0;
            break;
        case 2:
            SegmentA = 1;
            SegmentB = 1;
            SegmentC = 0;
            SegmentD = 1;
            SegmentE = 1;
            SegmentF = 0;
            SegmentG = 1;
            break;
        case 3:
            SegmentA = 1;
            SegmentB = 1;
            SegmentC = 1;
            SegmentD = 1;
            SegmentE = 0;
            SegmentF = 0;
            SegmentG = 1;
            break;
        case 4:
            SegmentA = 0;
            SegmentB = 1;
            SegmentC = 1;
            SegmentD = 0;
            SegmentE = 0;
            SegmentF = 1;
            SegmentG = 1;
            break;
        case 5:
            SegmentA = 1;
            SegmentB = 0;
            SegmentC = 1;
            SegmentD = 1;
            SegmentE = 0;
            SegmentF = 1;
            SegmentG = 1;
            break;
        case 6:
            SegmentA = 1;
            SegmentB = 0;
            SegmentC = 1;
            SegmentD = 1;
            SegmentE = 1;
            SegmentF = 1;
            SegmentG = 1;
            break;
        case 7:
            SegmentA = 1;
            SegmentB = 1;
            SegmentC = 1;
            SegmentD = 0;
            SegmentE = 0;
            SegmentF = 0;
            SegmentG = 0;
            break;
        case 8:
            SegmentA = 1;
            SegmentB = 1;
            SegmentC = 1;
            SegmentD = 1;
            SegmentE = 1;
            SegmentF = 1;
            SegmentG = 1;
            break;
        case 9:
            SegmentA = 1;
            SegmentB = 1;
            SegmentC = 1;
            SegmentD = 1;
            SegmentE = 0;
            SegmentF = 1;
            SegmentG = 1;
            break;
        case 'F':
            SegmentA = 1;
            SegmentB = 0;
            SegmentC = 0;
            SegmentD = 0;
            SegmentE = 1;
            SegmentF = 1;
            SegmentG = 1;
            break;
        case 'o':
            SegmentA = 1;
            SegmentB = 1;
            SegmentC = 1;
            SegmentD = 1;
            SegmentE = 1;
            SegmentF = 1;
            SegmentG = 0;
            break;
        default:
            
            break;
    }
}
void multiplexDisplay(int number,bool run){
    if (run == true){
        for (int i = 4 - 1; i >= 0; i--) {
            digits[i] = number % 10;
            number /= 10;
        }
    }
    else{
        digits[0] = 0;
        digits[1] = 'o';
        digits[2] = 'F';
        digits[3] = 'F';
    }
    
    if (displayNumber >= 3){
        displayNumber = 0;
    }
    else{
        displayNumber++;
    }
    switch (displayNumber) {
        case 0:
            if (digits[0] != 0){  
                display0 = 1;
            }
            display3 = 0;
            break;
        case 1:
            if ((digits[0] != 0) || (digits[1] != 0)){
                display1 = 1;
            }
            display0 = 0;
            break;
        case 2:
            if ((digits[0] != 0) || (digits[1] != 0) || (digits[2] != 0)){
                display2 = 1;
            }
            display1 = 0;
            break;
        case 3:
            display2 = 0;
            display3 = 1;
            break;
        default:
            
            break;
    }
    sevenSegmentDisplay(digits[displayNumber]);
}