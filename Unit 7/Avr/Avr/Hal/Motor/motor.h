/*
* motor.h
*
* Created: 5/19/2024 10:31:48 PM
*  Author: xcite
*/


#ifndef MOTOR_H_
#define MOTOR_H_
#include "../../Mcal/GPIO/gpio.h"
typedef enum{
	Left,
	Right,
	Stop,
}rotation_t;
typedef struct {
	Pin motor_pins[2];
	rotation_t direction;
}motor_t;

bool motor_on(motor_t *m);
bool motor_toggel(motor_t *m);
bool motor_off(motor_t *m);
#endif /* MOTOR_H_ */