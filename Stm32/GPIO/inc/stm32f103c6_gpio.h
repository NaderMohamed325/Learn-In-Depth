/*
 * stm32f103c6_gpio.h
 *
 *  Created on: Jun 29, 2024
 *      Author: Nader
 */

#ifndef STM32F103C6_GPIO_H_
#define STM32F103C6_GPIO_H_

//Includes
#include "stm32f103x6.h"

//---------------------------------------

//Config

typedef struct{
	uint16_t GPIO_PinNumber;  ///select the pin number @ref GPIO_PINS_define

	uint8_t GPIO_MODE;       /// selects the pin mode

	uint8_t GPIO_Speed;     /// selects the slew rate
}GPIO_PinConfig_t;

#define GPIO_PIN_SET  1
#define GPIO_PIN_RESET 0

#define GPIO_RETURN_LOCK_Enabled 1
#define GPIO_RETURN_LOCK_Error   0



/// @ref GPIO_PINS_define
#define GPIO_PIN_0            ((uint16_t)0x0001)
#define GPIO_PIN_1            ((uint16_t)0x0002)
#define GPIO_PIN_2            ((uint16_t)0x0004)
#define GPIO_PIN_3            ((uint16_t)0x0008)
#define GPIO_PIN_4            ((uint16_t)0x0010)
#define GPIO_PIN_5            ((uint16_t)0x0020)
#define GPIO_PIN_6            ((uint16_t)0x0040)
#define GPIO_PIN_7            ((uint16_t)0x0080)
#define GPIO_PIN_8            ((uint16_t)0x0100)
#define GPIO_PIN_9            ((uint16_t)0x0200)
#define GPIO_PIN_10           ((uint16_t)0x0400)
#define GPIO_PIN_11           ((uint16_t)0x0800)
#define GPIO_PIN_12           ((uint16_t)0x1000)
#define GPIO_PIN_13           ((uint16_t)0x2000)
#define GPIO_PIN_14           ((uint16_t)0x4000)
#define GPIO_PIN_15           ((uint16_t)0x8000)
#define GPIO_PIN_ALL          ((uint16_t)0xFFFF)


#define GPIO_PIN_MASK          0X0000FFFFU

//In input mode (MODE[1:0]=00):
//00: Analog mode
//01: Floating input (reset state)
//10: Input with pull-up / pull-down
//11: Reserved
//In output mode (MODE[1:0] >00):
//00: General purpose output push-pull
//01: General purpose output Open-drain
//10: Alternate function output Push-pull
//11: Alternate function output Open-drain

#define GPIO_MODE_Analog       0     	 /// Analog					///
#define GPIO_MODE_INPUT_FLO    1        /// floating			   ///
#define GPIO_MODE_INPUT_PU     2       /// pull up                ///
#define GPIO_MODE_INPUT_PD     3      /// pull down              ///
#define GPIO_MODE_OUTPUT_PP	   4     /// push pull              ///
#define GPIO_MODE_OUTPUT_OD    5    /// open drain             ///
#define GPIO_MODE_OUTPUT_AF_PP 6   /// alternative push pull  ///
#define GPIO_MODE_OUTPUT_AF_OD 7  /// alternative open drain ///
#define GPIO_MODE_AF_INPUT     8 /// alternative input      ///


//00: Input mode (reset state)
//01: Output mode, max speed 10 MHz.
//10: Output mode, max speed 2 MHz.
//11: Output mode, max speed 50 MHz.

#define GPIO_SPEED_10M 1
#define GPIO_SPEED_2M  2
#define GPIO_SPEED_50M 3



/**
 * @brief  Initializes the GPIO pin(s) according to the specified parameters in GPIO_PinConfig_t.
 * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
 * @param  PinConfig: pointer to a GPIO_PinConfig_t structure that contains
 *         the configuration information for the specified GPIO pin(s).
 * @retval None
 *
 * This function configures the mode, speed, pull-up/pull-down resistors,
 * and output type of the specified GPIO pin(s).
 */
void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig);

/**
 * @brief  Resets the GPIOx peripheral registers to their default reset values.
 * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
 * @retval None
 *
 * This function deinitializes the GPIO peripheral, resetting all registers to their default values.
 */
void MCAL_GPIO_Deinit(GPIO_TypeDef *GPIOx);

/**
 * @brief  Reads the specified input pin.
 * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
 * @param  PinNumber: specifies the pin to be read.
 *          This parameter can be one of GPIO_PIN_x where x can be (0..15).
 * @retval The input pin value (0 or 1).
 *
 * This function reads the value of the specified GPIO pin.

 */
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber);

/**
 * @brief  Reads the entire GPIO port.
 * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
 * @retval The input port value.
 *
 * This function reads the value of the entire GPIO port, returning the state of all pins.
 */
uint16_t  MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx);


/**
 * @brief  Toggles the specified output pin.
 * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
 * @param  PinNumber: specifies the pin to be toggled.
 *          This parameter can be one of GPIO_PIN_x where x can be (0..15).
 * @retval  void
 *
 * This function toggles the value of the specified GPIO pin.

 */
void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber);

/**
 * @brief  Lock the specified output pin.
 * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
 * @param  PinNumber: specifies the pin to be Locked.
 *          This parameter can be one of GPIO_PIN_x where x can be (0..15).
 * @retval  uint8_t (OK or NULL)
 *
 * This function Locks the value of the specified GPIO pin.

 */
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber);


void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx,uint16_t value);


#endif /* STM32F103C6_GPIO_H_ */
