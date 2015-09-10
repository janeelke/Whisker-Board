#include <p32xxxx.h>
#include <plib.h>
#include "PIC32MX250pins.h"
#include "SPIcontrol.h"
#include "ADCcontrol.h"
#include <xc.h>



// DEVCFG3:
#pragma config IOL1WAY  = OFF       // Peripheral Pin Select Configuration, allow mult reconfig
#pragma config PMDL1WAY = OFF		// Peripheral Module Disable Config, allow mult reconfig
// DEVCFG2:
#pragma config FPLLODIV = DIV_2     // PLL Output Divider
#pragma config FPLLMUL  = MUL_20    // PLL Multiplier
#pragma config FPLLIDIV = DIV_2     // PLL Input Divider
// 8MHz / 2 * 20 / 2 = 40MHz
// DEVCFG1:
#pragma config FWDTEN   = OFF       // Watchdog Timer
#pragma config WDTPS    = PS1       // Watchdog Timer Postscale
#pragma config FCKSM    = CSDCMD    // Clock Switching & Fail Safe Clock Monitor
#pragma config FPBDIV   = DIV_1     // Peripheral Clock divisor
#pragma config OSCIOFNC = OFF       // CLKO Enable
#pragma config POSCMOD  = OFF       // Primary Oscillator
#pragma config IESO     = OFF       // Internal/External Switch-over
#pragma config FSOSCEN  = OFF       // Secondary Oscillator Enable (KLO was off)
#pragma config FNOSC    = FRCPLL    // Oscillator Selection
// DEVCFG0:
#pragma config CP       = OFF       // Code Protect
#pragma config BWP      = ON        // Boot Flash Write Protect
#pragma config PWP      = OFF       // Program Flash Write Protect
#pragma config ICESEL   = ICS_PGx1  // ICE/ICD Comm Channel Select
#pragma config JTAGEN   = OFF       // JTAG Enable
#pragma config DEBUG    = ON      // Background Debugger Enable

#define SYS_FREQ 40000000L

//for ADC
#define VOLTS_PER_COUNT (3.3/1024)
#define CORE_TICK_TIME 25

#define DELAY_TICKS 20000000

//unsigned char spi_io(unsigned char o, unsigned char ps);

/*void __ISR(_EXTERNAL_1_VECTOR, IPL5SOFT) Ext1ISR(void) { //interrput 1 stops OC1 by pin 10
   INTDisableInterrupts();
   OC1RS = 0;
   while(1){//!PORTAbits.RA2){
        //Do nothing until RA2 (pin 9) is hit
   }
   OC1RS = 199;
   IFS0bits.INT1IF = 0;
   INTEnableInterrupts();
}

void __ISR(_EXTERNAL_2_VECTOR, IPL5SOFT) Ext2ISR(void) { //interrput 1 stops OC2 by pin 9
   INTDisableInterrupts();
   OC1RS = 0;
   while(1){//!PORTAbits.RA3){
        //Do nothing until RA3 (pin 10) is hit
   }
   OC1RS = 199;
   IFS0bits.INT2IF = 0;
   INTEnableInterrupts();
}

void __ISR(_EXTERNAL_3_VECTOR, IPL5SOFT) Ext3ISR(void) { //interrput 1 stops OC1 by pin 10
   INTDisableInterrupts();
   OC1RS = 0;
   while(1){//!PORTAbits.RA2){
        //Do nothing until RA3 (pin 9) is hit
   }
   OC1RS = 199;
   IFS0bits.INT3IF = 0;
   INTEnableInterrupts();
}

void __ISR(_EXTERNAL_4_VECTOR, IPL5SOFT) Ext4ISR(void) { //interrput 1 stops OC1 by pin 10
   INTDisableInterrupts();
   OC1RS = 0;
   while(1){//!PORTAbits.RA2){
        //Do nothing until RA3 (pin 9) is hit
   }
   OC1RS = 199;
   IFS0bits.INT4IF = 0;
   INTEnableInterrupts();
}*/

int main(void) {
  CFGCONbits.JTAGEN = 0; // turn off JTAG, get back those pins for IO use

  SYSTEMConfigPerformance(SYS_FREQ);
  INTDisableInterrupts();
  
  PIC32MX250_setup_pins();
  
  //Setup SPI1
  SPI1CON = 0;              // turn off the spi module and reset it
  SPI1BUF;                  // clear the rx buffer by reading from it
  SPI1BRG = 0x3;            // baud rate to 5MHz [SPI1BRG = (40000000/(2*desired))-1]
  SPI1STATbits.SPIROV = 0;  // clear the overflow bit
  SPI1CONbits.CKE = 1;      // data changes when clock goes from active to inactive
                            //    (high to low since CKP is 0)
  SPI1CONbits.MSTEN = 1;    // master operation
  SPI1CONbits.ON = 1;       // turn on spi
  
  TRISBbits.TRISB7=0;   //set pins as outputs--0=output
  TRISAbits.TRISA4=0;
  TRISAbits.TRISA3=0;
   
  TRISAbits.TRISA2=1; //make RA2 an input to trigger ADC collecting
   
  LATBbits.LATB7=0;  //make this pin go low
  
  //Initialize pin values
  LATAbits.LATA3=1; //make this pin be 3.3v
  LATAbits.LATA4=1; 
  
  unsigned int sample=0;
  while(1){
      if (PORTAbits.RA2){
          //if pin 9 goes high, read from the adc
          sample=adc_grab(1);
      }
  }
  //unsigned char setValue=127, goldenValue=127;
  //int zeroValue, collect;
  //int count=0, jj=0;
  
  //spi_io(1,74);
  //zeroValue=adc_grab(i);
  /*zeroValue=479;
  //zeroValue= (int) 1.45/3.3*1024;
  spi_io(1,setValue);
  collect = adc_grab(i);
  int minDiff = abs(collect-zeroValue);
  while(count<128){
      if(abs(collect-zeroValue)<= minDiff){
          minDiff = abs(collect- zeroValue);
          goldenValue=setValue;
      }
      if(collect>zeroValue){
          setValue++;
      }
      else if(collect<zeroValue){
          setValue--;
      }
      while(jj<10000){
          jj++;
      }
      jj=0;
      spi_io(1,setValue);
      collect = adc_grab(i);
      count++;   
  }
  spi_io(1,goldenValue);*/
  
  //if(count>=128){
  //    LATAbits.LATA4=1;
  //}
  //sample2=(unsigned char) (adc_grab(i)/4);
  
  //spi_io(1,sample2);
  
  //while(1){
      //LATBbits.LATB7=1;
      /*//LATAbits.LATA3=0;
      
      spi_io(1,125);
      //spi_io(240,0b00010010,2);
      //spi_io(200);
      //LATAbits.LATA3=1;
      for(i=0;i<100000;i++){
      Nop();
      }*/
  //}
  return 0;
}

