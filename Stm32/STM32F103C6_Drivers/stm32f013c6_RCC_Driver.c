/*
 * stm32f013c6_RCC_Driver.c
 *
 *  Created on: Jul 6, 2024
 *      Author: xcite
 */
#include "inc/stm32f013c6_RCC_Driver.h"


// AHB prescaler table values
const uint8_t HCLK[] =
{
    0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
};

// APB prescaler table values
const uint8_t APBP_resc_Table[8] =
{
    0, 0, 0, 0, 1, 2, 3, 4
};

/**
 * @brief Get the SYSCLK frequency.
 * @return The system clock frequency in Hz.
 */
uint32_t MCAL_RCC_Get_SYS_CLK_Freq(void)
{
    switch ((RCC->CFGR >> 2) & 0x03)
    {
        case 0:
            return HSI_RC_Clk;

        case 1:
            return HSE_Clock;

        case 2:
            return 16000000UL;

        default:
            return -1; // Not allowed value
    }
}

/**
 * @brief Get the HCLK frequency.
 * @return The AHB clock frequency in Hz.
 */
uint32_t MCAL_RCC_Get_HCLK_Freq(void)
{
    return (MCAL_RCC_Get_SYS_CLK_Freq() >> HCLK[(RCC->CFGR >> 4) & 0x0F]);
}

/**
 * @brief Get the PCLK1 frequency.
 * @return The APB1 clock frequency in Hz.
 */
uint32_t MCAL_RCC_Get_PCLK1_Freq(void)
{
    return (MCAL_RCC_Get_HCLK_Freq() >> APBP_resc_Table[(RCC->CFGR >> 8) & 0x07]);
}

/**
 * @brief Get the PCLK2 frequency.
 * @return The APB2 clock frequency in Hz.
 */
uint32_t MCAL_RCC_Get_PCLK2_Freq(void)
{
    return (MCAL_RCC_Get_HCLK_Freq() >> APBP_resc_Table[(RCC->CFGR >> 11) & 0x07]);
}
