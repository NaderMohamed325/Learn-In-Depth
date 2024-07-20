/*
* Avr.c
*
* Created: 6/26/2024 10:12:08 PM
* Author : Nader
*/

#include "MCAL/Timer/Timer.h"

// Global pin configuration for use in ISR
Pin_config_t Pin;

// Interrupt Service Routine (ISR) for Timer0 Overflow
void my_isr(void) {
	Pin_Toggle(&Pin);
}

int main(void) {
	// Configure the pin
	Pin.port = B;
	Pin.pin = 4;
	Pin.direction = Output;
	Pin.logic = Low;
	Pin_logic_init(&Pin);

	// Configure the timer
	Timer0_t timer = {
		.Compare_Value = 255,
		.Output_Pin_Functionality = OC0_Toggle,
		.Precaller = Prescaller_1024,
		.Timer_Mode = Normal,
		.Force_Output_Pin = Enable,
		.interrupt_status = OverFlow_Interrupt,
		.Call_Back_Overflow = my_isr
	};

	// Initialize the timer
	Timer0_Init(&timer);

	while (1) {
		// Main loop
	}
}
