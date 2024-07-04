/*
 * Uart.h
 *
 * Created: 7/4/2024 11:08:45 PM
 *  Author: xcite
 */ 


#ifndef UART_H_
#define UART_H_
#include "../gpio/gpio.h"

void UART_Init(void);
void UART_Send(unsigned char data);
unsigned char UART_Receive(void);


#endif /* UART_H_ */