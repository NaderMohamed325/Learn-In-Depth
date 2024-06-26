/*
* main.c
*
* Created: 5/17/2024 5:46:14 PM
*  Author: xcite
*/
#include "main.h"


int main(void)
{
	led_t led={
		{.pin_number = 1, .port = 0, .direction = OUTPUT, .logic = HIGH},.status=led_on
		
	};
	led_init(&led);
	while(1){
		led_toggel(&led);
		_delay_ms(200);

		
	}
	
}