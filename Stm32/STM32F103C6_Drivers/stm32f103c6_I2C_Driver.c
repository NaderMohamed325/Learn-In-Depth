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
    uint16_t tempreg = 0, freqrange = 0, result = 0;
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
	tempreg &= ~(I2C_CR2_FREQ_Msk);
	pclk = MCAL_RCC_GetPCLK1Freq();
	freqrange = (uint16_t) ((pclk) / 1000000);
	tempreg |= freqrange;
	I2Cx->I2C_CR2 = tempreg;
//---------------------------------------------------------//
	I2Cx->I2C_CR1 &= ~(I2C_CR1_PE);
	tempreg = 0;
	if (I2C_InitStruct->I2C_ClockSpeed == I2C_SCLK_SM_50K
		|| I2C_InitStruct->I2C_ClockSpeed == I2C_SCLK_SM_100K)
	    {
	    result = (uint16_t) (pclk / (I2C_InitStruct->I2C_ClockSpeed << 1));
	    tempreg |= result;
	    I2Cx->I2C_CCR = tempreg;
	    I2Cx->I2C_TRISE = freqrange + 1;
	    }
	tempreg = I2Cx->I2C_CR1;
	tempreg |= (uint16_t) (I2C_InitStruct->I2C_Ack_Control
		| I2C_InitStruct->General_Call_Address_Detection
		| I2C_InitStruct->I2C_Mode | I2C_InitStruct->StretchMode);
	I2Cx->I2C_CR1 = tempreg;
	if (I2C_InitStruct->I2C_Slave_address.Enable_Dual_Add == 1)
	    {
	    tempreg = I2C_OAR2_ENDUAL;
	    tempreg |= I2C_InitStruct->I2C_Slave_address.Secondary_Add
		    << I2C_OAR2_ADD2_Pos;
	    I2Cx->I2C_OAR2 = tempreg;

	    }
	tempreg = 0;
	tempreg |= I2C_InitStruct->I2C_Slave_address.First_Add << 1;
	tempreg |= I2C_InitStruct->I2C_Slave_address.I2C_Addressing_Mode;

	}
    if (I2C_InitStruct->P_Slave_Event_CallBack != NULL)
	{
	I2Cx->I2C_CR2 |= (I2C_CR2_ITERREN);
	I2Cx->I2C_CR2 |= (I2C_CR2_ITEVTEN);
	I2Cx->I2C_CR2 |= (I2C_CR2_ITBUFEN);
	}
    if (I2Cx == I2C1)
	{
	NVIC_IRQ31_I2C1_EV_Enable();NVIC_IRQ32_I2C1_EV_Enable();
	}
    else if (I2Cx == I2C2)
	{
	NVIC_IRQ33_I2C2_EV_Enable();NVIC_IRQ34_I2C2_EV_Enable();
	}
    I2Cx->I2C_SR1 = 0;
    I2Cx->I2C_SR2 = 0;

    I2Cx->I2C_CR1 |= I2C_CR1_PE;
    }
void MCAL_I2C_DInit(I2C_TypeDef *I2Cx)
    {
    if (I2Cx == I2C1)
	{
	NVIC_IRQ31_I2C1_EV_Disable();
	NVIC_IRQ32_I2C1_EV_Disable();
	RCC_I2C1_Reset();
	}
    else if (I2Cx == I2C2)
	{
	NVIC_IRQ33_I2C2_EV_Disable();
	NVIC_IRQ34_I2C2_EV_Disable();
	RCC_I2C2_Reset();
	}
    }
void MCAL_I2C_GPIO_Set_Pins(I2C_TypeDef *I2Cx)
    {

    GPIO_PinConfig_t PinCfg;
    PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_OD;
    PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
    if (I2Cx == I2C1)
	{
	PinCfg.GPIO_PinNumber = GPIO_PIN_6;
	MCAL_GPIO_Init(GPIOB, &PinCfg);
	PinCfg.GPIO_PinNumber = GPIO_PIN_7;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	}
    else if (I2Cx == I2C2)
	{
	PinCfg.GPIO_PinNumber = GPIO_PIN_10;
	MCAL_GPIO_Init(GPIOB, &PinCfg);
	PinCfg.GPIO_PinNumber = GPIO_PIN_11;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

	}

    }
