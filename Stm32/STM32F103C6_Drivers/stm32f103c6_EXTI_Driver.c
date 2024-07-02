/**
 * @file stm32f103c6_EXTI_Driver.c
 * @brief EXTI driver implementation for STM32F103C6 microcontroller.
 *
 * This file provides functions for initializing, updating, and deinitializing EXTI (External Interrupt)
 * configurations for STM32F103C6.
 *
 * @date June 29, 2024
 * @author Nader
 */

#include "inc/stm32f103c6_EXTI_Driver.h"
#define AFIO_GPIO_EXTI_Mapping(x)      ( \
    (x == GPIOA) ? 0 : \
    (x == GPIOB) ? 1 : \
    (x == GPIOC) ? 2 : \
    (x == GPIOD) ? 3 : 0 )
void (*G_IRQ_CllBack[16])(void);

void Enable_NVIC(uint8_t IRQ)
    {
    switch (IRQ)
	{
    case 0:
	NVIC_IRQ6_EXTI0_Enable();
	break;
    case 1:
	NVIC_IRQ7_EXTI1_Enable();
	break;
    case 2:
	NVIC_IRQ8_EXTI2_Enable();
	break;
    case 3:
	NVIC_IRQ9_EXTI3_Enable();
	break;
    case 4:
	NVIC_IRQ10_EXTI4_Enable();
	break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
	NVIC_IRQ23_EXTI5_9_Enable();
	break;
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
	NVIC_IRQ40_EXTI10_15_Enable();
	break;

	}
    }
