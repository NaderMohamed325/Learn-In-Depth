/*
 * stm32f103c6_I2C_Driver.c
 *
 *  Created on: Jul 14, 2024
 *      Author: xcite
 */
#include "inc/stm32f103c6_I2C_Driver.h"

I2C_InitTypeDef Global_I2C_Config[] =
    {
	{
	0
	},
	{
	0
	}
    };

#define 		I2C1_INDEX 				0
#define 		I2C2_INDEX 				1

void MCAL_I2C_Init(I2C_TypeDef *I2Cx, I2C_InitTypeDef *I2C_InitStruct)
    {
    uint16_t tempreg = 0, freqrange = 0;
    uint32_t pclk = 8000000;
    if (I2Cx == I2C1)
	{
	Global_I2C_Config[I2C1_INDEX] = *I2C_InitStruct;
	RCC_I2C1_CLK_EN();
	}
    else if (I2Cx == I2C2)
	{
	Global_I2C_Config[I2C2_INDEX] = *I2C_InitStruct;
	RCC_I2C2_CLK_EN();
	}

    if (I2C_InitStruct->I2C_Mode == I2C_mode_I2C)
	{
	tempreg = I2Cx->I2C_CR2;
	temp &= ~(I2C_CR2_FREQ_Msk);
	pclk = MCAL_RCC_GetPCLK1Freq();
	freqrange = (uint16_t) ((pclk) / 1000000);
	tempreg |= freqrange;
	I2Cx->I2C_CR2 = tempreg;
//---------------------------------------------------------//
	I2Cx->I2C_CR1 &= ~(I2C_CR1_PE);
	temp = 0;
	if (I2C_InitStruct->I2C_ClockSpeed == I2C_SCLK_SM_50K
		|| I2C_InitStruct->I2C_ClockSpeed == I2C_SCLK_SM_100K)
	    {

	    }

	}

    }
void MCAL_I2C_DInit(I2C_TypeDef *I2Cx)
    {

    }
void MCAL_I2C_GPIO_Set_Pins(I2C_TypeDef *I2Cx)
    {

    }
