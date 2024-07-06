/*
 * stm32f013c6_RCC_Driver.c
 *
 *  Created on: Jul 6, 2024
 *      Author: xcite
 */
#include "inc/stm32f013c6_RCC_Driver.h"

const uint8_t APBP_resc_Table[8] =
    {
    0, 0, 0, 0, 1, 2, 3, 4
    };
const uint8_t HCLK[] =
    {
    0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    };
//Bits 1:0
//SW[1:0]: System clock Switch
//Set and cleared by software to select SYSCLK source.
//Set by hardware to force HSI selection when leaving Stop and Standby mode or in case of failure of
//the HSE oscillator used directly or indirectly as system clock (if the Clock Security System is
//enabled).
//00: HSI selected as system clock
//01: HSE selected as system clock
//10: PLL selected as system clock
//11: Not allowed

uint32_t MCAL_RCC_Get_SYS_CLK_Freq(void)
    {
    switch (RCC->CFGR >> 2)
	{
    case 0:
	return HSI_RC_Clk;
	break;

    case 1:
	return HSE_Clock;
	break;

    case 2:
	return 16000000UL;
	break;

	}
return -1;
    }
//Bits 7:4 HPRE[3:0]: AHB prescaler
//Set and cleared by software to control AHB clock division factor.
//0xxx: SYSCLK not divided
//1000: SYSCLK divided by 2      8
//1001: SYSCLK divided by 4      9
//1010: SYSCLK divided by 8      10
//1011: SYSCLK divided by 16     11
//1100: SYSCLK divided by 64     12
//1101: SYSCLK divided by 128    13
//1110: SYSCLK divided by 256    14
//1111: SYSCLK divided by 512    15
uint32_t MCAL_RCC_Get_HCLK_Freq(void)
    {
    return (MCAL_RCC_Get_SYS_CLK_Freq() >> ((HCLK[RCC->CFGR >> 4]) & 0B1111));
    }
//Bits 10:8 PPRE1[2:0]: APB Low-speed prescaler (APB1)
//Set and cleared by software to control the division factor of the APB Low speed clock (PCLK1).
//0xx: HCLK not divided
//100: HCLK divided by 2
//101: HCLK divided by 4
//110: HCLK divided by 8
//111: HCLK divided by 16
//Caution: Software must configure these bits ensure that the frequency in this domain does not
//exceed 36 MHz.
uint32_t MCAL_RCC_Get_PCLK1_Freq(void)
    {
    return (MCAL_RCC_Get_HCLK_Freq()
	    >> (APBP_resc_Table[RCC->CFGR >> 8] & 0B111));

    }

//Bits 13:11 PPRE2[2:0]: APB high-speed prescaler (APB2)
//Set and cleared by software to control the division factor of the APB High speed clock (PCLK2).
//0xx: HCLK not divided
//100: HCLK divided by 2
//101: HCLK divided by 4
//110: HCLK divided by 8
//111: HCLK divided by 16

uint32_t MCAL_RCC_Get_PCLK2_Freq(void)
    {
    return (MCAL_RCC_Get_HCLK_Freq()
	    >> (APBP_resc_Table[RCC->CFGR >> 11] & 0B111));
    }

