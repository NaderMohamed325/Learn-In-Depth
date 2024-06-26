/*
* gpio.c
*
* Created: 5/17/2024 5:49:28 PM
* Author: Nader
*/
#include "gpio.h"

bool Pin_init(Pin *pin) {
	if (!pin || (pin->pin_number < 0 || pin->pin_number > 7) || (pin->port < 0 || pin->port > 3)) {
		return false;
	}

	Pin_setDirection(pin);
	Pin_setLogic(pin);

	return true;
}

void Pin_setDirection(Pin *pin) {
	if (pin->direction == OUTPUT) {
		switch (pin->port) {
			case 0:
			DDRA |= (1 << pin->pin_number);
			break;
			case 1:
			DDRB |= (1 << pin->pin_number);
			break;
			case 2:
			DDRC |= (1 << pin->pin_number);
			break;
			case 3:
			DDRD |= (1 << pin->pin_number);
			break;
		}
		} else if (pin->direction == INPUT) {
		switch (pin->port) {
			case 0:
			DDRA &= ~(1 << pin->pin_number);
			break;
			case 1:
			DDRB &= ~(1 << pin->pin_number);
			break;
			case 2:
			DDRC &= ~(1 << pin->pin_number);
			break;
			case 3:
			DDRD &= ~(1 << pin->pin_number);
			break;
		}
	}
}

void Pin_setLogic(Pin *pin) {
	if (pin->direction == OUTPUT) {
		switch (pin->port) {
			case 0:
			if (pin->logic == HIGH) {
				PORTA |= (1 << pin->pin_number);
				} else {
				PORTA &= ~(1 << pin->pin_number);
			}
			break;
			case 1:
			if (pin->logic == HIGH) {
				PORTB |= (1 << pin->pin_number);
				} else {
				PORTB &= ~(1 << pin->pin_number);
			}
			break;
			case 2:
			if (pin->logic == HIGH) {
				PORTC |= (1 << pin->pin_number);
				} else {
				PORTC &= ~(1 << pin->pin_number);
			}
			break;
			case 3:
			if (pin->logic == HIGH) {
				PORTD |= (1 << pin->pin_number);
				} else {
				PORTD &= ~(1 << pin->pin_number);
			}
			break;
		}
		} else if (pin->direction == INPUT) {
		switch (pin->port) {
			case 0:
			if (pin->logic == HIGH) {
				PORTA |= (1 << pin->pin_number); // Enable pull-up resistor
				} else {
				PORTA &= ~(1 << pin->pin_number); // Disable pull-up resistor
			}
			break;
			case 1:
			if (pin->logic == HIGH) {
				PORTB |= (1 << pin->pin_number);
				} else {
				PORTB &= ~(1 << pin->pin_number);
			}
			break;
			case 2:
			if (pin->logic == HIGH) {
				PORTC |= (1 << pin->pin_number);
				} else {
				PORTC &= ~(1 << pin->pin_number);
			}
			break;
			case 3:
			if (pin->logic == HIGH) {
				PORTD |= (1 << pin->pin_number);
				} else {
				PORTD &= ~(1 << pin->pin_number);
			}
			break;
		}
	}
}


void Pin_toggel(Pin *pin){
	pin->logic=!(pin->logic);
	Pin_setLogic(pin);
}