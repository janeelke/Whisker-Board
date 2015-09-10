#include <plib.h>
#include "PIC32MX250pins.h"


void PIC32MX250_setup_pins(void) {
	// set all analog input pins to digital mode
	ANSELA = 0;
	ANSELB = 0;
        //ANSELBbits.ANSB14 = 1; // Use AN10 on B14 as analog input
    ANSELAbits.ANSA0 = 1;

	// set all pins to digital inputs
	TRISA = 0xFFFF;
	TRISB = 0xFFFF;

    //uController
    //4-PGED1
    //5-PGEC1
    
    //SPI
    //25-SCK1
    //14-SD01-RPB5 MOSI
    RPB5Rbits.RPB5R=0b0011;
    //22-SDI1-RPB11 MISO
    SDI1Rbits.SDI1R=0b0011;
    //CS 9-12
        //9-RA2
        TRISAbits.TRISA2=0;
        //10-RA3
        TRISAbits.TRISA3=0;
        //11-RB4
        TRISBbits.TRISB4=0;
        //12-RA4
        TRISAbits.TRISA4=0;
    
    //Analog Input
    //2-AN0-RA0
    ANSELAbits.ANSA0=1;
    //3-AN1-RA1
    ANSELAbits.ANSA1=1;
    //6-AN4-RB2
    ANSELBbits.ANSB2=1;
    //7-AN5-RB3
    ANSELBbits.ANSB3=1;
    
    //I2C
    //18-SDA1
    //17-SCL1
}
