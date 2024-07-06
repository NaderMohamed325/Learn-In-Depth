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
void UART_Send_Number(unsigned int num);
unsigned int UART_Receive_Number(void);
#endif /* UART_H_ */