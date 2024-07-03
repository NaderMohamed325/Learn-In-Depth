/*
* Avr.c
*
* Created: 6/26/2024 10:12:08 PM
* Author : Nader
*/



#include "ECU/Lcd/lcd.h"

int main(void) {
	lcd_4bit_mode lcd;
	lcd.lcd_data[0].direction=Output;
	lcd.lcd_data[0].pin=Low;
	lcd.lcd_data[0].port=A;
	lcd.lcd_data[0].pin=0;
	
	lcd.lcd_data[1].direction=Output;
	lcd.lcd_data[1].pin=Low;
	lcd.lcd_data[1].port=A;
	lcd.lcd_data[1].pin=1;
	
	lcd.lcd_data[2].direction=Output;
	lcd.lcd_data[2].pin=Low;
	lcd.lcd_data[2].port=A;
	lcd.lcd_data[2].pin=2;
	
	lcd.lcd_data[3].direction=Output;
	lcd.lcd_data[3].pin=Low;
	lcd.lcd_data[3].port=A;
	lcd.lcd_data[3].pin=3;
	
	lcd.lcd_en.direction=Output;
	lcd.lcd_en.pin=Low;
	lcd.lcd_en.port=A;
	lcd.lcd_en.pin=4;
	
	lcd.lcd_rs.direction=Output;
	lcd.lcd_rs.pin=Low;
	lcd.lcd_rs.port=A;
	lcd.lcd_rs.pin=5;
	
	lcd_4bit_initialize(&lcd);
	lcd_4bit_send_string(&lcd,(unsigned char *)"Learn in depth");
	while (1) {
		// Your main program loop
	}
	
}