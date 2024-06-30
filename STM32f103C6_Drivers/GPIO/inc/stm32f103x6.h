/*
 * stm32f103x6.h
 *
 *  Created on: Jun 29, 2024
 *      Author: Nader
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define F_CPU 8000000UL
//Base addresses for Memories
#define FLASH_MEMORY_BASE  0X08000000UL
#define System_MEMORY_BASE 0X1FFFF000UL
#define SRAM_MEMORY_BASE   0X08000000UL

#define Peripherals_BASE   0x40000000UL
#define CortexM3_IP_BASE   0xE0000000UL
//Base addresses for AHB Peripheral
#define RCC_BASE           0x40021000UL
//Base addresses for APB2 Peripheral
//A and B fully included in LQFP48
#define GPIOA_BASE         0x40010800UL
#define GPIOB_BASE         0x40010C00UL
//C and D partial included in LQFP48
#define GPIOC_BASE         0x40011000UL
#define GPIOD_BASE         0x40011400UL
// E and F NOT included in LQFP48
#define GPIOE_BASE         0x40011800UL
#define GPIOF_BASE         0x40011C00UL
//EXTI
#define EXTI_BASE          0x40010400UL
//AFIO
#define AFIO_BASE          0x40010000UL

//Base addresses for APB1 Peripheral

//

//Peripheral register:GPIO
typedef struct {
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
} GPIO_TypeDef;

//Peripheral register:RCC
typedef struct {
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
} RCC_TypeDef;

//Peripheral register:EXTI
typedef struct {
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
} EXTI_TypeDef;

typedef struct {
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	volatile uint32_t RESERVED;
	volatile uint32_t MAPR2;
} AFIO_TypeDef;
//Peripheral Instants:
#define GPIOA     				 ((GPIO_TypeDef*)GPIOA_BASE)
#define GPIOB      				 ((GPIO_TypeDef*)GPIOB_BASE)
#define GPIOC     				 ((GPIO_TypeDef*)GPIOC_BASE)
#define GPIOD     				 ((GPIO_TypeDef*)GPIOD_BASE)
#define GPIOE      				 ((GPIO_TypeDef*)GPIOE_BASE)
#define GPIOF      				 ((GPIO_TypeDef*)GPIOF_BASE)

#define RCC        			     ((RCC_TypeDef*)RCC_BASE)

#define EXTI       			     ((EXTI_TypeDef*)EXTI_BASE)

#define AFIO     				 ((AFIO_TypeDef*)AFIO_BASE)

//clock enable Macros:
#define RCC_GPIOA_CLK_EN()       (RCC->APB2ENR |=1<<2)
#define RCC_GPIOB_CLK_EN()       (RCC->APB2ENR |=1<<3)
#define RCC_GPIOC_CLK_EN()       (RCC->APB2ENR |=1<<4)
#define RCC_GPIOD_CLK_EN()       (RCC->APB2ENR |=1<<5)
#define RCC_GPIOE_CLK_EN()       (RCC->APB2ENR |=1<<6)

#define AFIO_GPIOE_CLK_EN()      (RCC->APB2ENR |=1<<0)













//Generic Macros:

#endif /* INC_STM32F103X6_H_ */
