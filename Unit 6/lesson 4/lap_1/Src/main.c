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
#define GPIOA_CRL    *(volatile uint32_t *)(GPIOA_BASE + 0x00)

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
    RCC_APB2ENR |= 1 << 0;      // Enable AFIO clock
}

void GPIO_init() {
    GPIOA_CRL &= 0xF0FFFFFF;  // Clear CNF and MODE bits for PA7
    GPIOA_CRL |= 0x02000000;  // Set MODE7 to output mode (max speed 2 MHz) and CNF7 to push-pull
    GPIOA_CRL |= (1 << 2);    // Set PA0 for input (external interrupt)
}

void EXTI0_IRQHandler(void) {

        GPIOA_ODR ^= LED_PIN;  // Toggle LED_PIN (PA7)
        EXTI_PR |= (1 << 0);   // Clear interrupt pending bit for EXTI line 0

}

int main(void) {
    clock_init();
    GPIO_init();

    EXTI_IMR |= (1 << 0);       // Unmask EXTI line 0
    EXTI_RTSR |= (1 << 0);      // Trigger on rising edge
    AFIO_EXTICR1 &= ~(0xF << 0); // Select PA0 as the source input for EXTI0

    NVIC_ISER0 |= (1 << 6);     // Enable EXTI0 interrupt in NVIC

    while (1) {
        // Main loop
    }
}


