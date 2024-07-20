/*
* Avr.c
*
* Created: 6/26/2024 10:12:08 PM
* Author : Nader
*/

#include "MCAL/Timer/Timer.h"

int main(void) {
	// Configure the pin for PWM output
	Pin_config_t Pin;
	Pin.port = B;
	Pin.pin = 3;
	Pin.direction = Output;
	Pin.logic = Low;
	Pin_logic_init(&Pin);

	// Initialize Timer0 for PWM generation with 50% duty cycle
	Timer0_PWM_Init(128, OC0_Clear, Prescaller_64);

	while (1) {
		// Main loop
	}
}
