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

#include "../HAL/inc/keypad.h"
#include "../HAL/inc/lcd.h"
#include "stm32f103c6_EXTI_Driver.h"
void ISR(void)
    {
    LCD_clear_screen();
    LCD_WRITE_STRING((char*) "ISR Enabled");
    delay_ms(3000);
    LCD_clear_screen();
    }
int main(void)
    {
    LCD_INIT();
    EXTI_PinConfig_t  Exti_Pin;
    Exti_Pin.EXI_Pin = EXTI0PA0
    ;
    Exti_Pin.IRQ_EN = EXTI_IRQ_Enable;
    Exti_Pin.Trigger_Case = EXTI_Trigger_RISING;
    Exti_Pin.P_IRQ_CallBack = ISR;
    MCAL_EXTI_GPIO_Init(&Exti_Pin);
    LCD_WRITE_STRING((char*) "ISR Waiting")
	;
    while(1){


    }
    }
