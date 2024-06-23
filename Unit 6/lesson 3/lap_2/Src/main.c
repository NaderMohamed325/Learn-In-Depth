#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef volatile unsigned int vuint32_t;

#define RCC_BASE     0x40021000
#define RCC_APB2ENR  *(volatile uint32_t *)(RCC_BASE + 0x18)
#define RCC_CFGR     *(volatile uint32_t *)(RCC_BASE + 0x04)
#define RCC_CR       *(volatile uint32_t *)(RCC_BASE + 0x00)
#define RCC_IOPAEN   (1<<2)

#define GPIOA_BASE   0x40010800
#define GPIOA_CRH    *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR    *(volatile uint32_t *)(GPIOA_BASE + 0x0C)

#define LED_PIN      (1<<5)

void delay(uint32_t count) {
    for (uint32_t i = 0; i < count; i++) {
        asm("nop");
    }
}

int main(void) {

	RCC_CFGR  |= 0b100 <<8 ;
	RCC_CFGR  |= 0b0110 <<18 ;
	RCC_CFGR  |= 0b10 <<0 ;
	RCC_CR |= 1 <<24 ;
    RCC_APB2ENR |= RCC_IOPAEN;


    GPIOA_CRH &= 0xFF0FFFFF;
    GPIOA_CRH |= 0x00200000;

    while (1) {

        GPIOA_ODR ^= LED_PIN;
        delay(100000);
    }

    return 0;
}
