/*
 * Memory_Map.h
 *
 * Created: 6/26/2024 10:14:08 PM
 *  Author: Nader
 */

#ifndef MEMORY_MAP_H_
#define MEMORY_MAP_H_

// GPIO Registers for PORTA
#define PORTA *((volatile unsigned char *)0x3B)
#define DDRA  *((volatile unsigned char *)0x3A)
#define PINA  *((volatile unsigned char *)0x39)

#define PA0   0
#define PA1   1
#define PA2   2
#define PA3   3
#define PA4   4
#define PA5   5
#define PA6   6
#define PA7   7

// GPIO Registers for PORTB
#define PORTB *((volatile unsigned char *)0x38)
#define DDRB  *((volatile unsigned char *)0x37)
#define PINB  *((volatile unsigned char *)0x36)

#define PB0   0
#define PB1   1
#define PB2   2
#define PB3   3
#define PB4   4
#define PB5   5
#define PB6   6
#define PB7   7

// GPIO Registers for PORTC
#define PORTC *((volatile unsigned char *)0x35)
#define DDRC  *((volatile unsigned char *)0x34)
#define PINC  *((volatile unsigned char *)0x33)

#define PC0   0
#define PC1   1
#define PC2   2
#define PC3   3
#define PC4   4
#define PC5   5
#define PC6   6
#define PC7   7

// GPIO Registers for PORTD
#define PORTD *((volatile unsigned char *)0x32)
#define DDRD  *((volatile unsigned char *)0x31)
#define PIND  *((volatile unsigned char *)0x30)

#define PD0   0
#define PD1   1
#define PD2   2
#define PD3   3
#define PD4   4
#define PD5   5
#define PD6   6
#define PD7   7

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

// SPI Registers
#define SPCR  *((volatile unsigned char *)0x2D)  // SPI Control Register
#define SPSR  *((volatile unsigned char *)0x2E)  // SPI Status Register
#define SPDR  *((volatile unsigned char *)0x2F)  // SPI Data Register

// Bit definitions for SPCR
#define SPIE  7  // SPI Interrupt Enable
#define SPE   6  // SPI Enable
#define DORD  5  // Data Order
#define MSTR  4  // Master/Slave Select
#define CPOL  3  // Clock Polarity
#define CPHA  2  // Clock Phase
#define SPR1  1  // SPI Clock Rate Select 1
#define SPR0  0  // SPI Clock Rate Select 0

// Bit definitions for SPSR
#define SPIF  7  // SPI Interrupt Flag
#define WCOL  6  // Write COLlision Flag
#define SPI2X 0  // Double SPI Speed Bit

// I2C (TWI) Registers
#define TWBR  *((volatile unsigned char *)0x20)  // TWI Bit Rate Register
#define TWSR  *((volatile unsigned char *)0x21)  // TWI Status Register
#define TWAR  *((volatile unsigned char *)0x22)  // TWI (Slave) Address Register
#define TWDR  *((volatile unsigned char *)0x23)  // TWI Data Register
#define TWCR  *((volatile unsigned char *)0x56)  // TWI Control Register
#define TWAMR *((volatile unsigned char *)0x57)  // TWI (Slave) Address Mask Register

// Bit definitions for TWSR
#define TWPS1 1  // TWI Prescaler Bits
#define TWPS0 0  // TWI Prescaler Bits

// Bit definitions for TWAR
#define TWA6 7  // TWI (Slave) Address Bit 6
#define TWA5 6  // TWI (Slave) Address Bit 5
#define TWA4 5  // TWI (Slave) Address Bit 4
#define TWA3 4  // TWI (Slave) Address Bit 3
#define TWA2 3  // TWI (Slave) Address Bit 2
#define TWA1 2  // TWI (Slave) Address Bit 1
#define TWA0 1  // TWI (Slave) Address Bit 0
#define TWGCE 0 // TWI General Call Recognition Enable

// Bit definitions for TWCR
#define TWINT  7  // TWI Interrupt Flag
#define TWEA   6  // TWI Enable Acknowledge Bit
#define TWSTA  5  // TWI Start Condition Bit
#define TWSTO  4  // TWI Stop Condition Bit
#define TWWC   3  // TWI Write Collision Flag
#define TWEN   2  // TWI Enable Bit
#define TWIE   0  // TWI Interrupt Enable

#endif /* MEMORY_MAP_H_ */
