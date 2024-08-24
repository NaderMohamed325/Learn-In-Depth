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
#include "../STM32F103C6_Drivers/inc/stm32f103c6_EXTI_Driver.h"

#define TaskA_Stack_Size 100
#define TaskB_Stack_Size 100
extern unsigned int _estack;

unsigned int _S_MSP = (unsigned int) &_estack, _E_MSP, S_PSP_TA, E_PSP_TA,
	S_PSP_TB, E_PSP_TB;

uint8_t TASKA_IRQ_flag = 0, TASKB_IRQ_flag = 0, IRQ_Flag = 0;

#define OS_SET_PSP(add)  __asm volatile("mov r0 ,%0 \n\t msr PSP , r0 " : : "r"(add)  )
#define OS_SP_PSP()      __asm volatile("mrs r0 ,CONTROL \n\t mov r1 ,#0x02 \n\t  orr r0,r0,r1 \n\t msr CONTROL , r0")
#define OS_PSP_SP()      __asm volatile("mrs r0 ,CONTROL \n\t mov r1 ,#0x05 \n\t  and r0,r0,r1 \n\t msr CONTROL , r0")
typedef enum
    {
    privilged,
    unprivilged
    } CPU_Access_level;

void Switch_CPU_Access_level(CPU_Access_level access_level)
    {
    switch (access_level)
	{
    case privilged:
	__asm("NOP \n\t NOP \n\t NOP \n\t");
	__asm("mrs r3, CONTROL \n\t"
		"lsr r3, r3, #0x01 \n\t"
		"lsr r3, r3, #0x01 \n\t"
		"msr CONTROL , r3");
	__asm("NOP \n\t NOP \n\t NOP \n\t");
	break;
    case unprivilged:
	__asm("NOP \n\t NOP \n\t NOP \n\t");
	__asm("mrs r3, CONTROL \n\t"
		"orr r3, r3, #0x01 \n\t"
		"msr CONTROL , r3");
	__asm("NOP \n\t NOP \n\t NOP \n\t");
	break;
	}
    }
#define   OS_Generate_Exception()   __asm volatile("SVC #3")
void EXTI9_CALLBACK(void)
    {
    if (!IRQ_Flag)
	{
	TASKA_IRQ_flag = 1;
	IRQ_Flag = 1;
	}
    else
	{
	TASKB_IRQ_flag = 1;
	IRQ_Flag = 0;
	}
    }

int TaskA(int a, int b)
    {
    return a + b;
    }

int TaskB(int a, int b, int c)
    {
    return a + b + c;
    }
void SVC_Handler()
    {
    Switch_CPU_Access_level(privilged);
    }
void MainOs(void)
    {
    _E_MSP = _S_MSP - 512;

    S_PSP_TA = (_E_MSP - 8);
    E_PSP_TA = (S_PSP_TA - TaskA_Stack_Size);

    S_PSP_TB = (E_PSP_TA - 8);
    E_PSP_TB = (S_PSP_TB - TaskB_Stack_Size);

    while (1)
	{
	__asm("NOP");
	if (TASKA_IRQ_flag)
	    {
	    TASKA_IRQ_flag = 0;
	    OS_SET_PSP(S_PSP_TA);
	    Switch_CPU_Access_level(unprivilged);
	    OS_SP_PSP();
	    TASKA_IRQ_flag = TaskA(4, 6);
	    OS_Generate_Exception();
	    OS_PSP_SP();
	    }
	else if (TASKB_IRQ_flag)
	    {
	    TASKB_IRQ_flag = 0;
	    OS_SET_PSP(S_PSP_TB);
	    OS_SP_PSP();
	    Switch_CPU_Access_level(unprivilged);
	    TASKB_IRQ_flag = TaskB(2, 4, 6);
	    OS_Generate_Exception();
	    OS_PSP_SP();
	    }
	}
    }

int main(void)
    {
    RCC_GPIOB_CLK_EN();
    RCC_AFIO_CLK_EN();

    // Set EXTI Configuration
    EXTI_PinConfig_t EXTIConfig;
    EXTIConfig.EXI_Pin = EXTI9PB9
    ;
    EXTIConfig.Trigger_Case = EXTI_Trigger_RISING;
    EXTIConfig.P_IRQ_CallBack = EXTI9_CALLBACK;
    EXTIConfig.IRQ_EN = EXTI_IRQ_Enable;
    MCAL_EXTI_GPIO_Init(&EXTIConfig);

    // Initialize IRQ_Flag
    IRQ_Flag = 1;

    // Start the OS
    MainOs();

    while (1)
	{
	if (IRQ_Flag)
	    {
	    IRQ_Flag = 0;
	    }
	else
	    {
	    // Do nothing, avoid MISRA warning
	    }
	}
    }
