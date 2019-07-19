// Piano.c
// Runs on LM4F120 or TM4C123, 
// edX lab 13 
// There are four keys in the piano
// Daniel Valvano
// December 29, 2014

// Port E bits 3-0 have 4 piano keys

// Port A bits 5-2 have 4 piano keys

#include "Piano.h"
#include "..//tm4c123gh6pm.h"


// **************Piano_Init*********************
// Initialize piano key inputs
// Input: none
// Output: none
void Piano_Init(void){ 
		volatile unsigned long delay;
		SYSCTL_RCGC2_R |= 0x00000010;     // 1) E clock 
		delay = SYSCTL_RCGC2_R;           // delay   
		GPIO_PORTE_LOCK_R = 0x4C4F434B;   // 2) unlock PortE PE0  
		GPIO_PORTE_CR_R = 0x0F;           // allow changes to PE3-0       
		GPIO_PORTE_AMSEL_R = 0x00;        // 3) disable analog function
		GPIO_PORTE_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
		GPIO_PORTE_DIR_R = 0x00;          // 5) PE3-PE0 input
		GPIO_PORTE_AFSEL_R = 0x00;        // 6) no alternate function
		GPIO_PORTE_PUR_R = 0x00;          // enable pullup resistors on PE3-PE0       
		GPIO_PORTE_DEN_R = 0x0F;          // 7) enable digital pins PE3-PE0  	
	
	
/*		SYSCTL_RCGC2_R |= 0x00000001;     // 1) A clock 
		delay = SYSCTL_RCGC2_R;           // delay   
		GPIO_PORTA_LOCK_R = 0x4C4F434B;   // 2) unlock PortA PA0  
		GPIO_PORTA_CR_R = 0x3C;           // allow changes to PA5-2       
		GPIO_PORTA_AFSEL_R &= ~0x3C;  		// disable alt funct on PA5-PA2
		GPIO_PORTA_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
		GPIO_PORTA_DIR_R = 0x00;          // 5) PA3-PA2 input
		GPIO_PORTA_AFSEL_R = 0x00;        // 6) no alternate function
		GPIO_PORTA_PUR_R = 0x00;          // enable pullup resistors on PA5-PA2       
		GPIO_PORTA_DEN_R = 0x3C;          // 7) enable digital pins PA5-PA2  	
  */
}
// **************Piano_In*********************
// Input from piano key inputs
// Input: none 
// Output: 0 to 15 depending on keys
// 0x01 is key 0 pressed, 0x02 is key 1 pressed,
// 0x04 is key 2 pressed, 0x08 is key 3 pressed
unsigned long Piano_In(void){
  
	return GPIO_PORTE_DATA_R;	//Input keys on PE3-0
	//return GPIO_PORTA_DATA_R;	//Input keys on PE5-2
  //return 0; // remove this, replace with input
}
