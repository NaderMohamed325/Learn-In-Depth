/*
* Avr.c
*
* Created: 6/26/2024 10:12:08 PM
* Author : Nader
*/



#include "ECU/Lcd/lcd.h"

int main(void) {
	 Pin_config_t lcd_en = {A, 0, Output, Low};
	 Pin_config_t lcd_rs = {A, 1, Output, Low};
	 Pin_config_t lcd_data[4] = {
		 {A, 2, Output, Low},  // D4
		 {A, 3, Output, Low},  // D5
		 {A, 4, Output, Low},  // D6
		 {A, 5, Output, Low}   // D7
	 };

	 // Initialize LCD structure for 4-bit mode
	 lcd_4bit_mode lcd = {lcd_en, lcd_rs, {lcd_data[0], lcd_data[1], lcd_data[2], lcd_data[3]}};
 Pin_logic_init(&lcd_en);
 Pin_logic_init(&lcd_rs);
 for (int i = 0; i < 4; i++) {
	 Pin_logic_init(&lcd_data[i]);
 }

	 // Initialize LCD in 4-bit mode
	 lcd_4bit_initialize(&lcd);

	 // Example usage: Display a string on LCD
	 char display_str[] = "Hello, LCD!";
	 lcd_4bit_send_string(&lcd, (unsigned char *) display_str);

	 while (1) {
		 // Your main program loop
	 }
	
}