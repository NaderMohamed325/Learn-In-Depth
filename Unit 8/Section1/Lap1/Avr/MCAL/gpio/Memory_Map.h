/*
 * Memory_Map.h
 *
 * Created: 6/26/2024 10:14:08 PM
 *  Author: Nader
 */ 


#ifndef MEMORY_MAP_H_
#define MEMORY_MAP_H_

#define PORTA *((volatile unsigned char *)0x3B)
#define DDRA  *((volatile unsigned char *)0x3A)
#define PINA  *((volatile unsigned char *)0x39)

#define PORTB *((volatile unsigned char *)0x38)
#define DDRB  *((volatile unsigned char *)0x37)
#define PINB  *((volatile unsigned char *)0x36)

#define PORTC *((volatile unsigned char *)0x35)
#define DDRC  *((volatile unsigned char *)0x34)
#define PINC  *((volatile unsigned char *)0x33)

#define PORTD *((volatile unsigned char *)0x32)
#define DDRD  *((volatile unsigned char *)0x31)
#define PIND  *((volatile unsigned char *)0x30)


// UART Registers
#define UDR   *((volatile unsigned char *)0x2C)  // USART I/O Data Register
#define UCSRA *((volatile unsigned char *)0x2B)  // USART Control and Status Register A
#define UCSRB *((volatile unsigned char *)0x2A)  // USART Control and Status Register B
#define UCSRC *((volatile unsigned char *)0x40)  // USART Control and Status Register C
#define UBRRL *((volatile unsigned char *)0x29)  // USART Baud Rate Register Low
#define UBRRH *((volatile unsigned char *)0x40)  // USART Baud Rate Register High


// Bit definitions for UCSRA
#define RXC   7  // USART Receive Complete
#define TXC   6  // USART Transmit Complete
#define UDRE  5  // USART Data Register Empty
#define FE    4  // Frame Error
#define DOR   3  // Data OverRun
#define PE    2  // Parity Error
#define U2X   1  // Double the USART Transmission Speed
#define MPCM  0  // Multi-processor Communication Mode

// Bit definitions for UCSRB
#define RXCIE  7  // RX Complete Interrupt Enable
#define TXCIE  6  // TX Complete Interrupt Enable
#define UDRIE  5  // USART Data Register Empty Interrupt Enable
#define RXEN   4  // Receiver Enable
#define TXEN   3  // Transmitter Enable
#define UCSZ2  2  // Character Size
#define RXB8   1  // Receive Data Bit 8
#define TXB8   0  // Transmit Data Bit 8

// Bit definitions for UCSRC
#define URSEL  7  // Register Select
#define UMSEL  6  // USART Mode Select
#define UPM1   5  // Parity Mode
#define UPM0   4  // Parity Mode
#define USBS   3  // Stop Bit Select
#define UCSZ1  2  // Character Size
#define UCSZ0  1  // Character Size
#define UCPOL  0  // Clock Polarity



#endif /* MEMORY_MAP_H_ */