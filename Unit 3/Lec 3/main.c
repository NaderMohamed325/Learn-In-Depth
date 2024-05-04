#define RCC_BASE_ADDR    0x40021000
#define GPIOC_BASE_ADDR  0x40011000

#define RCC_APB2ENR      (*(volatile unsigned int*)(RCC_BASE_ADDR + 0x18))
#define GPIOC_CRH        (*(volatile unsigned int*)(GPIOC_BASE_ADDR + 0x04))
#define GPIOC_ODR        (*(volatile unsigned int*)(GPIOC_BASE_ADDR + 0x0C))
#define RCC_EN           (1 << 4) // GPIOC clock enable bit
#define LED_PIN          13

void delay(int milliseconds) {
    int i;
    for (i = 0; i < milliseconds * 800; i++) {
        __asm__("nop");
    }
}

int main() {
    // Enable clock for GPIOC
    RCC_APB2ENR |= RCC_EN;

    // Configure pin as output (push-pull, max speed 2 MHz)
    GPIOC_CRH &= ~(0xF << ((LED_PIN - 8) * 4));
    GPIOC_CRH |= (0x2 << ((LED_PIN - 8) * 4));

    while (1) {
        // Turn LED on
        GPIOC_ODR |= (1 << LED_PIN);
        delay(1000);  // Delay 1 second

        // Turn LED off
        GPIOC_ODR &= ~(1 << LED_PIN);
        delay(1000);  // Delay 1 second
    }

    return 0;
}