void MCAL_I2C_Master_TX(I2C_TypeDef *I2Cx, uint16_t devAddr, uint8_t *dataOut,
	uint32_t dataLen, Stop_Condition Stop, Repeated_Start start)
    {
    int i = 0;
    I2C_GenerateSTART(I2Cx, ENABLE, start);
    while (!I2C_GetFlagStatus(I2Cx, EV5))
	;
    I2C_SendAddress(I2Cx, devAddr, I2C_Direction_Transmitter);
    while (!I2C_GetFlagStatus(I2Cx, EV6))
	;
    while (!I2C_GetFlagStatus(I2Cx, MASTER_BYTE_TRANSMITTING))
	;
    for (i = 0; i < dataLen; ++i)
	{
	I2Cx->I2C_DR = dataOut[i];
	while (!I2C_GetFlagStatus(I2Cx, EV8))
	    ;
	}
    if (Stop == With_Stop)
	{
	I2C_GenerateSTOP(I2Cx, ENABLE);
	}

    }
void MCAL_I2C_Master_RX(I2C_TypeDef *I2Cx, uint16_t devAddr, uint8_t *dataOut,
	uint32_t dataLen, Stop_Condition Stop, Repeated_Start start)
    {
    int i = 0;
    I2C_GenerateSTART(I2Cx, ENABLE, start);
    while (!I2C_GetFlagStatus(I2Cx, EV5))
	;
    I2C_SendAddress(I2Cx, devAddr, I2C_Direction_Recieve);
    while (!I2C_GetFlagStatus(I2Cx, EV6))
	;
    I2C_AcknowledgeConfig(I2Cx, ENABLE);
    if (dataLen)
	{
	for (i = dataLen; i > 1; i--)
	    {
	    while (!I2C_GetFlagStatus(I2Cx, EV7))
		;
	    I2Cx->I2C_DR = dataOut[i];
	    dataOut++;

	    }

	I2C_AcknowledgeConfig(I2Cx, DISABLE);
	}
    int index = I2Cx == I2C1 ? I2C1_INDEX : I2C2_INDEX;
    if (Stop == With_Stop)
	{
	I2C_GenerateSTOP(I2Cx, ENABLE);
	}
    if (Global_I2C_Config[index].I2C_Ack_Control == I2C_ACK_Enable)
	{
	I2C_AcknowledgeConfig(I2Cx, ENABLE);
	}
    }

//Slave interrupt mechanism
void MCAL_I2C_SlaveSendData(I2C_TypeDef *I2Cx, uint8_t data)
    {
    I2Cx->I2C_DR = data;
    }

uint8_t MCAL_I2C_SlaveReceiveData(I2C_TypeDef *I2Cx)
    {
    return (uint8_t) I2Cx->I2C_DR;
    }

//Generic APIs

void I2C_GenerateSTART(I2C_TypeDef *I2Cx, FunctionalState NewState,
	Repeated_Start start)
    {
    if (start != repeated_start)
	{
	while (I2C_GetFlagStatus(I2Cx, I2C_FLAG_BUSY))
	    ;
	}
    //	Bit 8 START: Start generation
    //	This bit is set and cleared by software and cleared by hardware when start is sent or PE=0.
    //	In Master Mode:
    //	0: No Start generation
    //	1: Repeated start generation
    //	In Slave mode:
    //	0: No Start generation
    //	1: Start generation when the bus is free

    if (NewState != DISABLE)
	{
	/* Generate a START condition */
	I2Cx->I2C_CR1 |= I2C_CR1_START;
	}
    else
	{
	/* Disable the START condition generation */
	I2Cx->I2C_CR1 &= ~(I2C_CR1_START);
	}

    }

