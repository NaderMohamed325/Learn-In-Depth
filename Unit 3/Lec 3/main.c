#define RCC_BASE_ADDR    0x40021000
#define GPIOA_BASE_ADDR  0x40010800

#define RCC_APB2ENR      (*(volatile unsigned int*)(RCC_BASE_ADDR + 0x18))
#define GPIOA_CRH        (*(volatile unsigned int*)(GPIOA_BASE_ADDR + 0x04))
#define GPIOA_ODR        (*(volatile unsigned int*)(GPIOA_BASE_ADDR + 0x0C))
#define RCC_EN           (1 << 2)
#define LED_PIN          13UL

void delay(int milliseconds) {
    int i;
    for (i = 0; i < milliseconds * 800; i++) {
        __asm__("nop");
    }
}

int main() {
    // Enable clock for GPIOA
    RCC_APB2ENR |= RCC_EN;

    // Configure pin as output (push-pull, max speed 2 MHz)
    GPIOA_CRH &= ~(0xF << ((LED_PIN - 8) * 4));
    GPIOA_CRH |= (0x2 << ((LED_PIN - 8) * 4));

    while (1) {
        // Turn LED on
        GPIOA_ODR |= (1 << LED_PIN);
        delay(1000);  // Delay 1 second

        // Turn LED off
        GPIOA_ODR &= ~(1 << LED_PIN);
        delay(1000);  // Delay 1 second
    }

    return 0;
}
