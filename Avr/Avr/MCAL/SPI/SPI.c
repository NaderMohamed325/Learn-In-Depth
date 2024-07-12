/*
 * SPI.c
 *
 * Created: 7/9/2024 3:06:49 PM
 *  Author: xcite
 */ 

#include "SPI.h"

#define MOSI 5
#define MISO 6
#define SCK  7
#define SS   4
#define Master_SPI 1
#define Slave_SPI 1
void SPI_MasterInit(void)
{
	/* Set MOSI, SCK and SS output, all others input */
	DDRB |= (1<<MOSI)|(1<<SCK)|(1<<SS);
	/* Set MISO input */
	DDRB &= ~(1<<MISO);
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}
unsigned char SPI_MasterTransmit(unsigned char cData)
{
	/* Start transmission */
	SPDR = cData;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)));
	return SPDR; 
}

void SPI_SlaveInit(void)
{
	/* Set MISO output */
	DDRB |= (1<<MISO);
	/* Set MOSI, SCK and SS input*/
	DDRB &= ~(1<<MOSI) & ~(1<<SCK) & ~(1<<SS);
	/* Enable SPI, Slave, set clock rate fck/16 */
	SPCR = (1<<SPE);
}
unsigned char SPI_SlaveRecieve(unsigned char cData)
{
	/* Start transmission */
	SPDR = cData;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)));
	return SPDR;
}
