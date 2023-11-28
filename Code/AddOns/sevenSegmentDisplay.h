#ifndef SEVENSEGMENTDISPLAY_H
#define	SEVENSEGMENTDISPLAY_H
    /* Includes */
    #include <xc.h>
    #include <stdbool.h>

    /* Definitions */
    #define SegmentA    LATA2 //
    #define SegmentB    LATA0 //
    #define SegmentC    LATA4 //
    #define SegmentD    LATA5 //
    #define SegmentE    LATE0 //
    #define SegmentF    LATA1 //
    #define SegmentG    LATA3 //
    #define display0    LATC3 //
    #define display1    LATD0 //
    #define display2    LATD1 //
    #define display3    LATC2 //

    /* Variables */
    char digits[4] = {0,0,0,0};
    char displayNumber = 0;

    /* Functions' prototypes */
    void sevenSegmentDisplay(char number);
    void multiplexDisplay(int number, bool run);

#endif	/* SEVENSEGMENTDISPLAY_H */

