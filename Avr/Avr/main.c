/*
* Avr.c
*
* Created: 6/26/2024 10:12:08 PM
* Author : Nader
*/

#include "Memory_Map.h"
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{
	
	DDRA=0B11111111;

	while (1)
	{
		for (int i=0;i<8;i++)
		{
			PORTA|=(1<<i);
			_delay_ms(20);
		}
		for (int i=7;i>=0;i--)
		{
			PORTA&=~(1<<i);
			_delay_ms(20);
		}
		
		
	}
	
}

