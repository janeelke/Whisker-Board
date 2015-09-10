#include <plib.h>
#include "PIC32MX150pins.h"

void PIC32MX150_setup_pins(void) {
	// set all analog input pins to digital mode
	ANSELA = 0;
	ANSELB = 0;
        //ANSELBbits.ANSB14 = 1; // Use AN10 on B14 as analog input

	// set all pins to digital inputs
	TRISA = 0xFFFF;
	TRISB = 0xFFFF;

	// Pins and functionality

	////// RA0 - Pin 2
	////INPUTS: AN0, INT4, T2CK, IC4, SS1, REFCLKI
	//ANSELAbits.ANSA0 = 1;
	//                                              ->INT4Rbits.INT4R = 0b0000;
	//T2CKRbits.T2CKR = 0b0000;
	//IC4Rbits.IC4R = 0b0000;
	//SS1Rbits.SS1R = 0b0000;
	//REFCLKIRbits.REFCLKIR = 0b0000;
	////OUTPUTS: NC, U1TX, U2RTS, SS1, OC1, C2OUT
	//RPA0Rbits.RPA0R = 0b0000; // NC
	//RPA0Rbits.RPA0R = 0b0001; // U1TX
	//RPA0Rbits.RPA0R = 0b0010; // U2RTS
	//RPA0Rbits.RPA0R = 0b0011; // SS1
	//RPA0Rbits.RPA0R = 0b0101; // OC1
	//RPA0Rbits.RPA0R = 0b0111; // C2OUT

        //OC2
	////// RA1 - Pin 3
	////INPUTS: AN1, INT3, T3CK, IC3, U1CTSR, U2RX, SDI1
	//ANSELAbits.ANSA1 = 1;
	//INT3Rbits.INT3R = 0b0000;
	//T3CKRbits.T3CKR = 0b0000;
	//IC3Rbits.IC3R = 0b0000;
	//U1CTSRbits.U1CTSR = 0b0000;
	//U2RXRbits.U2RXR = 0b0000;
	//SDI1Rbits.SDI1R = 0b0000;
	////OUTPUTS: NC, SDO1, SDO2, OC2
	//RPA1Rbits.RPA1R = 0b0000; // NC
	//RPA1Rbits.RPA1R = 0b0011; // SDO1
	//RPA1Rbits.RPA1R = 0b0100; // SDO2
	//RPA1Rbits.RPA1R = 0b0101; // OC2

        //Currently Empty Pin
	////// RA2 - Pin 9
	////INPUTS: INT2, T4CK, IC1, IC5, U1RX, U2CTS, SDI2, OCFB
	//                                                          ->INT2Rbits.INT2R = 0b0000;
	//T4CKRbits.T4CKR = 0b0000;
	//IC1Rbits.IC1R = 0b0000;
	//IC5Rbits.IC5R = 0b0000;
	//U1RXRbits.U1RXR = 0b0000;
	//U2CTSRbits.U2CTSR = 0b0000;
	//SDI2Rbits.SDI2R = 0b0000;
	//OCFBRbits.OCFBR = 0b0000;
	////OUTPUTS: NC, SDO1, SDO2, OC4, OC5, REFCLKO
	//RPA2Rbits.RPA2R = 0b0000; // NC
	//RPA2Rbits.RPA2R = 0b0011; // SDO1
	//RPA2Rbits.RPA2R = 0b0100; // SDO2
	//RPA2Rbits.RPA2R = 0b0101; // OC4
	//RPA2Rbits.RPA2R = 0b0110; // OC5
	//RPA2Rbits.RPA2R = 0b0111; // REFCLKO

        //Currently Empty Pin
	////// RA3 - Pin 10
	////INPUTS: INT1, T5CK, IC2, SS2, OCFA
	//                                               ->INT1Rbits.INT1R = 0b0000;
	//T5CKRbits.T5CKR = 0b0000;
	//IC2Rbits.IC2R = 0b0000;
	//SS2Rbits.SS2R = 0b0000;
	//OCFARbits.OCFAR = 0b0000;
	////OUTPUTS: NC, U1RTS, U2TX, SS2, OC3, C1OUT
	//RPA3Rbits.RPA3R = 0b0000; // NC
	//RPA3Rbits.RPA3R = 0b0001; // U1RTS
	//RPA3Rbits.RPA3R = 0b0010; // U2TX
	//RPA3Rbits.RPA3R = 0b0100; // SS2
	//RPA3Rbits.RPA3R = 0b0101; // OC3
	//RPA3Rbits.RPA3R = 0b0111; // C1OUT

        //Set to digital output
	////// RA4 - Pin 12
	////INPUTS: T1CK, INT2, T4CK, IC1, IC5, U1RX, U2CTS, SDI2, OCFB
	//INT2Rbits.INT2R = 0b0010;
	//T4CKRbits.T4CKR = 0b0010;
	//IC1Rbits.IC1R = 0b0010;
	//IC5Rbits.IC5R = 0b0010;
	//U1RXRbits.U1RXR = 0b0010;
	//U2CTSRbits.U2CTSR = 0b0010;
	//SDI2Rbits.SDI2R = 0b0010;
	//OCFBRbits.OCFBR = 0b0010;
	////OUTPUTS: NC, SDO1, SDO2, OC4, OC5, REFCLKO
	//RPA4Rbits.RPA4R = 0b0000; // NC
	//RPA4Rbits.RPA4R = 0b0011; // SDO1
	//RPA4Rbits.RPA4R = 0b0100; // SDO2
	//RPA4Rbits.RPA4R = 0b0101; // OC4
	//RPA4Rbits.RPA4R = 0b0110; // OC5
	//RPA4Rbits.RPA4R = 0b0111; // REFCLKO

	////// RB0 - Pin 4
	////INPUTS: AN2, INT1, T5CK, IC2, SS2, OCFA
	//ANSELBbits.ANSB0 = 1;
	//INT1Rbits.INT1R = 0b0010;
	//T5CKRbits.T5CKR = 0b0010;
	//IC2Rbits.IC2R = 0b0010;
	//SS2Rbits.SS2R = 0b0010;
	//OCFARbits.OCFAR = 0b0010;
	////OUTPUTS: NC, U1RTS, U2TX, SS2, OC3, C1OUT
	//RPB0Rbits.RPB0R = 0b0000; // NC
	//RPB0Rbits.RPB0R = 0b0001; // U1RTS
	//RPB0Rbits.RPB0R = 0b0010; // U2TX
	//RPB0Rbits.RPB0R = 0b0100; // SS2
	//RPB0Rbits.RPB0R = 0b0101; // OC3
	//RPB0Rbits.RPB0R = 0b0111; // C1OUT

	////// RB1 - Pin 5
	////INPUTS: AN3, INT3, T3CK, IC3, U1CTSR, U2RX, SDI1
	//ANSELBbits.ANSB1 = 1;
	//INT3Rbits.INT3R = 0b0010;
	//T3CKRbits.T3CKR = 0b0010;
	//IC3Rbits.IC3R = 0b0010;
	//U1CTSRbits.U1CTSR = 0b0010;
	//U2RXRbits.U2RXR = 0b0010;
	//SDI1Rbits.SDI1R = 0b0010;
	////OUTPUTS: NC, SDO1, SDO2, OC2
	//RPB1Rbits.RPB1R = 0b0000; // NC
	//RPB1Rbits.RPB1R = 0b0011; // SDO1
	//RPB1Rbits.RPB1R = 0b0100; // SDO2
	//RPB1Rbits.RPB1R = 0b0101; // OC2

        //Set to digital output
	////// RB2 - Pin 6
	////INPUTS: AN4, SDA2, INT2, T4CK, IC1, IC5, U1RX, U2CTS, SDI2, OCFB
	//ANSELBbits.ANSB2 = 1;
	//INT2Rbits.INT2R = 0b0100;
	//T4CKRbits.T4CKR = 0b0100;
	//IC1Rbits.IC1R = 0b0100;
	//IC5Rbits.IC5R = 0b0100;
	//U1RXRbits.U1RXR = 0b0100;
	//U2CTSRbits.U2CTSR = 0b0100;
	//SDI2Rbits.SDI2R = 0b0100;
	//OCFBRbits.OCFBR = 0b0100;
	////OUTPUTS: NC, SDO1, SDO2, OC4, OC5, REFCLKO
	//RPB2Rbits.RPB2R = 0b0000; // NC
	//RPB2Rbits.RPB2R = 0b0011; // SDO1
	//RPB2Rbits.RPB2R = 0b0100; // SDO2
	//RPB2Rbits.RPB2R = 0b0101; // OC4
	//RPB2Rbits.RPB2R = 0b0110; // OC5
	//RPB2Rbits.RPB2R = 0b0111; // REFCLKO

	////// RB3 - Pin 7
	////INPUTS: AN5, SCL2, INT4, T2CK, IC4, SS1, REFCLKI
	//ANSELBbits.ANSB3 = 1;
	//INT4Rbits.INT4R = 0b0001;
	//T2CKRbits.T2CKR = 0b0001;
	//IC4Rbits.IC4R = 0b0001;
	//SS1Rbits.SS1R = 0b0001;
	//REFCLKIRbits.REFCLKIR = 0b0001;
	////OUTPUTS: NC, U1TX, U2RTS, SS1, OC1, C2OUT
	//RPB3Rbits.RPB3R	= 0b0000; // NC
	//RPB3Rbits.RPB3R = 0b0001; // U1TX
	//RPB3Rbits.RPB3R = 0b0010; // U2RTS
	//RPB3Rbits.RPB3R = 0b0011; // SS1
	//RPB3Rbits.RPB3R = 0b0101; // OC1
	//RPB3Rbits.RPB3R = 0b0111; // C2OUT

        //Set to digital output
	////// RB4 - Pin 11
	////INPUTS: INT4, T2CK, IC4, SS1, REFCLKI
	//INT4Rbits.INT4R = 0b0010;
	//T2CKRbits.T2CKR = 0b0010;
	//IC4Rbits.IC4R = 0b0010;
	//SS1Rbits.SS1R = 0b0010;
	//REFCLKIRbits.REFCLKIR = 0b0010;
	////OUTPUTS: NC, U1TX, U2RTS, SS1, OC1, C2OUT
	//RPB4Rbits.RPB4R	= 0b0000; // NC
	//RPB4Rbits.RPB4R = 0b0001; // U1TX
	//RPB4Rbits.RPB4R = 0b0010; // U2RTS
	//RPB4Rbits.RPB4R = 0b0011; // SS1
	//RPB4Rbits.RPB4R = 0b0101; // OC1
	//RPB4Rbits.RPB4R = 0b0111; // C2OUT

        //Set to digital output
	////// RB5 - Pin 14
	////INPUTS: INT3, T3CK, IC3, U1CTSR, U2RX, SDI1
	//INT3Rbits.INT3R = 0b0001;
	//T3CKRbits.T3CKR = 0b0001;
	//IC3Rbits.IC3R = 0b0001;
	//U1CTSRbits.U1CTSR = 0b0001;
	//U2RXRbits.U2RXR = 0b0001;
	//SDI1Rbits.SDI1R = 0b0001;
	////OUTPUTS: NC, SDO1, SDO2, OC2
	//RPB5Rbits.RPB5R = 0b0000; // NC
	//RPB5Rbits.RPB5R = 0b0011; // SDO1
	//RPB5Rbits.RPB5R = 0b0100; // SDO2
	//RPB5Rbits.RPB5R = 0b0101; // OC2

        //Set to digital output
	////// RB6 - Pin 15
	////INPUTS: INT2, T4CK, IC1, IC5, U1RX, U2CTS, SDI2, OCFB
	//INT2Rbits.INT2R = 0b0001;
	//T4CKRbits.T4CKR = 0b0001;
	//IC1Rbits.IC1R = 0b0001;
	//IC5Rbits.IC5R = 0b0001;
	//U1RXRbits.U1RXR = 0b0001;
	//U2CTSRbits.U2CTSR = 0b0001;
	//SDI2Rbits.SDI2R = 0b0001;
	//OCFBRbits.OCFBR = 0b0001;
	////OUTPUTS: NC, SDO1, SDO2, OC4, OC5, REFCLKO
	//RPB6Rbits.RPB6R = 0b0000; // NC
	//RPB6Rbits.RPB6R = 0b0011; // SDO1
	//RPB6Rbits.RPB6R = 0b0100; // SDO2
	//RPB6Rbits.RPB6R = 0b0101; // OC4
	//RPB6Rbits.RPB6R = 0b0110; // OC5
	//RPB6Rbits.RPB6R = 0b0111; // REFCLKO

        //Set to digital output
	////// RB7 - Pin 16
	////INPUTS: INT0, INT4, T2CK, IC4, SS1, REFCLKI
	//INT4Rbits.INT4R = 0b0100;
	//T2CKRbits.T2CKR = 0b0100;
	//IC4Rbits.IC4R = 0b0100;
	//SS1Rbits.SS1R = 0b0100;
	//REFCLKIRbits.REFCLKIR = 0b0100;
	////OUTPUTS: NC, U1TX, U2RTS, SS1, OC1, C2OUT
	//RPB7Rbits.RPB7R	= 0b0000; // NC
	//RPB7Rbits.RPB7R = 0b0001; // U1TX
	//RPB7Rbits.RPB7R = 0b0010; // U2RTS
	//RPB7Rbits.RPB7R = 0b0011; // SS1
	//RPB7Rbits.RPB7R = 0b0101; // OC1
	//RPB7Rbits.RPB7R = 0b0111; // C2OUT

        //Laser
	////// RB8 - Pin 17
	////INPUTS: SCL1, INT3, T3CK, IC3, U1CTSR, U2RX, SDI1
	//INT3Rbits.INT3R = 0b0100;
	//T3CKRbits.T3CKR = 0b0100;
	//IC3Rbits.IC3R = 0b0100;
	//U1CTSRbits.U1CTSR = 0b0100;
	//U2RXRbits.U2RXR = 0b0100;
	//SDI1Rbits.SDI1R = 0b0100;
	////OUTPUTS: NC, SDO1, SDO2, OC2
	//RPB8Rbits.RPB8R = 0b0000; // NC
	//RPB8Rbits.RPB8R = 0b0011; // SDO1
	//RPB8Rbits.RPB8R = 0b0100; // SDO2
	//RPB8Rbits.RPB8R = 0b0101; // OC2

        //Laser
	////// RB9 - Pin 18
	////INPUTS: SDA1, INT1, T5CK, IC2, SS2, OCFA
	//INT1Rbits.INT1R = 0b0100;
	//T5CKRbits.T5CKR = 0b0100;
	//IC2Rbits.IC2R = 0b0100;
	//SS2Rbits.SS2R = 0b0100;
	//OCFARbits.OCFAR = 0b0100;
	////OUTPUTS: NC, U1RTS, U2TX, SS2, OC3, C1OUT
	//RPB9Rbits.RPB9R = 0b0000; // NC
	//RPB9Rbits.RPB9R = 0b0001; // U1RTS
	//RPB9Rbits.RPB9R = 0b0010; // U2TX
	//RPB9Rbits.RPB9R = 0b0100; // SS2
	//RPB9Rbits.RPB9R = 0b0101; // OC3
	//RPB9Rbits.RPB9R = 0b0111; // C1OUT

        //Empty
	////// RB10 - Pin 21
	////INPUTS: INT1, T5CK, IC2, SS2, OCFA
	//INT1Rbits.INT1R = 0b0011;
	//T5CKRbits.T5CKR = 0b0011;
	//IC2Rbits.IC2R = 0b0011;
	//SS2Rbits.SS2R = 0b0011;
	//OCFARbits.OCFAR = 0b0011;
	////OUTPUTS: NC, U1RTS, U2TX, SS2, OC3, C1OUT
	//RPB10Rbits.RPB10R = 0b0000; // NC
	//RPB10Rbits.RPB10R = 0b0001; // U1RTS
	//RPB10Rbits.RPB10R = 0b0010; // U2TX
	//RPB10Rbits.RPB10R = 0b0100; // SS2
	//RPB10Rbits.RPB10R = 0b0101; // OC3
	//RPB10Rbits.RPB10R = 0b0111; // C1OUT

        //Set to digital output
	////// RB11 - Pin 22
	////INPUTS: INT3, T3CK, IC3, U1CTSR, U2RX, SDI1
	//                                              ->INT3Rbits.INT3R = 0b0011;
	//T3CKRbits.T3CKR = 0b0011;
	//IC3Rbits.IC3R = 0b0011;
	//U1CTSRbits.U1CTSR = 0b0011;
	//U2RXRbits.U2RXR = 0b0011;
	//SDI1Rbits.SDI1R = 0b0011;
	////OUTPUTS: NC, SDO1, SDO2, OC2
	//RPB11Rbits.RPB11R = 0b0000; // NC
	//RPB11Rbits.RPB11R = 0b0011; // SDO1
	//RPB11Rbits.RPB11R = 0b0100; // SDO2
	//RPB11Rbits.RPB11R = 0b0101; // OC2

        //Set to digital output
	////// RB12 - Pin 23
	////INPUTS: AN12
	////ANSELBbits.ANSB12; // this doesn't seem to exist, but is labeled on the spec sheet
	////OUTPUTS:

	////// RB13 - Pin 24
	////INPUTS: AN11, INT2, T4CK, IC1, IC5, U1RX, U2CTS, SDI2, OCFB
	//ANSELBbits.ANSB13 = 1;
	//INT2Rbits.INT2R = 0b0011;
	//T4CKRbits.T4CKR = 0b0011;
	//IC1Rbits.IC1R = 0b0011;
	//IC5Rbits.IC5R = 0b0011;
	//U1RXRbits.U1RXR = 0b0011;
	//U2CTSRbits.U2CTSR = 0b0011;
	//SDI2Rbits.SDI2R = 0b0011;
	//OCFBRbits.OCFBR = 0b0011;
	////OUTPUTS: NC, SDO1, SDO2, OC4, OC5, REFCLKO
	//RPB13Rbits.RPB13R = 0b0000; // NC
	//RPB13Rbits.RPB13R = 0b0011; // SDO1
	//RPB13Rbits.RPB13R = 0b0100; // SDO2
	//RPB13Rbits.RPB13R = 0b0101; // OC4
	//RPB13Rbits.RPB13R = 0b0110; // OC5
	//RPB13Rbits.RPB13R = 0b0111; // REFCLKO

	////// RB14 - Pin 25
	////INPUTS: AN10, SCK1, INT1, T5CK, IC2, SS2, OCFA
	//ANSELBbits.ANSB14 = 1;
	//INT1Rbits.INT1R = 0b0001;
	//T5CKRbits.T5CKR = 0b0001;
	//IC2Rbits.IC2R = 0b0001;
	//SS2Rbits.SS2R = 0b0001;
	//OCFARbits.OCFAR = 0b0001;
	////OUTPUTS: NC, U1RTS, U2TX, SS2, OC3, C1OUT
	//RPB14Rbits.RPB14R = 0b0000; // NC
	//RPB14Rbits.RPB14R = 0b0001; // U1RTS
	//RPB14Rbits.RPB14R = 0b0010; // U2TX
	//RPB14Rbits.RPB14R = 0b0100; // SS2
	//RPB14Rbits.RPB14R = 0b0101; // OC3
	//RPB14Rbits.RPB14R = 0b0111; // C1OUT

        //Empty
	////// RB15 - Pin 26
	////INPUTS: AN9, SCK2, INT4, T2CK, IC4, SS1, REFCLKI
	//ANSELBbits.ANSB15 = 1;
	//SCK2
	//INT4Rbits.INT4R = 0b0011;
	//T2CKRbits.T2CKR = 0b0011;
	//IC4Rbits.IC4R = 0b0011;
	//SS1Rbits.SS1R = 0b0011;
	//REFCLKIRbits.REFCLKIR = 0b0011;
	////OUTPUTS: NC, U1TX, U2RTS, SS1, OC1, C2OUT
	//RPB15Rbits.RPB15R	= 0b0000; // NC
	//RPB15Rbits.RPB15R = 0b0001; // U1TX
	//RPB15Rbits.RPB15R = 0b0010; // U2RTS
	//RPB15Rbits.RPB15R = 0b0011; // SS1
	//RPB15Rbits.RPB15R = 0b0101; // OC1
	//RPB15Rbits.RPB15R = 0b0111; // C2OUT
}
