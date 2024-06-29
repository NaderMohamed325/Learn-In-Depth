/*
 * stm32f103c6_gpio.c
 *
 *  Created on: Jun 29, 2024
 *      Author: Nader
 */

#include "stm32f103c6_gpio.h"

uint8_t Get_CRLH_Position(uint16_t PinNumber)
    {
    switch (PinNumber)
	{
    case GPIO_PIN_0:
	return 0;
	break;
    case GPIO_PIN_1:
	return 4;
	break;
    case GPIO_PIN_2:
	return 8;
	break;
    case GPIO_PIN_3:
	return 12;
	break;
    case GPIO_PIN_4:
	return 16;
	break;
    case GPIO_PIN_5:
	return 20;
	break;
    case GPIO_PIN_6:
	return 24;
	break;
    case GPIO_PIN_7:
	return 28;
	break;
    case GPIO_PIN_8:
	return 32;
	break;
    case GPIO_PIN_9:
	return 36;
	break;
    case GPIO_PIN_10:
	return 40;
	break;
    case GPIO_PIN_11:
	return 44;
	break;
    case GPIO_PIN_12:
	return 48;
	break;
    case GPIO_PIN_13:
	return 52;
	break;
    case GPIO_PIN_14:
	return 56;
	break;
    case GPIO_PIN_15:
	return 60;
	break;
    default:
	// Handle error or return default position
	return 0;
	break;
	}
    }
/**
 * @brief  Initializes the GPIO pin(s) according to the specified parameters in GPIO_PinConfig_t.
 * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
 * @param  PinConfig: pointer to a GPIO_PinConfig_t structure that contains
 *         the configuration information for the specified GPIO pin(s).
 * @retval None
 *
 * This function initializes the GPIO pin(s) based on the configuration provided
 * in the GPIO_PinConfig_t structure.
 */
void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig)
    {
    uint8_t PIN_CONFIG = 0; // Variable to store pin configuration
    volatile uint32_t *configregister = NULL; // Pointer to the configuration register

    // Determine whether to use CRL or CRH register based on pin number
    configregister =
	    (PinConfig->GPIO_PinNumber < 8) ? &GPIOx->CRL : &GPIOx->CRH;

    // Clear the configuration bits for the specified pin
    (*configregister) &= ~(0xF << Get_CRLH_Position(PinConfig->GPIO_PinNumber));

    // Configure pin mode and speed
    if ((PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD)
	    || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP)
	    || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD)
	    || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP))
	{
	// Calculate pin configuration for output modes
	PIN_CONFIG = (((PinConfig->GPIO_MODE - 4) << 2)
		| (PinConfig->GPIO_Speed)) & 0x0F;
	}
    else
	{
	if ((PinConfig->GPIO_MODE == GPIO_MODE_Analog)
		|| (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO))
	    {
	    // Calculate pin configuration for analog or input floating modes
	    PIN_CONFIG = (PinConfig->GPIO_MODE << 2) & 0x0F;
	    }
	else
	    {
	    // Handle input with pull-up or pull-down modes
	    if ((PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PD)
		    || (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU))
		{
		PIN_CONFIG = (GPIO_MODE_INPUT_PU << 2) & 0x0F;
		}

	    // Set or clear the ODR register based on pull-up configuration
	    if (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU)
		{
		GPIOx->ODR |= PinConfig->GPIO_PinNumber; // Set pin to pull-up
		}
	    else
		{
		GPIOx->ODR &= ~PinConfig->GPIO_PinNumber; // Clear pin (no pull-up)
		}
	    }
	}

    // Apply the configured settings to the selected pin
    (*configregister) |= (PIN_CONFIG
	    << Get_CRLH_Position(PinConfig->GPIO_PinNumber));
    }

/**
 * @brief  Resets the GPIOx peripheral registers to their default reset values.
 * @param  GPIOx: where x can be (A..F) to select the GPIO peripheral.
 * @retval None
 *
 * This function deinitializes the GPIO peripheral, resetting all registers to their default values.
 */
void MCAL_GPIO_Deinit(GPIO_TypeDef *GPIOx)
    {
    if (GPIOx == GPIOA)
	{
	RCC->APB2RSTR |= (1 << 2);
	RCC->APB2RSTR &= ~(1 << 2);
	}
    else if (GPIOx == GPIOB)
	{
	RCC->APB2RSTR |= (1 << 3);
	RCC->APB2RSTR &= ~(1 << 3);
	}
    else if (GPIOx == GPIOC)
	{
	RCC->APB2RSTR |= (1 << 4);
	RCC->APB2RSTR &= ~(1 << 4);
	}
    else if (GPIOx == GPIOD)
	{
	RCC->APB2RSTR |= (1 << 5);
	RCC->APB2RSTR &= ~(1 << 5);
	}
    else if (GPIOx == GPIOE)
	{
	RCC->APB2RSTR |= (1 << 6);
	RCC->APB2RSTR &= ~(1 << 6);
	}
    }

