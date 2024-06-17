/*
* motor.c
*
* Created: 5/19/2024 10:31:58 PM
*  Author: xcite
*/
#include "motor.h"

bool motor_on(motor_t *m){
	if(!m){
		return false;
	}

	switch(m->direction){
		case Right:
		m->motor_pins[0].logic=HIGH;
		m->motor_pins[1].logic=LOW;
		break;
		
		case Left:
		m->motor_pins[1].logic=HIGH;
		m->motor_pins[0].logic=LOW;
		break;
		
		case Stop:
		m->motor_pins[0].logic=LOW;
		m->motor_pins[1].logic=LOW;
		break;
	}

	Pin_init(&m->motor_pins[0]);
	Pin_init(&m->motor_pins[1]);
	return true;
	
}
bool motor_toggel(motor_t *m){
	if(!m){
		return false;
	}

	m->motor_pins[0].logic=!m->motor_pins[0].logic;
	m->motor_pins[1].logic=!m->motor_pins[1].logic;
	Pin_setLogic(&m->motor_pins[0]);
	Pin_setLogic(&m->motor_pins[1]);
	return true;
}

bool motor_off(motor_t *m){
	if(!m){
		return false;
	}

	m->motor_pins[0].logic=LOW;
	m->motor_pins[1].logic=LOW;
	Pin_setLogic(&m->motor_pins[0]);
	Pin_setLogic(&m->motor_pins[1]);
	return true;
}