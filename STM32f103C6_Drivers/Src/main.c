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
lcd_4bit_mode lcd4bit;

int main(void)
    {
    clock_init();

    lcd4bit.lcd_data[0].GPIOx = GPIOA;
    lcd4bit.lcd_data[0].Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
    lcd4bit.lcd_data[0].Pin.GPIO_PinNumber = GPIO_PIN_0;
    lcd4bit.lcd_data[0].Pin.GPIO_Speed = GPIO_SPEED_10M;

    lcd4bit.lcd_data[1].GPIOx = GPIOA;
    lcd4bit.lcd_data[1].Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
    lcd4bit.lcd_data[1].Pin.GPIO_PinNumber = GPIO_PIN_1;
    lcd4bit.lcd_data[1].Pin.GPIO_Speed = GPIO_SPEED_10M;

    lcd4bit.lcd_data[2].GPIOx = GPIOA;
    lcd4bit.lcd_data[2].Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
    lcd4bit.lcd_data[2].Pin.GPIO_PinNumber = GPIO_PIN_2;
    lcd4bit.lcd_data[2].Pin.GPIO_Speed = GPIO_SPEED_10M;

    lcd4bit.lcd_data[3].GPIOx = GPIOA;
    lcd4bit.lcd_data[3].Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
    lcd4bit.lcd_data[3].Pin.GPIO_PinNumber = GPIO_PIN_3;
    lcd4bit.lcd_data[3].Pin.GPIO_Speed = GPIO_SPEED_10M;

    lcd4bit.lcd_en.GPIOx = GPIOA;
    lcd4bit.lcd_en.Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
    lcd4bit.lcd_en.Pin.GPIO_PinNumber = GPIO_PIN_4;
    lcd4bit.lcd_en.Pin.GPIO_Speed = GPIO_SPEED_10M;

    lcd4bit.lcd_rs.GPIOx = GPIOA;
    lcd4bit.lcd_rs.Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
    lcd4bit.lcd_rs.Pin.GPIO_PinNumber = GPIO_PIN_5;
    lcd4bit.lcd_rs.Pin.GPIO_Speed = GPIO_SPEED_10M;

    lcd_4bit_initialize(&lcd4bit);
    lcd_4bit_send_string(&lcd4bit, (uint8_t*) "Hello, World!");
    while (1)
	{

	}

    }
