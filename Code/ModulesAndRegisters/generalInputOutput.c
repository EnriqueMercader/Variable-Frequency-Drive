#include "generalInputOutput.h"

void generalInputOutput_Configuration(void){
    LATE = 0;
    LATD = 0;
    LATA = 0;
    LATB = 0;
    LATC = 0;

    TRISE = 0b00000000;
    TRISA = 0b00000000;
    TRISB = 0b00000000;
    TRISC = 0b11110000;
    TRISD = 0b00000000;

    ANSELD = 0;
    ANSELC = 0;
    ANSELB = 0;
    ANSELE = 0;
    ANSELA = 0;

    WPUD = 0;
    WPUE = 0;
    WPUB = 0;
    WPUA = 0;
    WPUC = 0;

    ODCONE = 0;
    ODCONA = 0;
    ODCONB = 0;
    ODCONC = 0;
    ODCOND = 0;

    SLRCONA = 0xFF;
    SLRCONB = 0xFF;
    SLRCONC = 0xFF;
    SLRCOND = 0xFF;
    SLRCONE = 0x07;

    INLVLA = 0xFF;
    INLVLB = 0xFF;
    INLVLC = 0b01110000;
    INLVLD = 0xFF;
    INLVLE = 0x0F;
}