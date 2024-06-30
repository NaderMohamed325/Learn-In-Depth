/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
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

#include "../GPIO/inc/stm32f103c6_gpio.h"

// Simple delay function
void delay(unsigned int nCount)
    {
    unsigned int i, j;

    for (i = 0; i < nCount; i++)
	for (j = 0; j < nCount; j++)
	    ;
    }

// Initialize the clock for GPIOA and GPIOB
void clock_init()
    {
    RCC_GPIOA_CLK_EN();  // Enable clock for GPIOA
    RCC_GPIOB_CLK_EN();  // Enable clock for GPIOB
    }

// Initialize GPIO pins
void GPIO_init()
    {
    GPIO_PinConfig_t PinCfg;

    // Configure PA1 as Input Floating
    PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
    PinCfg.GPIO_PinNumber = GPIO_PIN_1;
    MCAL_GPIO_Init(GPIOA, &PinCfg);

    // Configure PB1 as Output Push-Pull mode with 10MHz speed
    PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
    PinCfg.GPIO_PinNumber = GPIO_PIN_1;
    PinCfg.GPIO_Speed = GPIO_SPEED_10M;
    MCAL_GPIO_Init(GPIOB, &PinCfg);

    // Configure PA13 as Input Floating
    PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
    PinCfg.GPIO_PinNumber = GPIO_PIN_13;
    MCAL_GPIO_Init(GPIOA, &PinCfg);

    // Configure PB13 as Output Push-Pull mode with 10MHz speed
    PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
    PinCfg.GPIO_PinNumber = GPIO_PIN_13;
    PinCfg.GPIO_Speed = GPIO_SPEED_10M;
    MCAL_GPIO_Init(GPIOB, &PinCfg);

    }

int main(void)
    {
    // Initialize clocks and GPIO pins
    clock_init();
    GPIO_init();

    while (1)
	{
	// Check if PA1 is LOW
	if (MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == GPIO_PIN_RESET)
	    {
	    // Toggle PB1
	    MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
	    // Wait until PA1 is HIGH
	    while (MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == GPIO_PIN_RESET)
		;
	    }

	// Check if PA13 is HIGH
	if (MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13) == GPIO_PIN_SET)
	    {
	    // Toggle PB13
	    MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
	    }

	// Simple delay
	delay(100);
	}
    }
