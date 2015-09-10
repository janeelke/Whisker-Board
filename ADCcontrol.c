#include <plib.h>
#include "ADCcontrol.h"
#define SAMPLE_TIME 10

unsigned int adc_grab(int sample_pin) {
  unsigned int elapsed=0,finishtime=0;
  unsigned int sample;
  
  AD1CON3bits.ADCS = 2;
  AD1CON1bits.ADON = 1;
  
  
  //ANALOG INPUTS ON AN0(RA0),AN1{RA1),AN4(RB2),AN5(RB3)
  
  WriteCoreTimer(0);
  if (sample_pin<=1){
    // sample_pin is 1 or 2
    AD1CHSbits.CH0SA = sample_pin-1;
  }
  else{
    //sample_pin is 3 or 4
    AD1CHSbits.CH0SA = sample_pin+1;
  }

  AD1CON1bits.SAMP = 1; //start sampling
  elapsed = ReadCoreTimer();
  finishtime = elapsed + SAMPLE_TIME;
  while(ReadCoreTimer() < finishtime){//sample for more than 200ns
      ;
  }
  AD1CON1bits.SAMP = 0; //stop sampling and start converting
  while (!AD1CON1bits.DONE){
      ;
  }
  sample=ADC1BUF0;//read the buffer with the result
  char msg[100]={};
  sprintf(msg,"AN0: %4u (%5.3f volts)",sample,sample*(3.3/1024));
  //to check ADC values, set a breakpoint at the line below, view the variables tab
  //and look at the value for message. it says what the adc is reading in volts
  return(sample);
  //elapsed=ReadCoreTimer();
}