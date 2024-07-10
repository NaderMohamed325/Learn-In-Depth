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


#include "../STM32F103C6_Drivers/inc/stm32f103c6_USART_Driver.h"
#include "../STM32F103C6_Drivers/inc/stm32f103c6_SPI_Driver.h"

unsigned char volatile ch = 0;

/**
 * @brief UART interrupt service routine.
 * This function handles received data from UART and sends it via SPI.
 */
void ISR_Uart(void) {
    MCAL_UART_ReceiveData(USART1, &ch, disable);
    MCAL_UART_SendData(USART1, &ch, disable);

    // SPI transmission
    MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0); // Select the SPI slave (CS low)
    MCAL_SPI_TX_RX(SPI1, &ch, Pollingenable);
    MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1); // Deselect the SPI slave (CS high)
}

#define MCU_Act_As_Master 1
//#define MCU_Act_As_Slave  1

int main(void) {
    // Enable necessary clocks
    RCC_GPIOA_CLK_EN();
    RCC_GPIOB_CLK_EN();
    RCC_USART1_CLK_EN();
    RCC_SPI1_CLK_EN();
    RCC->APB2ENR |= (1 << 0); // Enable AFIO clock

    // UART configuration
    UART_Config uart;
    uart.BaudRate = UART_BaudRate_9600;
    uart.HwFlowCtl = UART_HwFlowCtl_NONE;
    uart.IRQ_Enable = UART_IRQ_Enable_RXNEIE;
    uart.P_IRQ_CallBack = ISR_Uart; // Set UART interrupt callback
    uart.Parity = UART_Parity__NONE;
    uart.Payload_Length = UART_Payload_Length_8B;
    uart.StopBits = UART_StopBits__1;
    uart.USART_Mode = UART_MODE_TX_RX;

    MCAL_UART_Init(USART1, &uart);
    MCAL_UART_GPIO_Set_Pins(USART1);

    // SPI configuration
    SPI_Config SPI1CFG;
    SPI1CFG.CLKPhase = SPI_Clock_Phase_2EDGE_first_data_capture_edge;
    SPI1CFG.CLKPolarity = SPI_CLKPolarity_HIGH_when_idle;
    SPI1CFG.DataSize = SPI_DataSize_8BIT;
    SPI1CFG.Frame_Format = SPI_Frame_Format_MSB_transmitted_first;
    SPI1CFG.SPI_BAUDRATEPRESCALER = SPI_BAUDRATEPRESCALER_8;

#ifdef MCU_Act_As_Master
    SPI1CFG.Device_Mode = SPI_Device_Mode_MASTER;
    SPI1CFG.Communication_Mode = SPI_DIRECTION_2LINES;
    SPI1CFG.IRQ_Enable = SPI_IRQ_Enable_NONE;
    SPI1CFG.NSS = SPI_NSS_Soft_NSSInternalSoft_Set;
    SPI1CFG.P_IRQ_CallBack = NULL;
#endif

#ifdef MCU_Act_As_Slave
    // Slave configuration can be added here
#endif
    GPIO_PinConfig_t PinCfg1;
    PinCfg1.GPIO_PinNumber = GPIO_PIN_4;
    PinCfg1.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
    PinCfg1.GPIO_Output_Speed = GPIO_SPEED_10M;
    MCAL_GPIO_Init(GPIOA, &PinCfg1);
    MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);



    MCAL_SPI_GPIO_Set_Pins(SPI1);
    MCAL_SPI_Init(SPI1, &SPI1CFG);

    // GPIO configuration for SPI CS pin


    // Deselect the SPI slave initially (CS high)


    while (1) {
        // Main loop can be used for other tasks
    }
}
