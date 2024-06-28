/*
* Avr.c
*
* Created: 6/26/2024 10:12:08 PM
* Author : Nader
*/


#include "MCAL/gpio/gpio.h"
#include "avr/builtins.h"
#define F_CPU 8000000UL


//char port;               /**< Port of the pin (A, B, C, D) */
//char pin;                /**< Pin number */
//Direction_t direction;   /**< Direction of the pin (Input, Output) */
//Logic_t logic;
/*
* delay.c
*
* Created: 6/28/2024 6:13:21 PM
*  Author: Nader
*/


int main(void)
{
	Pin_config_t p={
		.direction = Output,
		.port=A,
		.pin=0,
		.logic=High
	};
	Pin_logic_init(&p);
	while (1)
	{
		
		
	}
	
}

