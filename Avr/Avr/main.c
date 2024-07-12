/*
* Avr.c
*
* Created: 6/26/2024 10:12:08 PM
* Author : Nader
*/


#include "ECU/Lcd/lcd.h"
#include "MCAL/UART/Uart.h"
#include "MCAL/SPI/SPI.h"



int main(void)
{

	SPI_MasterInit();
		unsigned char p=0;
		while(1){
			SPI_MasterTransmit(p++);
			_delay_ms(500);
		}
	
	

	return 0;
}