void Disable_NVIC(uint8_t IRQ)
    {
    switch (IRQ)
	{
    case 0:
	NVIC_IRQ6_EXTI0_Disable();
	break;
    case 1:
	NVIC_IRQ7_EXTI1_Disable();
	break;
    case 2:
	NVIC_IRQ8_EXTI2_Disable();
	break;
    case 3:
	NVIC_IRQ9_EXTI3_Disable();
	break;
    case 4:
	NVIC_IRQ10_EXTI4_Disable();
	break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
	NVIC_IRQ23_EXTI5_9_Disable();
	break;
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
	NVIC_IRQ40_EXTI10_15_Disable();
	break;
	}
    /**
     * @brief Initializes GPIO EXTI configuration.
     *
     * This function initializes the EXTI configuration based on the provided configuration structure.
     *
     * @param EXTI_Cfg Pointer to an EXTI_PinConfig_t structure that contains the configuration parameters.
     */
    void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t *EXTI_Cfg)
	{
	Update_EXTI(EXTI_Cfg);
	}

    /**
     * @brief Updates GPIO EXTI configuration.
     *
     * This function updates the EXTI configuration based on the provided configuration structure.
     *
     * @param EXTI_Cfg Pointer to an EXTI_PinConfig_t structure that contains the updated configuration parameters.
     */
    void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t *EXTI_Cfg)
	{
	Update_EXTI(EXTI_Cfg);
	}

    /**
     * @brief Deinitializes GPIO EXTI configuration.
     *
     * This function resets all EXTI registers and disables NVIC interrupts associated with EXTI.
     */
    void MCAL_EXTI_GPIO_Deinit()
	{
	EXTI->IMR = 0X00000000;
	EXTI->EMR = 0X00000000;
	EXTI->RTSR = 0X00000000;
	EXTI->SWIER = 0X00000000;
	EXTI->FTSR = 0X00000000;
	EXTI->PR = 0XFFFFFFFF;
	NVIC_IRQ6_EXTI0_Disable();
	NVIC_IRQ7_EXTI1_Disable();
	NVIC_IRQ8_EXTI2_Disable();
	NVIC_IRQ9_EXTI3_Disable();
	NVIC_IRQ10_EXTI4_Disable();
	NVIC_IRQ23_EXTI5_9_Disable();
	NVIC_IRQ40_EXTI10_15_Disable();
	}

    /**
     * @brief Updates EXTI configuration.
     *
     * This function updates the EXTI configuration based on the provided configuration structure.
     *
     * @param EXTI_Cfg Pointer to an EXTI_PinConfig_t structure that contains the updated configuration parameters.
     * @note This function is static and should not be called directly from outside this file.
     */
    void Update_EXTI(EXTI_PinConfig_t *EXTI_Cfg)
	{
	// Implement EXTI configuration update based on EXTI_Cfg
	GPIO_PinConfig_t PinCFG;
	PinCFG.GPIO_MODE = GPIO_MODE_AF_INPUT;
	PinCFG.GPIO_PinNumber = EXTI_Cfg->EXI_Pin.GPIO_Pin;
	MCAL_GPIO_Init(EXTI_Cfg->EXI_Pin.GPIOx, &PinCFG);

	//Update the Port

	uint8_t AFIO_EXTICR_index = (EXTI_Cfg->EXI_Pin.EXTI_InputLine_Number)
		/ 4;
	uint8_t AFIO_EXTICR_Position = (EXTI_Cfg->EXI_Pin.EXTI_InputLine_Number)
		% 4;
	//clear afio register
	AFIO->EXTICR[AFIO_EXTICR_index] &= ~(0XF << AFIO_EXTICR_Position);
	AFIO->EXTICR[AFIO_EXTICR_index] |=
		((AFIO_GPIO_EXTI_Mapping(EXTI_Cfg->EXI_Pin.GPIOx) & 0XF)
			<< AFIO_EXTICR_Position);
	//--------------------------------------------------------------------------------------------------------------------//

	EXTI->RTSR &= ~(1 << EXTI_Cfg->EXI_Pin.EXTI_InputLine_Number);
	EXTI->FTSR &= ~(1 << EXTI_Cfg->EXI_Pin.EXTI_InputLine_Number);

	if (EXTI_Cfg->Trigger_Case == EXTI_Trigger_FALLING)
	    {
	    EXTI->FTSR |= (1 << EXTI_Cfg->EXI_Pin.EXTI_InputLine_Number);

	    }
	else if (EXTI_Cfg->Trigger_Case == EXTI_Trigger_RISING)
	    {
	    EXTI->RTSR |= (1 << EXTI_Cfg->EXI_Pin.EXTI_InputLine_Number);
	    }
	else if (EXTI_Cfg->Trigger_Case == EXTI_Trigger_RISING_AND_FALLING)
	    {
	    EXTI->RTSR |= (1 << EXTI_Cfg->EXI_Pin.EXTI_InputLine_Number);
	    EXTI->FTSR |= (1 << EXTI_Cfg->EXI_Pin.EXTI_InputLine_Number);
	    }
	G_IRQ_CllBack[EXTI_Cfg->EXI_Pin.EXTI_InputLine_Number] =
		EXTI_Cfg->P_IRQ_CallBack;
	if (EXTI_Cfg->IRQ_EN == EXTI_IRQ_Enable)
	    {
	    EXTI->IMR |= (1 << EXTI_Cfg->EXI_Pin.EXTI_InputLine_Number);
	    Enable_NVIC(EXTI_Cfg->EXI_Pin.EXTI_InputLine_Number);
	    }
	else if (EXTI_Cfg->IRQ_EN == EXTI_IRQ_Disable)
	    {
	    EXTI->IMR &= ~(1 << EXTI_Cfg->EXI_Pin.EXTI_InputLine_Number);
	    Disable_NVIC(EXTI_Cfg->EXI_Pin.EXTI_InputLine_Number);
	    }

	}
    void EXTI0_IRQHandler(void)
	{
	EXTI->PR |= (1 << 0);
	G_IRQ_CllBack[0]();

	}
    void EXTI1_IRQHandler(void)
	{
	EXTI->PR |= (1 << 1);
	G_IRQ_CllBack[1]();
	}

    void EXTI2_IRQHandler(void)
	{
	EXTI->PR |= (1 << 2);
	G_IRQ_CllBack[2]();
	}

    void EXTI3_IRQHandler(void)
	{
	EXTI->PR |= (1 << 3);
	G_IRQ_CllBack[3]();
	}
    void EXTI4_IRQHandler(void)
	{
	EXTI->PR |= (1 << 4);
	G_IRQ_CllBack[4]();
	}
    void EXTI9_5_IRQHandler(void)
	{
	if (EXTI->PR & 1 << 5)
	    {
	    EXTI->PR |= (1 << 5);
	    G_IRQ_CllBack[5]();
	    }
	if (EXTI->PR & 1 << 6)
	    {
	    EXTI->PR |= (1 << 6);
	    G_IRQ_CllBack[6]();
	    }
	if (EXTI->PR & 1 << 7)
	    {
	    EXTI->PR |= (1 << 7);
	    G_IRQ_CllBack[7]();
	    }
	if (EXTI->PR & 1 << 8)
	    {
	    EXTI->PR |= (1 << 8);
	    G_IRQ_CllBack[8]();
	    }
	if (EXTI->PR & 1 << 9)
	    {
	    EXTI->PR |= (1 << 9);
	    G_IRQ_CllBack[9]();
	    }
	}

    void EXTI10_15_IRQHandler(void)
	{
	if (EXTI->PR & 1 << 10)
	    {
	    EXTI->PR |= (1 << 10);
	    G_IRQ_CllBack[10]();
	    }
	if (EXTI->PR & 1 << 11)
	    {
	    EXTI->PR |= (1 << 11);
	    G_IRQ_CllBack[11]();
	    }
	if (EXTI->PR & 1 << 12)
	    {
	    EXTI->PR |= (1 << 12);
	    G_IRQ_CllBack[12]();
	    }
	if (EXTI->PR & 1 << 13)
	    {
	    EXTI->PR |= (1 << 13);
	    G_IRQ_CllBack[13]();
	    }
	if (EXTI->PR & 1 << 14)
	    {
	    EXTI->PR |= (1 << 14);
	    G_IRQ_CllBack[14]();
	    }
	if (EXTI->PR & 1 << 15)
	    {
	    EXTI->PR |= (1 << 15);
	    G_IRQ_CllBack[15]();
	    }
	}}


