/*
*gpio.c
*
* Created: 6/28/2024 6:13:28 PM
*  Author: Nader
*/

#include "gpio.h"

/**
 * @brief Initializes the pin direction and sets its logic level.
 *
 * @param Pin Pointer to the pin configuration structure.
 * @return Std_return ROK if successful, NOK if the pin configuration is null.
 */
Std_return Pin_logic_init(Pin_config_t *Pin) {
	Pin_Direction(Pin);
	if (!Pin) {
		return NOK;
	}
	if (Pin->logic == Low) {
		Pin_Clear(Pin);
	} else if (Pin->logic == High) {
		Pin_Set(Pin);
	}
	return ROK;
}

/**
 * @brief Sets the pin logic level to high.
 *
 * @param Pin Pointer to the pin configuration structure.
 * @return Std_return ROK if successful, NOK if the pin configuration is null.
 */
Std_return Pin_Set(Pin_config_t *Pin) {
	if (!Pin) {
		return NOK;
	}
	switch (Pin->port) {
		case A:
			SET_BIT(PORTA, Pin->pin);
			Pin->logic = High;
			break;
		case B:
			SET_BIT(PORTB, Pin->pin);
			Pin->logic = High;
			break;
		case C:
			SET_BIT(PORTC, Pin->pin);
			Pin->logic = High;
			break;
		case D:
			SET_BIT(PORTD, Pin->pin);
			Pin->logic = High;
			break;
		default:
			return NOK;
	}
	return ROK;
}

/**
 * @brief Sets the pin logic level to low.
 *
 * @param Pin Pointer to the pin configuration structure.
 * @return Std_return ROK if successful, NOK if the pin configuration is null.
 */
Std_return Pin_Clear(Pin_config_t *Pin) {
	if (!Pin) {
		return NOK;
	}
	switch (Pin->port) {
		case A:
			CLEAR_BIT(PORTA, Pin->pin);
			Pin->logic = Low;
			break;
		case B:
			CLEAR_BIT(PORTB, Pin->pin);
			Pin->logic = Low;
			break;
		case C:
			CLEAR_BIT(PORTC, Pin->pin);
			Pin->logic = Low;
			break;
		case D:
			CLEAR_BIT(PORTD, Pin->pin);
			Pin->logic = Low;
			break;
		default:
			return NOK;
	}
	return ROK;
}

/**
 * @brief Sets the pin direction to input or output.
 *
 * @param Pin Pointer to the pin configuration structure.
 * @return Std_return ROK if successful, NOK if the pin configuration is null.
 */
Std_return Pin_Direction(Pin_config_t *Pin) {
	if (!Pin) {
		return NOK;
	}
	if (Pin->direction == Input) {
		switch (Pin->port) {
			case A:
				CLEAR_BIT(DDRA, Pin->pin);
				break;
			case B:
				CLEAR_BIT(DDRB, Pin->pin);
				break;
			case C:
				CLEAR_BIT(DDRC, Pin->pin);
				break;
			case D:
				CLEAR_BIT(DDRD, Pin->pin);
				break;
			default:
				return NOK;
		}
	} else if (Pin->direction == Output) {
		switch (Pin->port) {
			case A:
				SET_BIT(DDRA, Pin->pin);
				break;
			case B:
				SET_BIT(DDRB, Pin->pin);
				break;
			case C:
				SET_BIT(DDRC, Pin->pin);
				break;
			case D:
				SET_BIT(DDRD, Pin->pin);
				break;
			default:
				return NOK;
		}
	}
	return ROK;
}

/**
 * @brief Toggles the pin logic level.
 *
 * @param Pin Pointer to the pin configuration structure.
 * @return Std_return ROK if successful, NOK if the pin configuration is null.
 */
Std_return Pin_Toggle(Pin_config_t *Pin) {
	if (!Pin) {
		return NOK;
	}
	switch (Pin->port) {
		case A:
			TOGGLE_BIT(PORTA, Pin->pin);
			Pin->logic = (Pin->logic == High) ? Low : High;
			break;
		case B:
			TOGGLE_BIT(PORTB, Pin->pin);
			Pin->logic = (Pin->logic == High) ? Low : High;
			break;
		case C:
			TOGGLE_BIT(PORTC, Pin->pin);
			Pin->logic = (Pin->logic == High) ? Low : High;
			break;
		case D:
			TOGGLE_BIT(PORTD, Pin->pin);
			Pin->logic = (Pin->logic == High) ? Low : High;
			break;
		default:
			return NOK;
	}
	return ROK;
}

/**
 * @brief Reads the current logic level of the pin.
 *
 * @param Pin Pointer to the pin configuration structure.
 * @param level Pointer to a variable where the current logic level of the pin will be stored.
 * @return Std_return ROK if successful, NOK if the pin configuration or the level pointer is null.
 */
Std_return Pin_Read(Pin_config_t *Pin, Logic_t *level) {
	if (!Pin || !level) {
		return NOK;
	}

	switch (Pin->port) {
		case A:
			*level = (READ_BIT(PINA, Pin->pin)) ? High : Low;
			break;
		case B:
			*level = (READ_BIT(PINB, Pin->pin)) ? High : Low;
			break;
		case C:
			*level = (READ_BIT(PINC, Pin->pin)) ? High : Low;
			break;
		case D:
			*level = (READ_BIT(PIND, Pin->pin)) ? High : Low;
			break;
		default:
			return NOK;
	}

	return ROK;
}

void delay_ms(unsigned int ms) {
	while (ms--) {
		__builtin_avr_delay_cycles(F_CPU / 1000);
	}
}