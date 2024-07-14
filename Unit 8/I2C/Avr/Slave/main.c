/*
* Avr.c
*
* Created: 6/26/2024 10:12:08 PM
* Author : Nader
*/


#include "ECU/Lcd/lcd.h"
#include "MCAL/UART/Uart.h"
#include "MCAL/I2C/I2C.h"

int main(void) {
	uint8_t receivedData;

	I2C_SlaveInit(0x10); // Initialize I2C as slave with address 0x10

	while (1) {
		I2C_SlaveListen(); // Listen for I2C requests

		receivedData = I2C_SlaveReceive(); // Receive data from master

		I2C_SlaveTransmit(receivedData + 1); // Transmit processed data back to master
	}
}