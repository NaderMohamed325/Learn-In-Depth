#include "uart.h"

#define UART_REG         *((volatile unsigned int*)((unsigned int*)0x101f1000))


void Uart_Send(unsigned char*message) {

	while (*message) {
		UART_REG = (unsigned int)(*message);
		message++;
	}
}
