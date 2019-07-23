# utx-embedded-launchpad-lab13
UTX Embedded - Lab 13 - DAC

Purpose
This lab has these major objectives: 1) to learn about DAC conversion; 2) to understand how digital data stored in a computer could be used to represent sounds and music; 3) to study how the DAC  and interrupts can be used together to create sounds.

System Requirements
Most digital music devices rely on high-speed DACs to create the analog waveforms required to produce high-quality sound. In this lab, you will create a very simple sound generation system that illustrates this application of the DAC. Your goal is to create an embedded system that plays four notes, which will be a digital piano with four keys.

The first step is to design and test a 4-bit binary-weighted DAC, which converts 4 bits of digital output from the TM4C123 to an analog signal. You are free to design your DAC with a precision of more than 4 bits. The simulator supports up to 6 bits. You will convert the digital output signals to an analog output using a simple resistor network. During the static testing phase, you will connect the DAC analog output to the voltmeter and measure resolution, range, precision, and accuracy. During the dynamic testing phase, you will connect the DAC output to the scope to see the waveform verses time. If you connect the DAC to headphones, you will be able to hear the sounds created by your software. It doesn’t matter what range the DAC is, as long as there is an approximately linear relationship between the digital data and the speaker current.

The performance score of this lab is not based on loudness but sound quality. The quality of the music will depend on both hardware and software factors. The precision of the DAC, the external noise, and the dynamic range of the speaker are some of the hardware factors. Software factors include the DAC output rate and the number of data points stored in the sound data.

Note: You can create a 3-kΩ resistor from two 1.5-kΩ resistors. You can create a 6-kΩ resistor from two 12-kΩ resistors.

https://www.youtube.com/watch?v=o678t86HEGc