/**
 * @brief  Reads the specified input pin.
 * @param  GPIOx: where x can be (A..F) to select the GPIO peripheral.
 * @param  PinNumber: specifies the pin to be read.
 *          This parameter can be one of GPIO_PIN_x where x can be (0..15).
 * @retval The input pin value (0 or 1).
 *
 * This function reads the value of the specified GPIO pin.

 */
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber)
    {
    uint8_t bit_status;
    if (((GPIOx->IDR) & PinNumber) != (uint32_t) GPIO_PIN_RESET)
	{
	bit_status = GPIO_PIN_SET;
	}
    else
	{
	bit_status = GPIO_PIN_RESET;
	}
    return bit_status;
    }

/**
 * @brief  Reads the entire GPIO port.
 * @param  GPIOx: where x can be (A..F) to select the GPIO peripheral.
 * @retval The input port value.
 *
 * This function reads the value of the entire GPIO port, returning the state of all pins.
 */
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx)
    {
    return (uint16_t) (GPIOx->IDR);
    }

/**
 * @brief  Toggles the specified output pin.
 * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
 * @param  PinNumber: specifies the pin to be toggled.
 *          This parameter can be one of GPIO_PIN_x where x can be (0..15).
 * @retval  void
 *
 * This function toggles the value of the specified GPIO pin.

 */
void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber)
    {
    GPIOx->ODR ^= PinNumber;

    }

/**
 * @brief  Lock the specified output pin.
 * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
 * @param  PinNumber: specifies the pin to be Locked.
 *          This parameter can be one of GPIO_PIN_x where x can be (0..15).
 * @retval  uint8_t (OK or NULL)
 *
 * This function Locks the value of the specified GPIO pin.

 */
//This register is used to lock the configuration of the port bits when a correct write sequence
//is applied to bit 16 (LCKK). The value of bits [15:0] is used to lock the configuration of the
//GPIO. During the write sequence, the value of LCKR[15:0] must not change. When the
//LOCK sequence has been applied on a port bit it is no longer possible to modify the value of
//the port bit until the next reset.
// Each lock bit freezes the corresponding 4 bits of the control register (CRL, CRH)
//Bit 16 LCKK[16]: Lock key
//This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
//0: Port configuration lock key not active
//1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
//LOCK key writing sequence:
//Write 1
//Write 0
//Write 1
//Read 0
//Read 1 (this read is optional but confirms that the lock is active
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint16_t PinNumber)
    {
    volatile uint32_t temp = (1 << 16);

    temp|= PinNumber; //2 in 1

    GPIOx->LCKR = temp;
    GPIOx->LCKR = PinNumber;
    GPIOx->LCKR = temp;
    temp=GPIOx->LCKR ;
   if((uint32_t)(GPIOx->LCKR & 1<<16)){
       return GPIO_RETURN_LOCK_Enabled;
   }else
       {
       return GPIO_RETURN_LOCK_Error;
       }


    }
/**
 * @brief  Write on the specified output pin.
 * @param  GPIOx: where x can be (A..G) to select the GPIO peripheral.
 * @param  PinNumber: specifies the pin to be changed
 *          This parameter can be one of GPIO_PIN_x where x can be (0..15).
 * @param   value: high or low logic
 * @retval  void
 *
 * This function write value on the specified GPIO pin.

 * @brief
 *
 * @param GPIOx
 * @param PinNumber
 * @param value
 */

void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t PinNumber, uint8_t value)
    {
    if (value != GPIO_PIN_RESET)
	{
//	 These bits are write-only and can be accessed in Word mode only.
//	 0: No action on the corresponding ODRx bit
//	 1: Set the corresponding ODRx bit

	GPIOx->BSRR = (uint32_t) PinNumber;
	}
    else
	{
//	 These bits are write-only and can be accessed in Word mode only.
//	 0: No action on the corresponding ODRx bit
//	 1: Reset the corresponding ODRx bit
	GPIOx->BRR = (uint32_t) PinNumber;
	}

    }
/**
 * @brief  Write on the entire GPIO port.
 * @param  GPIOx: where x can be (A..F) to select the GPIO peripheral.
 * @retval void
 *
 * This function write value on the entire GPIO port.
 */

void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx, uint16_t value)
    {

    GPIOx->ODR = (uint32_t) value;

    }
