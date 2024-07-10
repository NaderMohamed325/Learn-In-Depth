/*
 * stm32f013c6_RCC_Driver.h
 *
 *  Created on: Jul 6, 2024
 *      Author: xcite
 */

#ifndef INC_STM32F013C6_RCC_DRIVER_H_
#define INC_STM32F013C6_RCC_DRIVER_H_

#include "stm32f103c6_gpio.h"


#define  HSE_Clock			(uint32_t)16000000
#define  HSI_RC_Clk			(uint32_t)8000000


uint32_t MCAL_RCC_GetSYS_CLCKFreq(void);
uint32_t MCAL_RCC_GetHCLKFreq(void);
uint32_t MCAL_RCC_GetPCLK1Freq(void);
uint32_t MCAL_RCC_GetPCLK2Freq(void);












#endif /* INC_STM32F013C6_RCC_DRIVER_H_ */
