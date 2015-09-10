#include <plib.h>
#include "SPIcontrol.h"

unsigned char spi_io(int cs, unsigned char o) {

  //RA3 P1
  if (cs==1){
    LATAbits.LATA3 = 0;
    SPI1BUF = 0b00010010;
    while(!SPI1STATbits.SPIRBF) { // wait to receive the byte
      ;
    }
    SPI1BUF = o;
    while(!SPI1STATbits.SPIRBF) {
        ;
    }
    while(SPI1STATbits.SPIBUSY==1){
        ;
    }
    LATAbits.LATA3 = 1;
  }

  //RA3 P0
  if (cs==2){
    LATAbits.LATA3 = 0;
    SPI1BUF = 0b00010001;
    while(!SPI1STATbits.SPIRBF) { // wait to receive the byte
      ;
    }
    SPI1BUF = o;
    while(!SPI1STATbits.SPIRBF) {
        ;
    }
    while(SPI1STATbits.SPIBUSY==1){
        ;
    }
    LATAbits.LATA3 = 1;
  }

  //RA2 P1
  if (cs==3){
    LATAbits.LATA2 = 0;
    SPI1BUF = 0b00010010;
    while(!SPI1STATbits.SPIRBF) { // wait to receive the byte
      ;
    }
    SPI1BUF = o;
    while(!SPI1STATbits.SPIRBF) {
        ;
    }
    while(SPI1STATbits.SPIBUSY==1){
        ;
    }
    LATAbits.LATA2 = 1;
  }

  //RA2 P0
  if (cs==4){
    LATAbits.LATA2 = 0;
    SPI1BUF = 0b00010001;
    while(!SPI1STATbits.SPIRBF) { // wait to receive the byte
      ;
    }
    SPI1BUF = o;
    while(!SPI1STATbits.SPIRBF) {
        ;
    }
    while(SPI1STATbits.SPIBUSY==1){
        ;
    }
    LATAbits.LATA2 = 1;
  }
/*  SPI1BUF = ps;
  while(!SPI1STATbits.SPIRBF) { // wait to receive the byte
    ;
  }
  SPI1BUF = o;
  while(!SPI1STATbits.SPIRBF) {
      ;
  }
  while(SPI1STATbits.SPIBUSY==1){
      ;
  }*/
  //return SPI1BUF;
}