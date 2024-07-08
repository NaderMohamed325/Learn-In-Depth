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
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif



#include "stm32f103c6_EXTI_Driver.h"
#include "../STM32F103C6_Drivers/inc/stm32f103c6_USART_Driver.h"
 unsigned char c;
int main(void)
    {
    RCC_GPIOA_CLK_EN();
    RCC_GPIOB_CLK_EN();
    RCC_USART1_CLK_EN();
    UART_Config uart;
    uart.BaudRate = UART_BaudRate_115200;
    uart.HwFlowCtl = UART_HwFlowCtl_NONE;
    uart.IRQ_Enable = UART_IRQ_Enable_NONE;
    uart.P_IRQ_CallBack = NULL;
    uart.Parity = UART_Parity_OFF;
    uart.PayLoad_Length = UART_PayLoad_Length8B;
    uart.StopBits = UART_StopBits__1;
    uart.USART_Mode = UART_Mode_TX_RX;
    MCAL_UART_Init(USART1, &uart);
    MCAL_UART_GPIO_Set_Pins(USART1);
    while (1)
	{
	MCAL_UART_ReceiveData(USART1, &c, enable);
	MCAL_UART_SendData(USART1, &c, enable);
	}
    }
