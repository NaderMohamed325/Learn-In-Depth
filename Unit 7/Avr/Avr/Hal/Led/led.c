/*
 * led.c
 *
 * Created: 5/17/2024 6:44:10 PM
 *  Author: xcite
 */ 
#include "led.h"

void led_init(led_t *led){
	led->led_pin.logic=led->status;
	Pin_init(&(led->led_pin));
}
void led_set(led_t *led){
	led->led_pin.logic=HIGH;
	Pin_setLogic(&led->led_pin);
}
void led_reset(led_t *led){
	led->led_pin.logic=LOW;
	Pin_setLogic(&led->led_pin);
}

void led_toggel(led_t *led){
	led->led_pin.logic=!led->led_pin.logic;
	Pin_setLogic(&led->led_pin);
}
