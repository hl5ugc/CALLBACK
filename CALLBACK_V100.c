/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
� Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 2022-12-12
Author  : 
Company : 
Comments: 


Chip type               : ATmega2560
Program type            : Application
AVR Core Clock frequency: 16.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 2048
*******************************************************/

#include <mega2560.h>
// Standard Input/Output functions
#include <stdio.h>
#include <delay.h>
// Declare your global variables here
#include "SIO.H"
 
// rxd data가 수신 되었을때 apevent가 실행  

unsigned char rxd0_buff[10] ;
unsigned char rxd1_buff[10] ;

 
//
void ap_Uart1_Rxd(void)
{
    char status,data;
    status=UCSR1A;
    data=UDR1;
    if ((status & (FRAMING_ERROR | PARITY_ERROR | DATA_OVERRUN))==0)
    {
        UDR1 = data  ; 
        UDR2 = data  ; 
    }
}
void ap_Uart1_Txd(void)
{
 
}
void ap_Uart2_Rxd(void)
{

    char status,data;
    status=UCSR2A;
    data=UDR2;
    if ((status & (FRAMING_ERROR | PARITY_ERROR | DATA_OVERRUN))==0)
    {
        UDR2 = data  ;  
       
    }
}
void ap_Uart2_Txd(void)
{
 
} 
 

void main(void)
{
// Declare your local variables here

    // Crystal Oscillator division factor: 1
    #pragma optsize-
    CLKPR=(1<<CLKPCE);
    CLKPR=(0<<CLKPCE) | (0<<CLKPS3) | (0<<CLKPS2) | (0<<CLKPS1) | (0<<CLKPS0);
    #ifdef _OPTIMIZE_SIZE_
    #pragma optsize+
    #endif

    System_Init();
    canSetCallback(0, ap_Uart1_Rxd); 
    canSetCallback(1, ap_Uart2_Rxd); 
    canSetCallback(2, ap_Uart1_Txd); 
    canSetCallback(3, ap_Uart2_Txd); 
    // Global enable interrupts
    #asm("sei")
     
    while (1)
    {
        // Place your code here
        delay_ms(500) ;
 
    }
}
