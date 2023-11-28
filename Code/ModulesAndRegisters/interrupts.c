#include "interrupts.h"

void interrupts_Configuration(void){
    /* Interrupt on change*/
     /*Increase Button*/
        IOCCFbits.IOCCF4 = 0;   //interrupt on change for C4 - flag
        IOCCNbits.IOCCN4 = 0;   //interrupt on change for C4 - negative
        IOCCPbits.IOCCP4 = 1;   //interrupt on change for C4 - positive
    /*Decrease button*/
        IOCCFbits.IOCCF5 = 0;   //interrupt on change for C5 - flag
        IOCCNbits.IOCCN5 = 0;   //interrupt on change for C5 - negative
        IOCCPbits.IOCCP5 = 1;   //interrupt on change for C5 - positive
    /*Halt button*/
        IOCCFbits.IOCCF6 = 0;   //interrupt on change for C6 - flag
        IOCCNbits.IOCCN6 = 0;   //interrupt on change for C6 - negative
        IOCCPbits.IOCCP6= 1;   //interrupt on change for C6 - positive
        
    PIE0bits.IOCIE = 1;     // Enable IOCI interrupt 

    /* General */
    INTCONbits.GIE = 1;         // Enable global interrupt
    INTCONbits.PEIE = 1;        // Peripheral interrupt enable
}