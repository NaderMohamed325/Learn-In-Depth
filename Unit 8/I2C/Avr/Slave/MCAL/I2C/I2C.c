#include "I2C.h"

/**
 * @brief Initialize I2C (TWI) interface in master mode
 * @param sclClock The desired SCL clock frequency
 */
void I2C_MasterInit(unsigned long sclClock) {
    TWBR = (uint8_t)(((F_CPU / sclClock) - 16) / 2); // Set SCL frequency
    TWSR &= ~((1 << TWPS1) | (1 << TWPS0)); // Set prescaler bits to zero
    TWCR = (1 << TWEN); // Enable TWI
}

/**
 * @brief Generate start condition
 */
void I2C_Start(void) {
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN); // Send start condition
    while (!(TWCR & (1 << TWINT))); // Wait for TWINT flag to be set
}

/**
 * @brief Generate stop condition
 */
void I2C_Stop(void) {
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN); // Send stop condition
}

/**
 * @brief Write data to I2C bus
 * @param data The data byte to be transmitted
 */
void I2C_Write(uint8_t data) {
    TWDR = data; // Load data into TWDR register
    TWCR = (1 << TWINT) | (1 << TWEN); // Clear TWINT to start transmission
    while (!(TWCR & (1 << TWINT))); // Wait for TWINT flag to be set
}

/**
 * @brief Read data from I2C bus with ACK
 * @return The received data byte
 */
uint8_t I2C_ReadAck(void) {
    TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN); // Clear TWINT, enable ACK
    while (!(TWCR & (1 << TWINT))); // Wait for TWINT flag to be set
    return TWDR; // Return received data
}

/**
 * @brief Read data from I2C bus with NACK
 * @return The received data byte
 */
uint8_t I2C_ReadNack(void) {
    TWCR = (1 << TWINT) | (1 << TWEN); // Clear TWINT, send NACK
    while (!(TWCR & (1 << TWINT))); // Wait for TWINT flag to be set
    return TWDR; // Return received data
}

/**
 * @brief Get the current I2C status
 * @return The status code from TWSR
 */
uint8_t I2C_GetStatus(void) {
    return TWSR & 0xF8; // Mask prescaler bits to get status
}

/**
 * @brief Initialize I2C (TWI) interface in slave mode
 * @param slaveAddress The address of the slave device
 */
void I2C_SlaveInit(uint8_t slaveAddress) {
    TWAR = (slaveAddress << 1); // Set slave address (shifted left by 1)
    TWCR = (1 << TWEN) | (1 << TWEA) | (1 << TWINT); // Enable TWI, ACK, and interrupt
}

/**
 * @brief Listen for incoming I2C requests in slave mode
 */
void I2C_SlaveListen(void) {
    while (!(TWCR & (1 << TWINT))); // Wait for TWINT flag to be set
}

/**
 * @brief Receive data from I2C bus in slave mode
 * @return The received data byte
 */
uint8_t I2C_SlaveReceive(void) {
    TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN); // Clear TWINT, enable ACK
    while (!(TWCR & (1 << TWINT))); // Wait for TWINT flag to be set
    return TWDR; // Return received data
}

/**
 * @brief Transmit data over I2C bus in slave mode
 * @param data The data byte to be transmitted
 */
void I2C_SlaveTransmit(uint8_t data) {
    TWDR = data; // Load data into TWDR register
    TWCR = (1 << TWINT) | (1 << TWEN); // Clear TWINT to start transmission
    while (!(TWCR & (1 << TWINT))); // Wait for TWINT flag to be set
}
