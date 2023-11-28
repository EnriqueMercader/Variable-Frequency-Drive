/* Included libraries */
#include <xc.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Included files */
#include "configurationBits.h"
#include "interrupt.h"
#include "pwm.h"
#include "timer.h"
#include "generalInputOutput.h"
#include "interrupts.h"
#include "oscillator.h"
#include "peripheralModuleDisable.h"
#include "peripheralPinSelect.h"
#include "sevenSegmentDisplay.h"


/* Definitions */
#define _XTAL_FREQ 32000000


void device_Initialize(void){
    peripheralModuleDisable_Configuration();
    generalInputOutput_Configuration();
    peripheralPinSelect_Configuration();
    oscillator_Configuration();
    pwm_start();
    setTimer0(desiredFrequency);
    interrupts_Configuration();
}

void main(void){
    device_Initialize();
    while (1){
        multiplexDisplay(desiredFrequency, run);
        __delay_ms(1);
    }
}
