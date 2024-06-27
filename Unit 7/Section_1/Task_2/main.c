/*
* Avr.c
*
* Created: 6/26/2024 10:12:08 PM
* Author : Nader
*/

#include "Memory_Map.h"
#include "Utils.h"
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{
	
	DDRA=0B11111111;
	CLEAR_BIT(DDRC,0);
	int status=READ_BIT(PINC,0);

	int i=0;
	while (1)
	{
		status=READ_BIT(PINC,0);
		if(status){
			SET_BIT(PORTA,i++);
		
		}
		_delay_ms(100);
		
	}
	
}

