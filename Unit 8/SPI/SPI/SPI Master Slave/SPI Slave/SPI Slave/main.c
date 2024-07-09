/*
 * SPI Slave.c
 *
 * Created: 6/30/2021 12:50:18 PM
 * Author : Marco
 */ 
#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

#define SS 4
#define MOSI 5
#define MISO 6
#define SCK 7 

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


int main(void)
{
    /* Replace with your application code */
	unsigned char ch = 255;
	DDRA = 0xFF;
	SPI_SlaveInit();
	for (ch = 255; ch >= 0; ch--)
	{
		PORTA = SPI_SlaveRecieve(ch);
	}
}

