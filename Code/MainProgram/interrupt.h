#ifndef INTERRUPT_H
#define	INTERRUPT_H
    /* Includes */
    #include <xc.h>
    #include <stdbool.h>
    #include "timer.h"

    /* Definitions */
    #define CCP1    0x09
    #define CCP2    0x0A
    #define CCP3    0x0B
    #define frequencyStep 2

    /* Variables */
    int desiredFrequency = 10; //30
    bool run = true;
    int timerLoadValue = 0;
    unsigned char sineTable[42] = {
        0, 7, 15, 22, 29, 37, 43,
        50, 56, 62, 68, 73, 78, 83, 
        87, 90, 93, 96, 97, 99, 100, 
        100, 100, 99, 97, 96, 93, 90, 
        87, 83, 78, 73, 68, 62, 56, 
        50, 43, 37, 29, 22, 15, 7};

#endif	/* INTERRUPT_H */

