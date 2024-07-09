/*
 * SPI.h
 *
 * Created: 7/9/2024 3:06:49 PM
 *  Author: xcite
 */ 

#ifndef SPI_H_
#define SPI_H_



/**
 * @brief Initializes the SPI module as Master.
 * 
 * Sets the necessary pins as outputs for MOSI, SCK, and SS,
 * sets MISO as input, and enables SPI in Master mode with a clock rate of fck/16.
 */
void SPI_MasterInit(void);

/**
 * @brief Transmits a byte of data via SPI as Master.
 * 
 * @param cData The data byte to be transmitted.
 * @return The received data byte.
 */
unsigned char SPI_MasterTransmit(unsigned char cData);

/**
 * @brief Initializes the SPI module as Slave.
 * 
 * Sets the necessary pins as inputs for MOSI, SCK, and SS,
 * sets MISO as output, and enables SPI in Slave mode.
 */
void SPI_SlaveInit(void);

/**
 * @brief Receives a byte of data via SPI as Slave.
 * 
 * @param cData The data byte to be transmitted (typically dummy data in Slave mode).
 * @return The received data byte.
 */
unsigned char SPI_SlaveRecieve(unsigned char cData);

#endif /* SPI_H_ */
