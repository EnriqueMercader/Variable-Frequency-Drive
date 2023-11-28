#include "peripheralPinSelect.h"

void peripheralPinSelect_Configuration(void){
        
    #define CCP1    0x09
    #define CCP2    0x0A
    #define CCP3    0x0B
    RB7PPS = CCP1;  
    RB5PPS = CCP2;    
    RB3PPS = CCP3;   
}
