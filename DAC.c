// DAC.c
// Runs on LM4F120 or TM4C123, 
// edX lab 13 
// Implementation of the 4-bit digital to analog converter
// Daniel Valvano, Jonathan Valvano
// December 29, 2014
// Port B bits 3-0 have the 4-bit DAC

#include "DAC.h"
#include "..//tm4c123gh6pm.h"



// **************DAC_Init*********************
// Initialize 4-bit DAC 
// Input: none
// Output: none
void DAC_Init(void){
	unsigned long volatile delay;
	
	//Port B 3-0
  SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOB; // activate port B
  delay = SYSCTL_RCGC2_R;    // allow time to finish activating
  GPIO_PORTB_AMSEL_R &= ~0x1F;      // no analog
  //GPIO_PORTB_PCTL_R &= ~0x00000FFF; // regular GPIO function
	GPIO_PORTB_PCTL_R &= 0x00000000; // regular GPIO function
  GPIO_PORTB_DIR_R |= 0x1F;      // make PB3-0 out
	GPIO_PORTB_DR8R_R |= 0x1F;    // can drive up to 8mA out
  GPIO_PORTB_AFSEL_R &= ~0x1F;   // disable alt funct on PB3-0
  GPIO_PORTB_DEN_R |= 0x1F;      // enable digital I/O on PB3-0

	//Port B 4-1
	/*
  SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOB; // activate port B
  delay = SYSCTL_RCGC2_R;    // allow time to finish activating
  GPIO_PORTB_AMSEL_R &= ~0x1F;      // no analog
  //GPIO_PORTB_PCTL_R &= ~0x00000FFF; // regular GPIO function
	GPIO_PORTB_PCTL_R &= 0x00000000; // regular GPIO function
  GPIO_PORTB_DIR_R |= 0x1F;      // make PB3-0 out
	GPIO_PORTB_DR8R_R |= 0x1F;    // can drive up to 8mA out
  GPIO_PORTB_AFSEL_R &= ~0x1F;   // disable alt funct on PB3-0
  GPIO_PORTB_DEN_R |= 0x1F;      // enable digital I/O on PB3-0
*/
	
	
	//Port A 5-2
	
	/*SYSCTL_RCGC2_R |= 0x00000001;     // 1) A clock 
	delay = SYSCTL_RCGC2_R;           // delay   
	GPIO_PORTA_LOCK_R = 0x4C4F434B;   // 2) unlock PortA PA0  
	GPIO_PORTA_CR_R = 0x3C;           // allow changes to PA5-2       
	GPIO_PORTA_AMSEL_R &= ~0x3C;      // no analog
	GPIO_PORTA_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
	GPIO_PORTA_DIR_R = 0x3C;          // 5) PA3-PA2 input
	GPIO_PORTA_DR8R_R |= 0x3C;    // can drive up to 8mA out
	GPIO_PORTA_AFSEL_R = ~0x3C;        // 6) no alternate function
	GPIO_PORTA_PUR_R = 0x00;          // enable pullup resistors on PA5-PA2       
	GPIO_PORTA_DEN_R = 0x3C;          // 7) enable digital pins PA5-PA2 
	*/

}


// **************DAC_Out*********************
// output to DAC
// Input: 4-bit data, 0 to 15 
// Output: none
unsigned long TestData;
void DAC_Out(unsigned long data){
  GPIO_PORTB_DATA_R = data;  //DAC on Port B3-0 
	TestData = data;
	
	//data = data * 2;	//DAC on Port B4-1
	//GPIO_PORTB_DATA_R = data;  //DAC on Port B4-1 
	
	//data = data * 4;  	//DAC on Port A5-A2
	//GPIO_PORTA_DATA_R = data;  	//DAC on Port A5-A2
}
