/*
* Avr.c
*
* Created: 6/26/2024 10:12:08 PM
* Author : Nader
*/

#include "MCAL/Interrupt/Interrupt.h"
#include "MCAL/UART/Uart.h"
#include "MCAL/Timer/Timer.h"

Pin_config_t P;
Pin_config_t A1;
void Fun(void);
int main(void) {

	ExtInterrupt_Init(EXT_INT0,RISING_EDGE);
	ExtInterrupt_Enable(EXT_INT0);

	P.direction=Input;
	P.logic=Low;
	P.pin=2;
	P.port=D;
	
	
	A1.direction=Output;
	A1.logic=High;
	A1.pin=2;
	A1.port=C;
	Pin_logic_init(&A1);
	ExtInterrupt_SetCallback(EXT_INT0,Fun);
	// Main loop
	while (1) {
		
	}

	return 0;
}

void Fun(void){
	Pin_Toggle(&A1);
}
