/*
 * stm32f103c6_gpio.h
 *
 *  Created on: Jun 29, 2024
 *      Author: Nader
 */

#ifndef STM32F103C6_GPIO_H_
#define STM32F103C6_GPIO_H_

// Includes
#include "stm32f103x6.h"

//---------------------------------------

// Config
typedef struct
{
    uint16_t GPIO_PinNumber;  ///< Select the pin number @ref GPIO_PINS_define
    uint8_t GPIO_MODE;        ///< Selects the pin mode
    uint8_t GPIO_Speed;       ///< Selects the slew rate
} GPIO_PinConfig_t;

#define GPIO_PIN_SET  1
#define GPIO_PIN_RESET 0

#define GPIO_RETURN_LOCK_Enabled 1
#define GPIO_RETURN_LOCK_Error   0

/// @ref GPIO_PINS_define
#define GPIO_PIN_0       ((uint16_t)0x0001)
#define GPIO_PIN_1       ((uint16_t)0x0002)
#define GPIO_PIN_2       ((uint16_t)0x0004)
#define GPIO_PIN_3       ((uint16_t)0x0008)
#define GPIO_PIN_4       ((uint16_t)0x0010)
#define GPIO_PIN_5       ((uint16_t)0x0020)
#define GPIO_PIN_6       ((uint16_t)0x0040)
#define GPIO_PIN_7       ((uint16_t)0x0080)
#define GPIO_PIN_8       ((uint16_t)0x0100)
#define GPIO_PIN_9       ((uint16_t)0x0200)
#define GPIO_PIN_10      ((uint16_t)0x0400)
#define GPIO_PIN_11      ((uint16_t)0x0800)
#define GPIO_PIN_12      ((uint16_t)0x1000)
#define GPIO_PIN_13      ((uint16_t)0x2000)
#define GPIO_PIN_14      ((uint16_t)0x4000)
#define GPIO_PIN_15      ((uint16_t)0x8000)
#define GPIO_PIN_ALL     ((uint16_t)0xFFFF)
#define GPIO_PIN_MASK    0x0000FFFFu

// GPIO modes
#define GPIO_MODE_Analog        0  ///< Analog mode
#define GPIO_MODE_INPUT_FLO     1  ///< Floating input
#define GPIO_MODE_INPUT_PU      2  ///< Input with pull-up
#define GPIO_MODE_INPUT_PD      3  ///< Input with pull-down
#define GPIO_MODE_OUTPUT_PP     4  ///< General purpose output push-pull
#define GPIO_MODE_OUTPUT_OD     5  ///< General purpose output open-drain
#define GPIO_MODE_OUTPUT_AF_PP  6  ///< Alternate function output push-pull
#define GPIO_MODE_OUTPUT_AF_OD  7  ///< Alternate function output open-drain
#define GPIO_MODE_AF_INPUT      8  ///< Alternate function input

// GPIO speeds
#define GPIO_SPEED_10M 1
#define GPIO_SPEED_2M  2
#define GPIO_SPEED_50M 3

/**
 * @brief  Initializes the GPIO pin(s) according to the specified parameters in GPIO_PinConfig_t.
 * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
 * @param  PinConfig: pointer to a GPIO_PinConfig_t structure that contains
 *         the configuration information for the specified GPIO pin(s).
 * @retval None
 */
void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig);

/**
 * @brief  Resets the GPIOx peripheral registers to their default reset values.
 * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
 * @retval None
 */
void MCAL_GPIO_Deinit(GPIO_TypeDef *GPIOx);

/**
 * @brief  Reads the specified input pin.
 * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
 * @param  PinNumber: specifies the pin to be read.
 *          This parameter can be one of GPIO_PIN_x where x can be (0..15).
 * @retval The input pin value (0 or 1).
 */
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber);

/**
 * @brief  Reads the entire GPIO port.
 * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
 * @retval The input port value.
 */
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx);

/**
 * @brief  Toggles the specified output pin.
 * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
 * @param  PinNumber: specifies the pin to be toggled.
 *          This parameter can be one of GPIO_PIN_x where x can be (0..15).
 * @retval None
 */
void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber);

/**
 * @brief  Locks the specified output pin.
 * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
 * @param  PinNumber: specifies the pin to be locked.
 *          This parameter can be one of GPIO_PIN_x where x can be (0..15).
 * @retval uint8_t (OK or NULL)
 */
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber);

/**
 * @brief  Writes a value to the entire GPIO port.
 * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
 * @param  value: specifies the value to be written to the port.
 * @retval None
 */
void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx, uint16_t value);

/**
 * @brief  Writes a value to the specified GPIO pin.
 * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
 * @param  PinNumber: specifies the pin to be written.
 *          This parameter can be one of GPIO_PIN_x where x can be (0..15).
 * @param  value: specifies the value to be written to the pin (0 or 1).
 * @retval None
 */
void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber, uint8_t value);

#endif /* STM32F103C6_GPIO_H_ */
