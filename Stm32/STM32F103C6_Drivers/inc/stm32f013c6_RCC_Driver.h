/*
 * stm32f013c6_RCC_Driver.h
 *
 *  Created on: Jul 6, 2024
 *      Author: xcite
 */

#ifndef INC_STM32F013C6_RCC_DRIVER_H_
#define INC_STM32F013C6_RCC_DRIVER_H_

#include "stm32f103c6_gpio.h"

#define HSI_RC_Clk 16000000UL
#define HSE_Clock 16000000UL

uint32_t MCAL_RCC_Get_SYS_CLK_Freq(void);
uint32_t MCAL_RCC_Get_HCLK_Freq(void);
uint32_t MCAL_RCC_Get_PCLK1_Freq(void);
uint32_t MCAL_RCC_Get_PCLK2_Freq(void);












#endif /* INC_STM32F013C6_RCC_DRIVER_H_ */
