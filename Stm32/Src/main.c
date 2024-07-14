/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Nader
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
//#define MCU_Act_As_Master 1
//#define MCU_Act_As_Slave  1

#include "../STM32F103C6_Drivers/inc/stm32f103c6_I2C_Driver.h"



/**
 * @brief UART interrupt service routine.
 * This function handles received data from UART and sends it via SPI.
 */

int main(void)
    {
    // Enable necessary clocks
    RCC_GPIOA_CLK_EN();
    RCC_GPIOB_CLK_EN();
    RCC_USART1_CLK_EN();
    RCC_SPI1_CLK_EN();
    RCC_AFIO_CLK_EN(); // Enable AFIO clock

    while (1)
	{

	}

    }
