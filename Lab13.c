// Lab13.c
// Runs on LM4F120 or TM4C123
// Use SysTick interrupts to implement a 4-key digital piano
// edX Lab 13 
// Daniel Valvano, Jonathan Valvano
// December 29, 2014
// Port B bits 3-0 have the 4-bit DAC
// Port E bits 3-0 have 4 piano keys

#include "..//tm4c123gh6pm.h"
#include "Sound.h"
#include "Piano.h"
#include "TExaS.h"

#define numInputs 4

//Calculated frequencies for 523.251, 587.330, 659.255, 783.991
//(assuming 16MHz Systick Clock) MATH: (1/Frequency)/(1/5000000)-1 = Period
// unsigned long periodTable [numInputs] = { 9556,8513,7584,6378};	

//(assuming 16MHz Systick Clock) MATH: (Period = 80000000/32/Freq=2500000/Freq
unsigned long periodTable [numInputs] = { 4778,4257,3792,3189};	

unsigned long oldPianoInput;
// basic functions defined at end of startup.s
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
void delay(unsigned long msec);
int main(void){ // Real Lab13 
	// for the real board grader to work 
	// you must connect PD3 to your DAC output
//  TExaS_Init(SW_PIN_PA5432, DAC_PIN_PB3210,ScopeOn); // activate grader and set system clock to 80 MHz
			TExaS_Init(SW_PIN_PE3210, DAC_PIN_PB3210,ScopeOn); // activate grader and set system clock to 80 MHz

// PortE used for piano keys, PortB used for DAC        
  Sound_Init(); // initialize SysTick timer and DAC
  Piano_Init(); //initialize Piano key interrupts
  EnableInterrupts();  // enable after all initialization are done
  while(1){                
// input from keys to select tone
		if (oldPianoInput == Piano_In())
		{
			switch (oldPianoInput)
			{
				//case 0x04: //PA2
				case 0x01: //PE0
				{
					Sound_Tone(periodTable[0]);
					break;
				}
				//case 0x08:	//PA3
				case 0x02:	//PE1
				{
					Sound_Tone(periodTable[1]);
					break;
				}				
				//case 0x10:	//PA4
				case 0x04: //PE2
				{
					Sound_Tone(periodTable[2]);
					break;
				}					
				//case 0x20:	//PA5
				case 0x08:	//PE3
				{
					Sound_Tone(periodTable[3]);
					break;
				}										
				default:
				{
					Sound_Off();
				}
			}
		}		
		oldPianoInput = Piano_In();
		delay (10);
	}

            
}

// Inputs: Number of msec to delay
// Outputs: None
void delay(unsigned long msec){ 
  unsigned long count;
  while(msec > 0 ) {  // repeat while there are still delay
    count = 16000;    // about 1ms
    while (count > 0) { 
      count--;
    } // This while loop takes approximately 3 cycles
    msec--;
  }
}


