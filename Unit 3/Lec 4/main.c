#include <stdint.h>

#define SYSCTL_RCGC2_R     (*((volatile uint32_t *)0x400FE108))
#define GPIO_PORTF_DIR_R   (*((volatile uint32_t *)0x40025400))
#define GPIO_PORTF_DEN_R   (*((volatile uint32_t *)0x4002551C))
#define GPIO_PORTF_DATA_R  (*((volatile uint32_t *)0x400253FC))

#define LED_PIN 3  

void delay(uint32_t milliseconds) {
    uint32_t i, j;
    for (i = 0; i < milliseconds; i++) {
        for (j = 0; j < 800; j++) {
            __asm__("NOP");
        }
    }
}

int main() {

    SYSCTL_RCGC2_R |= 0x00000020;

 
    __asm__("NOP");
    __asm__("NOP");
    
    
    GPIO_PORTF_DIR_R |= (1 << LED_PIN);

   
    GPIO_PORTF_DEN_R |= (1 << LED_PIN);

    while (1) {
        
        GPIO_PORTF_DATA_R ^= (1 << LED_PIN);

       
        delay(1000); 
    }

    return 0;
}
