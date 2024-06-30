#include "../GPIO/inc/stm32f103c6_gpio.h"
#include "../Lcd_Driver/inc/lcd.h"
#include "../Keypad_Driver/inc/keypad.h"

// Initialize the clock for GPIOA and GPIOB
void clock_init()
    {
    RCC_GPIOA_CLK_EN();  // Enable clock for GPIOA
    RCC_GPIOB_CLK_EN();  // Enable clock for GPIOB
    }

// Initialize GPIO pins
void GPIO_init()
    {

    }

int main(void)
    {




    while(1){

    }


    }
