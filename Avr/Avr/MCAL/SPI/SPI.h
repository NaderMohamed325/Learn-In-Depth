/*
 * SPI.h
 *
 * Created: 7/9/2024 3:06:49 PM
 *  Author: xcite
 */ 

#ifndef SPI_H_
#define SPI_H_
#include "../gpio/gpio.h"



void SPI_MasterInit(void);

unsigned char SPI_MasterTransmit(unsigned char cData);


void SPI_SlaveInit(void);

unsigned char SPI_SlaveRecieve(unsigned char cData);


#endif /* SPI_H_ */
