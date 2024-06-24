/*
* main.c
*
* Created: 6/24/2024 5:37:59 PM
*  Author: xcite
*/

#define F_CPU 8000000ULL
#include <xc.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
ISR (INT0_vect){
	  PORTA ^= (1 << PA1);
	
		GICR|=(1<<INTF0);
}
int main(void)
{
	sei();
	DDRD&=~(1<<2);  //pin D2 input
	DDRA|=(1<<DDA1); //pin A1 output
	
	PORTD&=~(1<<2); //pull up resistor off  //if the pin was output 1 =5v and 0 =ground
	
	MCUCR|=(1<<ISC01);
	MCUCR&=~(1<<ISC00);
	
	GICR|=(1<<INT0);
	

	while(1)
	{
		
	}
}
