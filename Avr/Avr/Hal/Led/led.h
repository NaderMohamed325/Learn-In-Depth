/*
* led.h
*
* Created: 5/17/2024 6:43:58 PM
*  Author: xcite
*/


#ifndef LED_H_
#define LED_H_
#include "../../Mcal/GPIO/gpio.h"
typedef enum{
	led_off,
	led_on,
	
}led_status;

typedef struct {
	Pin led_pin;
	led_status status;
}led_t;

void led_init(led_t *led);
void led_set(led_t *led);
void led_reset(led_t *led);
void led_toggel(led_t *led);
#endif /* LED_H_ */