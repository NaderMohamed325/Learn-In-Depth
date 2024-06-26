#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef volatile unsigned int vuint32_t;

#define RCC_BASE     0x40021000
#define RCC_APB2ENR  *(volatile uint32_t *)(RCC_BASE + 0x18)
#define RCC_CFGR     *(volatile uint32_t *)(RCC_BASE + 0x04)
#define RCC_CR       *(volatile uint32_t *)(RCC_BASE + 0x00)
#define RCC_IOPAEN   (1<<2)
#define RCC_IOPBEN   (1<<3)

#define GPIOA_BASE   0x40010800
#define GPIOA_CRH    *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR    *(volatile uint32_t *)(GPIOA_BASE + 0x0C)
#define GPIOA_CRL    *(volatile uint32_t *)(GPIOA_BASE + 0x00)
#define GPIOA_IDR    *(volatile uint32_t *)(GPIOA_BASE + 0x08)

#define GPIOB_BASE   0x40010C00
#define GPIOB_CRH    *(volatile uint32_t *)(GPIOB_BASE + 0x04)
#define GPIOB_ODR    *(volatile uint32_t *)(GPIOB_BASE + 0x0C)
#define GPIOB_CRL    *(volatile uint32_t *)(GPIOB_BASE + 0x00)
#define GPIOB_IDR    *(volatile uint32_t *)(GPIOB_BASE + 0x08)

#define EXTI_BASE    0x40010400
#define EXTI_IMR     *(volatile uint32_t *)(EXTI_BASE + 0x00)
#define EXTI_RTSR    *(volatile uint32_t *)(EXTI_BASE + 0x08)
#define EXTI_PR      *(volatile uint32_t *)(EXTI_BASE + 0x14)

#define AFIO_BASE    0x40010000
#define AFIO_EXTICR1 *(volatile uint32_t *)(AFIO_BASE + 0x08)

#define NVIC_ISER0   *(volatile uint32_t *)(0xE000E100)

#define LED_PIN      (1 << 7)

void delay(uint32_t count) {
	for (uint32_t i = 0; i < count; i++) {
		asm("nop");
	}
}

void clock_init() {
	RCC_APB2ENR |= RCC_IOPAEN;  // Enable GPIOA clock
	RCC_APB2ENR |= RCC_IOPBEN;  // Enable GPIOB clock

}

void GPIO_init() {

	/* A1 input High Z                   // CNF1 = 0// CNF0 = 1// MODE1 = 0// MODE0 = 0//
	 * B1 output Push_Pull mode         // CNF1 = 0// CNF0 = 0// MODE1 = 0// MODE0 = 1//
	 * A13 input High Z                // CNF1 = 0// CNF0 = 0// MODE1 = 0// MODE0 = 0//
	 * B13 output push_pull mode      // CNF1 = 0// CNF0 = 1// MODE1 = 0// MODE0 = 1//
	 */
	GPIOA_CRL = 0;
	GPIOA_CRL |= 1 << 6; //A1 DONE

	GPIOB_CRL = 0;
	GPIOB_CRL &= ~(0b11 << 6); //B1 DONE
	GPIOB_CRL |= (0b01 << 4); //B1 DONE

	GPIOA_CRH = 0;
	GPIOA_CRH &= ~(0b11 << 20); //B1 DONE
	GPIOA_CRH |= (0b01 << 22); //B13 DONE

	GPIOB_CRH = 0;
	GPIOB_CRH |= (0b01 << 20); //B1 DONE
	GPIOB_CRH &= ~(0b11 << 22); //B13 DONE

}

int main(void) {
	GPIO_init();
	clock_init();

	while (1) {
		if (((GPIOA_IDR & (1 << 1)) >> 1) == 0) {
			GPIOB_ODR ^= (1 << 1);
			while (((GPIOA_IDR & (1 << 1)) >> 1) == 0)
				;
		}

		if (((GPIOA_IDR & (1 << 13)) >> 13) == 0) {
			GPIOB_ODR ^= (1 << 13);
		}
		delay(500);

	}
}

