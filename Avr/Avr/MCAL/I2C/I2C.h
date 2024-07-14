#ifndef I2C_DRIVER_H_
#define I2C_DRIVER_H_

#include "../gpio/gpio.h"

// Master functions
void I2C_MasterInit(unsigned long sclClock); // Initialize I2C in master mode
void I2C_Start(void);                        // Generate start condition
void I2C_Stop(void);                         // Generate stop condition
void I2C_Write(uint8_t data);                // Write data to I2C bus
uint8_t I2C_ReadAck(void);                   // Read data with ACK
uint8_t I2C_ReadNack(void);                  // Read data with NACK
uint8_t I2C_GetStatus(void);                 // Get I2C status

// Slave functions
void I2C_SlaveInit(uint8_t slaveAddress);    // Initialize I2C in slave mode
void I2C_SlaveListen(void);                  // Listen for incoming requests
uint8_t I2C_SlaveReceive(void);              // Receive data from I2C bus
void I2C_SlaveTransmit(uint8_t data);        // Transmit data over I2C bus

#endif /* I2C_DRIVER_H_ */
