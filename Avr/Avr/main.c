/*
* Avr.c
*
* Created: 6/26/2024 10:12:08 PM
* Author : Nader
*/


#include "ECU/Lcd/lcd.h"
#include "MCAL/UART/Uart.h"




int main(void)
{
    // Initialize UART
    UART_Init();
    _delay_ms(1001);
    // Send a string over UART
    const char *str = "Hello, UART!\n";
    while (*str) {
        UART_Send(*str++);
    }
    
    // Receive data and echo it back
    while (1) {
        unsigned char received_data = UART_Receive();
        UART_Send(received_data);
    }

    return 0;
}
