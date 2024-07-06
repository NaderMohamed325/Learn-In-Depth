/*
 * stm32f103c6_USART_Driver.c
 *
 *  Created on: Jul 6, 2024
 *      Author: xcite
 */

#include "inc/stm32f103c6_USART_Driver.h"

UART_Config *GL_USART1 = NULL;
UART_Config *GL_USART2 = NULL;
UART_Config *GL_USART3 = NULL;

/**
 * @brief Initializes the UART peripheral according to the specified parameters in UART_Config.
 * @param USARTx: Specifies the USART peripheral. This parameter can be USART1, USART2, or USART3.
 * @param UART_Config: Pointer to a UART_Config structure that contains the configuration information for the specified USART peripheral.
 * @return None
 */
void MCAL_UART_Init(USART_TypeDef *USARTx, UART_Config *UART_Config)
{
    uint32_t pclk, BRR;

    if (USARTx == USART1)
    {
        GL_USART1 = UART_Config;
        RCC_USART1_CLK_EN();
    }
    else if (USARTx == USART2)
    {
        GL_USART2 = UART_Config;
        RCC_USART2_CLK_EN();
    }
    else if (USARTx == USART3)
    {
        GL_USART3 = UART_Config;
        RCC_USART3_CLK_EN();
    }

    USARTx->CR1 |= (1 << 13); // USART enable

    USARTx->CR1 |= UART_Config->USART_Mode;
    USARTx->CR1 |= UART_Config->PayLoad_Length;
    USARTx->CR2 |= UART_Config->StopBits;
    USARTx->CR3 |= UART_Config->HwFlowCtl;

    if (USARTx == USART1)
    {
        pclk = MCAL_RCC_Get_PCLK2_Freq();
    }
    else
    {
        pclk = MCAL_RCC_Get_PCLK1_Freq();
    }
    BRR = UART_BRR_Register(pclk, UART_Config->BaudRate);

    USARTx->BRR = BRR;
    if (UART_Config->IRQ_Enable != UART_IRQ_Enable_NONE)
    {
        USARTx->CR1 |= (UART_Config->IRQ_Enable);

        if (USARTx == USART1)
            NVIC_IRQ37_USART1_Enable();
        else if (USARTx == USART2)
            NVIC_IRQ38_USART2_Enable();
        else if (USARTx == USART3)
            NVIC_IRQ39_USART3_Enable();
    }
}

/**
 * @brief De-initializes the UART peripheral.
 * @param USARTx: Specifies the USART peripheral. This parameter can be USART1, USART2, or USART3.
 * @return None
 */
void MCAL_UART_DeInit(USART_TypeDef *USARTx)
{
    if (USARTx == USART1)
    {
        RCC_USART1_Reset();
        NVIC_IRQ37_USART1_Disable();
        GL_USART1 = NULL;
    }
    else if (USARTx == USART2)
    {
        RCC_USART2_Reset();
        NVIC_IRQ38_USART2_Disable();
        GL_USART2 = NULL;
    }
    else if (USARTx == USART3)
    {
        RCC_USART3_Reset();
        NVIC_IRQ39_USART3_Disable();
        GL_USART3 = NULL;
    }
}

/**
 * @brief Sends data through the specified USART peripheral.
 * @param USARTx: Specifies the USART peripheral. This parameter can be USART1, USART2, or USART3.
 * @param pTxBuffer: Pointer to the data buffer to be sent.
 * @param PollingEn: Specifies the polling mechanism, enable or disable.
 * @return None
 */
void MCAL_UART_SendData(USART_TypeDef *USARTx, uint16_t *pTxBuffer, enum Polling_mechism PollingEn)
{
    if (PollingEn == enable)
    {
        while (!(USARTx->SR & (1 << 7)));
    }

    UART_Config *config = NULL;
    if (USARTx == USART1) config = GL_USART1;
    else if (USARTx == USART2) config = GL_USART2;
    else if (USARTx == USART3) config = GL_USART3;

    if (config->PayLoad_Length == UART_PayLoad_Length9B)
    {
        USARTx->DR = (*pTxBuffer & (uint16_t)0x01FF);
    }
    else
    {
        USARTx->DR = (*pTxBuffer & (uint16_t)0xFF);
    }
}

/**
 * @brief Receives data from the specified USART peripheral.
 * @param USARTx: Specifies the USART peripheral. This parameter can be USART1, USART2, or USART3.
 * @param pRxBuffer: Pointer to the buffer that will store the received data.
 * @param PollingEn: Specifies the polling mechanism, enable or disable.
 * @return None
 */
void MCAL_UART_ReceiveData(USART_TypeDef *USARTx, uint16_t *pRxBuffer, enum Polling_mechism PollingEn)
{
    if (PollingEn == enable)
    {
        while (!(USARTx->SR & (1 << 5)));
    }

    UART_Config *config = NULL;
    if (USARTx == USART1) config = GL_USART1;
    else if (USARTx == USART2) config = GL_USART2;
    else if (USARTx == USART3) config = GL_USART3;

    if (config->PayLoad_Length == UART_PayLoad_Length9B)
    {
        if (config->Parity == UART_Parity_OFF)
        {
            *((uint16_t*)pRxBuffer) = USARTx->DR;
        }
        else
        {
            *((uint16_t*)pRxBuffer) = (USARTx->DR & (uint8_t)0xFF);
        }
    }
    else
    {
        if (config->Parity == UART_Parity_OFF)
        {
            *((uint16_t*)pRxBuffer) = (USARTx->DR & (uint8_t)0xFF);
        }
        else
        {
            *((uint16_t*)pRxBuffer) = (USARTx->DR & (uint8_t)0x7F);
        }
    }
}

