/*
* Avr.c
*
* Created: 6/26/2024 10:12:08 PM
* Author : Nader
*/


#include "ECU/Lcd/lcd.h"
#include "MCAL/UART/Uart.h"
#include "MCAL/I2C/I2C.h"

int main(){
uint8_t data;

I2C_MasterInit(100000); // Initialize I2C as master with SCL frequency of 100kHz

I2C_Start(); // Start I2C communication
I2C_Write(0xA0); // Write address with write bit

I2C_Write(0x00); // Write data

I2C_Stop(); // Stop I2C communication

I2C_Start(); // Start I2C communication to read
I2C_Write(0xA1); // Write address with read bit

data = I2C_ReadAck(); // Read data with ACK

data = I2C_ReadNack(); // Read data with NACK

I2C_Stop(); // Stop I2C communication

while (1) {
	// Main loop
}
}