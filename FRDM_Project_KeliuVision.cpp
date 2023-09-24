#include "MKL25Z4.h"

#define PIR_PIN 4   // PTA4

void PIR_Init()
{
    SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;  // enable clock for PORTA
    PORTA->PCR[PIR_PIN] = PORT_PCR_MUX(1) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;  // set pin as input with pull-up resistor
}

void delay(int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < 1000; j++) {
        }
    }
}

void LED_init(void)
{
    SIM->SCGC5 |= 0x1400; /* enable clock to Port B and port D */
    PORTB->PCR[18] = 0x100;//set as GPIO pin/
    PTB->PDDR |= 0x40000;//selecting 18th pin as output/
    PTB->PSOR = 0x40000;//turns red LED off/
    PORTB->PCR[19] = 0x100;//set as GPIO pin/
    PTB->PDDR |= 0x80000;//selecting 19th pin as output/
    PTB->PSOR = 0x80000;//turns green LED off/
    PORTD->PCR[1] = 0x100;//set as GPIO pin/
    PTD->PDDR |= 0x2;//selecting 2nd pin as output/
    PTD->PSOR = 0x2;//turns blue LED off/
}

void UART0_init(void) {
    SIM->SCGC4 |= 0x0400;     // Enable clock for UART0
    SIM->SOPT2 |= 0x04000000; // Select clock source for UART0
    UART0->C2 = 0;            // Disable transmitter and receiver
    UART0->BDH = 0x00;        // Set baud rate as 0x0018
    UART0->BDL = 0x18;
    UART0->C4 = 0x0F;         // Set oversampling ratio as 16
    UART0->C1 = 0x00;         // Set desired settings in C1(control register)
    UART0->C2 = 0x08;         // Enable transmitter
    SIM->SCGC5 |= 0x0200;     // Enable clock in Port A
    PORTA->PCR[2] = 0x0200;   // Select MUX control for UART
}


int main()
{
		int motionDetected=0 ;
    PIR_Init();
    LED_init();
		UART0_init();
    while(1)
    {
        motionDetected = (PTA->PDIR & (1<<PIR_PIN)) >> PIR_PIN;
        if (motionDetected == 1)
        {
            PTB->PSOR = 0x80000;//turns green LED off/
						PTD->PSOR = 0x2;//turns blue LED off/
						PTB->PCOR = 0x40000;//turns red LED on/
						
						while (!(UART0->S1 & 0x80)) {
						}
  
						UART0->D = 'Y';
  
						while (!(UART0->S1 & 0x40)) {
						}
						delay(1);
						
				}
				else
				{
						PTB->PSOR = 0x40000;//turns red LED off/
						PTD->PSOR = 0x2;//turns blue LED off/
						PTB->PCOR = 0x80000;//turns green LED on/
					
					
				}
    }
}