FlagStatus I2C_GetFlagStatus(I2C_TypeDef *I2Cx, Status flag)
    {
    uint32_t flag1 = 0, flag2 = 0;
    uint32_t lastevent = 0;
    FlagStatus bitstatus = RESET;
    switch (flag)
	{
    case I2C_FLAG_BUSY:
	{
	if ((I2Cx->I2C_SR2) & (I2C_SR2_BUSY))
	    bitstatus = SET;
	else
	    bitstatus = RESET;
	break;
	}
    case EV5:
	{
	//	EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
	//		Bit 0 SB: Start bit (Master mode)
	//		0: No Start condition
	//		1: Start condition generated.
	//		– Set when a Start condition generated.
	//		– Cleared by software by reading the SR1 register followed by writing the DR register, or by
	//		hardware when PE=0
	if ((I2Cx->I2C_SR1) & (I2C_SR1_SB))
	    bitstatus = SET;
	else
	    bitstatus = RESET;
	break;
	}
    case EV6:
	{
	//		EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2.
	//Bit 1 ADDR: Address sent (master mode)/matched (slave mode)
	if (((I2Cx->I2C_SR1) & (I2C_SR1_ADDR)))
	    bitstatus = SET;
	else
	    bitstatus = RESET;

	break;
	}
    case MASTER_BYTE_TRANSMITTING:
	{
	/* Read the I2Cx status register */
	flag1 = I2Cx->I2C_SR1;
	flag2 = I2Cx->I2C_SR2;
	flag2 = flag2 << 16;
	/* Get the last event value from I2C status register */
	lastevent = (flag1 | flag2) & ((uint32_t) 0x00FFFFFF);
	/* Check whether the last event contains the I2C_EVENT */
	if ((lastevent & flag) == flag)
	    {
	    /* SUCCESS: last event is equal to I2C_EVENT */
	    bitstatus = SET;
	    }
	else
	    {
	    /* ERROR: last event is different from I2C_EVENT */
	    bitstatus = RESET;
	    }

	}

    case EV8_1: // EV8_1: TxE=1, shift register empty, data register empty, write Data1 in DR.
    case EV8: //EV8: TxE=1, shift register not empty, d . ata register empty, cleared by writing DR register
	{
	//		Bit 7 TxE: Data register empty (transmitters)
	//		0: Data register not empty
	//		1: Data register empty
	if (((I2Cx->I2C_SR1) & (I2C_SR1_TXE)))
	    bitstatus = SET;
	else
	    bitstatus = RESET;
	break;
	}
    case EV7:
	{
	//		Bit 6 RxNE: Data register not empty (receivers)
	//		0: Data register empty
	//		1: Data register not empty
	//		– Set when data register is not empty in receiver mode. RxNE is not set during address phase.
	//		– Cleared by software reading or writing the DR register or by hardware when PE=0.
	//		RxNE is not set in case of ARLO event.
	if (((I2Cx->I2C_SR1) & (I2C_SR1_RXNE)))
	    bitstatus = SET;
	else
	    bitstatus = RESET;
	break;
	}
	}

    return bitstatus;
    }

void I2C_SendAddress(I2C_TypeDef *I2Cx, uint16_t Address,
	I2C_Direction Direction)
    {
    Address = Address << 1;
    if (Direction != I2C_Direction_Transmitter)
	Address |= 1 << 0;
    else
	Address &= ~(1 << 0);

    I2Cx->I2C_DR = Address;
    }

void I2C_GenerateSTOP(I2C_TypeDef *I2Cx, FunctionalState NewState)
    {
    if (NewState != DISABLE)
	{
	I2Cx->I2C_CR1 |= I2C_CR1_STOP;
	}
    else
	{
	I2Cx->I2C_CR1 &= ~(I2C_CR1_STOP);
	}

    }

void I2C_AcknowledgeConfig(I2C_TypeDef *I2Cx, FunctionalState NewState)
    {
    if (NewState != DISABLE)
	{
	/* Enable the acknowledgement */
	I2Cx->I2C_CR1 |= I2C_CR1_ACK;
	}
    else
	{
	/* Disable the acknowledgement */
	I2Cx->I2C_CR1 &= ~(I2C_CR1_ACK);
	}
    }

void I2C1_ER_IRQHandler(void)
    {

    }