/**
 * @brief Waits for the transmission to complete.
 * @param USARTx: Specifies the USART peripheral. This parameter can be USART1, USART2, or USART3.
 * @return None
 */
void MCAL_UART_WAIT_TC(USART_TypeDef *USARTx)
{
    while (!(USARTx->SR & (1 << 6)));
}

/**
 * @brief Configures the GPIO pins for the specified USART peripheral.
 * @param USARTx: Specifies the USART peripheral. This parameter can be USART1, USART2, or USART3.
 * @return None
 */
void MCAL_UART_GPIO_Set_Pins(USART_TypeDef *USARTx)
{
    GPIO_PinConfig_t PinCfg;

    if (USARTx == USART1)
    {
        // PA9 TX, PA10 RX, PA11 CTS, PA12 RTS
        PinCfg.GPIO_PinNumber = GPIO_PIN_9;
        PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
        PinCfg.GPIO_Output_Speed = GPIO_SPEED_50M;
        MCAL_GPIO_Init(GPIOA, &PinCfg);

        PinCfg.GPIO_PinNumber = GPIO_PIN_10;
        PinCfg.GPIO_MODE = GPIO_MODE_AF_INPUT;
        MCAL_GPIO_Init(GPIOA, &PinCfg);

        if (GL_USART1->HwFlowCtl == UART_HwFlowCtl_CTS || GL_USART1->HwFlowCtl == UART_HwFlowCtl_RTS_CTS)
        {
            PinCfg.GPIO_PinNumber = GPIO_PIN_11;
            PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
            MCAL_GPIO_Init(GPIOA, &PinCfg);
        }

        if (GL_USART1->HwFlowCtl == UART_HwFlowCtl_RTS || GL_USART1->HwFlowCtl == UART_HwFlowCtl_RTS_CTS)
        {
            PinCfg.GPIO_PinNumber = GPIO_PIN_12;
            PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
            PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
            MCAL_GPIO_Init(GPIOA, &PinCfg);
        }
    }
    else if (USARTx == USART2)
    {
        // PA2 TX, PA3 RX, PA0 CTS, PA1 RTS
        PinCfg.GPIO_PinNumber = GPIO_PIN_2;
        PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
        PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
        MCAL_GPIO_Init(GPIOA, &PinCfg);

        PinCfg.GPIO_PinNumber = GPIO_PIN_3;
        PinCfg.GPIO_MODE = GPIO_MODE_AF_INPUT;
        MCAL_GPIO_Init(GPIOA, &PinCfg);

        if (GL_USART2->HwFlowCtl == UART_HwFlowCtl_CTS || GL_USART2->HwFlowCtl == UART_HwFlowCtl_RTS_CTS)
        {
            PinCfg.GPIO_PinNumber = GPIO_PIN_0;
            PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
            MCAL_GPIO_Init(GPIOA, &PinCfg);
        }

        if (GL_USART2->HwFlowCtl == UART_HwFlowCtl_RTS || GL_USART2->HwFlowCtl == UART_HwFlowCtl_RTS_CTS)
        {
            PinCfg.GPIO_PinNumber = GPIO_PIN_1;
            PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
            PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
            MCAL_GPIO_Init(GPIOA, &PinCfg);
        }
    }
    else if (USARTx == USART3)
    {
        // PB10 TX, PB11 RX, PB13 CTS, PA14 RTS
        PinCfg.GPIO_PinNumber = GPIO_PIN_10;
        PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
        PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
        MCAL_GPIO_Init(GPIOB, &PinCfg);

        PinCfg.GPIO_PinNumber = GPIO_PIN_11;
        PinCfg.GPIO_MODE = GPIO_MODE_AF_INPUT;
        MCAL_GPIO_Init(GPIOB, &PinCfg);

        if (GL_USART3->HwFlowCtl == UART_HwFlowCtl_CTS || GL_USART3->HwFlowCtl == UART_HwFlowCtl_RTS_CTS)
        {
            PinCfg.GPIO_PinNumber = GPIO_PIN_13;
            PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
            MCAL_GPIO_Init(GPIOB, &PinCfg);
        }

        if (GL_USART3->HwFlowCtl == UART_HwFlowCtl_RTS || GL_USART3->HwFlowCtl == UART_HwFlowCtl_RTS_CTS)
        {
            PinCfg.GPIO_PinNumber = GPIO_PIN_14;
            PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
            PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
            MCAL_GPIO_Init(GPIOB, &PinCfg);
        }
    }
}

// ISR
void USART1_IRQHandler(void)
{
    GL_USART1->P_IRQ_CallBack();
}

void USART2_IRQHandler(void)
{
    GL_USART2->P_IRQ_CallBack();
}

void USART3_IRQHandler(void)
{
    GL_USART3->P_IRQ_CallBack();
}
