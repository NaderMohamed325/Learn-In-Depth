/*
 * stm32f103c6_I2C_Driver.h
 *
 *  Created on: Jul 14, 2024
 *      Author: xcite
 */

#ifndef INC_STM32F103C6_I2C_DRIVER_H_
#define INC_STM32F103C6_I2C_DRIVER_H_
#include "stm32f103c6_gpio.h"
#include "stm32f013c6_RCC_Driver.h"
/*
 // The following is the required sequence in master mode.
 // Program the peripheral input clock in I2C_CR2 register in order to generate correct {@ref ClockSpeed}
 // timings
 // Configure the clock control registers
 // Configure the rise time register
 // Program the I2C_CR1 register to enable the peripheral
 // Set the START bit in the I2C_CR1 register to generate a Start condition
 // The peripheral input clock frequency must be at least:
 // 2 MHz in Sm mode
 // 4 MHz in Fm mode
 //    Supports different communication speeds:
 //    – Standard Speed (up to 100 kHz)
 //    – Fast Speed (up to 400 kHz)
 */
typedef enum
    {
    I2C_EV_STOP,
    I2C_ERROR_AF,
    I2C_EV_ADDR_Matched,
    I2C_EV_DATA_REQ, //the APP layer should send the data (I2C_SlaveSendData ) in this state
    I2C_EV_DATA_RCV //the APP layer should read the data (I2C_SlaveReceiveData ) in this state
    } Slave_State;

typedef struct
    {
	uint16_t Enable_Dual_Add;              //1- enable 0-disable
	uint16_t First_Add;
	uint16_t Secondary_Add;
	uint32_t I2C_Addressing_Mode;      ///@ref Slave_Adress_Mode
    } S_I2C_Slave_Address;
typedef struct
    {
	uint32_t I2C_ClockSpeed;  			///@ref ClockSpeed
	uint8_t StretchMode;     			///@ref StretchMode
	uint32_t I2C_Mode;	     			///@ref I2C_Mode
	S_I2C_Slave_Address I2C_Slave_address;
	uint16_t I2C_Ack_Control;			///@ref I2C_Ack_Control
	uint32_t General_Call_Address_Detection; ///@ref General_Call_Address_Detection
	void (*P_Slave_Event_CallBack)(Slave_State state);
    } I2C_InitTypeDef;

///@ref ClockSpeed
/*
 //Bits 5:0 FREQ[5:0]: Peripheral clock frequency
 //The FREQ bits must be configured with the APB clock frequency value (I2C peripheral
 //connected to APB). The FREQ field is used by the peripheral to generate data setup and
 //hold times compliant with the I2C specifications. The minimum allowed frequency is 2 MHz,
 //the maximum frequency is limited by the maximum APB frequency and cannot exceed
 //50 MHz (peripheral intrinsic maximum limit).
 //0b000000: Not allowed
 //0b000001: Not allowed
 //0b000010: 2 MHz
 //...
 //0b110010: 50 MHz
 //Higher than 0b101010: Not allowed
 */

#define I2C_SCLK_SM_50K        (500000UL)
#define I2C_SCLK_SM_100K       (1000000UL)

///@ref StretchMode
//Bit 7 NOSTRETCH: Clock stretching disable (Slave mode)
//This bit is used to disable clock stretching in slave mode when ADDR or BTF flag is set, until
//it is reset by software.
//0: Clock stretching enabled
//1: Clock stretching disabled

#define I2C_StrectchMode_Enable           0
#define I2C_StrectchMode_Disable   I2C_CR1_NOSTRETCH

///@ref I2C_Mode

#define I2C_mode_I2C 	0
#define I2C_mode_SMBUS I2C_CR1_SMBUS

///@ref Slave_Adress_Mode
//Bit 15 ADDMODE Addressing mode (slave mode)
//0: 7-bit slave address (10-bit address not acknowledged)
//1: 10-bit slave address (7-bit address not acknowledged)
//Bit 14 Should always be kept at 1 by software.
#define I2C_Addressing_Slave_Mode_7bit	0
#define I2C_Addressing_Slave_Mode_10bit	(uint8_t)(1<<15)
///@ref I2C_Ack_Control
//    Bit 10 ACK: Acknowledge enable
//    This bit is set and cleared by software and cleared by hardware when PE=0.
//    0: No acknowledge returned
//    1: Acknowledge returned after a byte is received (matched address or data)
#define I2C_ACK_Enable	(I2C_CR1_ACK)
#define I2C_ACK_Disable   0
///@ref General_Call_Address_Detection
//    Bit 6 ENGC: General call enable
//    0: General call disabled. Address 00h is NACKed.
//    1: General call enabled. Address 00h is ACKed.
#define I2C_Genaral_Address_Enable       I2C_CR1_ENGC
#define I2C_Genaral_Address_Disable       0















void MCAL_I2C_Init(I2C_TypeDef *I2Cx, I2C_InitTypeDef *I2C_InitStruct);
void MCAL_I2C_DInit(I2C_TypeDef *I2Cx);
void MCAL_I2C_GPIO_Set_Pins (I2C_TypeDef* I2Cx);



















#endif /* INC_STM32F103C6_I2C_DRIVER_H_ */
