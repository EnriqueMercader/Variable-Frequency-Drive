#include "timer.h"
#include "interrupt.h"

void setTimer0(int phaseFrequency){
    unsigned int prescalerValue = 1;
    signed char prescalerSelectBits = -1;
    do {
        timerLoadValue =((_XTAL_FREQ/(8 * partitions * (long) phaseFrequency * (long) prescalerValue)));
        prescalerValue = prescalerValue * 2;                        // Increases the prescaler value by a factor of 2
        prescalerSelectBits++;                                      // Increases the prescaler value for the register configuration
    } 
    while ((timerLoadValue < 0) || (timerLoadValue > 254));         // Checks if the calculated value is within the register's capacity
    TMR0H    = timerLoadValue;                                      // Load the value calculated to obtain the desired interrupt frequency
    TMR0L = 0;
    T0CON1 = (0b01000000 | prescalerSelectBits);                         // Enables timer 0 in 8 bit mode with the calculated prescaler
    PIR0bits.TMR0IF = 0;                                                // Clear Interrupt flag before enabling the interrupt
    PIE0bits.TMR0IE = 1;                                                // Enabling TMR0 interrupt.
    T0CON0 = 0b10000000;                                                // T0OUTPS 1:2; T0EN enabled; T016BIT 8-bit; 
}