void I2C1_EV_IRQHandler(void)
    {
    volatile uint32_t dummy_read = 0;
    I2C_TypeDef *I2Cx = I2C1;
    //Interrupt handling for both master and slave mode of a device
    uint32_t temp1, temp2, temp3;

    temp1 = I2Cx->I2C_CR2 & ( I2C_CR2_ITEVTEN);
    temp2 = I2Cx->I2C_CR2 & ( I2C_CR2_ITBUFEN);
    temp3 = I2Cx->I2C_SR1 & ( I2C_SR1_STOPF);

    // Handle For interrupt generated by STOPF event
    // Note : Stop detection flag is applicable only slave mode
    if (temp1 && temp3)
	{
	//STOF flag is set
	//Clear the STOPF ( i.e 1) read SR1 2) Write to CR1 )
	I2Cx->I2C_CR1 |= 0x0000;
	Slave_States(I2Cx, I2C_EV_STOP);

	}
    //----------------------------------------------------------
    temp3 = I2Cx->I2C_SR1 & (I2C_SR1_ADDR);
    // Handle For interrupt generated by ADDR event
    //Note : When master mode : Address is sent
    //		 When Slave mode   : Address matched with own address
    if (temp1 && temp3)
	{
	// interrupt is generated because of ADDR event
	//check for device mode
	if (I2Cx->I2C_SR2 & ( I2C_SR2_MSL))
	    {
	    //master

	    }
	else
	    {
	    //slave mode
	    //clear the ADDR flag ( read SR1 , read SR2)
	    dummy_read = I2Cx->I2C_SR1;
	    dummy_read = I2Cx->I2C_SR2;
	    Slave_States(I2Cx, I2C_EV_ADDR_Matched);

	    }
	}
    //----------------------------------------------------------

    temp3 = I2Cx->I2C_SR1 & ( I2C_SR1_TXE);
    // Handle For interrupt generated by TXE event
    if (temp1 && temp2 && temp3)
	{
	//Check for device mode
	if (I2Cx->I2C_SR2 & (I2C_SR2_MSL))
	    {

	    }
	else
	    {
	    //slave
	    Slave_States(I2Cx, I2C_EV_DATA_REQ);
	    }
	}

    //----------------------------------------------------------

    temp3 = I2Cx->I2C_SR1 & ( I2C_SR1_RXNE);
    // Handle For interrupt generated by 	SB=1, cleared by reading SR1 register followed by writing DR register with Address.
    if (temp1 && temp2 && temp3)
	{
	//check device mode .
	if (I2Cx->I2C_SR2 & ( I2C_SR2_MSL))
	    {
	    //The device is master

	    }
	else
	    {
	    //slave
	    Slave_States(I2Cx, I2C_EV_DATA_RCV);

	    }
	}

    }
void Slave_States(I2C_TypeDef *I2Cx, Slave_State state)
    {
    uint8_t index = I2Cx == I2C1 ? I2C1_INDEX : I2C2_INDEX;

    switch (state)
	{

    case I2C_ERROR_AF:
	{
	//make sure that the slave is really in transmitter mode
	if (I2Cx->I2C_SR2 & ( I2C_SR2_TRA))
	    {
	    //Slave Shouldn't Send anything else

	    }

	break;
	}

    case I2C_EV_STOP:
	{
	//make sure that the slave is really in transmitter mode
	if (I2Cx->I2C_SR2 & ( I2C_SR2_TRA))
	    {
	    //Notify APP that the Stop Condition is sent by the master
	    Global_I2C_Config[index].P_Slave_Event_CallBack(I2C_EV_STOP);
	    }

	break;
	}

    case I2C_EV_ADDR_Matched:
	{
	//Notify APP that the Stop Condition is sent by the master
	Global_I2C_Config[index].P_Slave_Event_CallBack(I2C_EV_ADDR_Matched);

	break;
	}

    case I2C_EV_DATA_REQ:
	{
	//make sure that the slave is really in transmitter mode
	if (I2Cx->I2C_SR2 & ( I2C_SR2_TRA))
	    {
	    //the APP layer should send the data (MCAL_I2C_SlaveSendData ) in this state
	    Global_I2C_Config[index].P_Slave_Event_CallBack(I2C_EV_DATA_REQ);
	    }

	break;
	}
    case I2C_EV_DATA_RCV:
	{
	//make sure that the slave is really in receiver mode
	if (!(I2Cx->I2C_SR2 & ( I2C_SR2_TRA)))
	    {
	    //the APP layer should read the data (MCAL_I2C_SlaveReceiveData ) in this state
	    Global_I2C_Config[index].P_Slave_Event_CallBack(I2C_EV_DATA_RCV);
	    }

	break;
	}
	}

    }

void I2C2_ER_IRQHandler(void)
    {

    }

void I2C2_EV_IRQHandler(void)
    {

    }

