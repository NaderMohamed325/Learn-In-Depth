#ifndef I2C_DRIVER_H_
#define I2C_DRIVER_H_

#include "../gpio/gpio.h"

void MCAL_I2C_Init(unsigned long SCL_Clock);
void MCAL_I2C_Start(void);
void MCAL_I2C_Write(uint8_t Byte);
void MCAL_I2C_Stop(void);


#endif /* I2C_DRIVER_H_ */
