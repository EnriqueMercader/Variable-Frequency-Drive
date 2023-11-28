#include "interrupt.h"
#define Phase1  0
#define Phase2  1
#define Phase3  2
char sineDirection[3] = {1,1,1};
char SineTableIndex[3] = {0,14,28};
void __interrupt() myISR (void){
    if (TMR0IF) {
        if (run == true){
            for(char i = 0; i<=2; i++){
                SineTableIndex[i]++;
                if (SineTableIndex[i] >= 42) {
                    SineTableIndex[i] = 0;
                    if (sineDirection[i] == 1){
                        sineDirection[i] = 0;
                        if (i == Phase1){
                            RB2PPS = 0;   
                            RB3PPS = CCP1;   
                        }
                        else if (i == Phase2){     
                            RB5PPS = 0;
                            RB4PPS = CCP2;   
                        }
                        else{
                            RB6PPS = 0;
                            RB7PPS = CCP3;   
                        }
                    }
                    else{
                        sineDirection[i] = 1;
                        if (i == Phase1){
                            RB3PPS = 0;
                            RB2PPS = CCP1;
                        }
                        else if (i == Phase2){
                            RB5PPS = CCP2;
                            RB4PPS = 0;
                        }
                        else{
                            RB6PPS = CCP3; 
                            RB7PPS = 0;
                        }
                    }

                }
            }
            CCPR1L = sineTable[SineTableIndex[0]];
            CCPR2L = sineTable[SineTableIndex[1]];
            CCPR3L = sineTable[SineTableIndex[2]];
        }
        TMR0H    = timerLoadValue;                                      // Load the value calculated to obtain the desired interrupt frequency
        TMR0L = 0;
        TMR0IF = 0;                             // Resets the timer 0 interrupt flag
    }
    if (IOCCF5){
        desiredFrequency = desiredFrequency + frequencyStep;
        setTimer0(desiredFrequency);
        IOCCF5 = 0;
        __delay_ms(1);
    }
    
    if (IOCCF4){
        if (desiredFrequency > frequencyStep){
            desiredFrequency = desiredFrequency - frequencyStep;
        }
        setTimer0(desiredFrequency);
        IOCCF4 = 0;
        __delay_ms(1);
    }
    
    if (IOCCF6){
        if (run == true){
            run = false;
            CCPR1L = 0;
            CCPR2L = 0;
            CCPR3L = 0;
            desiredFrequency = 10;
            setTimer0(desiredFrequency);
        }
        else{
            run = true;
        }
        IOCCF6 = 0;
        __delay_ms(1);
    }
}