#include "Interrupt.h"

// Callback functions
static void (*ExtInt0_Callback)(void) = 0;
static void (*ExtInt1_Callback)(void) = 0;
static void (*ExtInt2_Callback)(void) = 0;

// Initialize external interrupts
void ExtInterrupt_Init(ExtInterrupt_t intPin, InterruptMode_t mode) {
	switch (intPin) {
		case EXT_INT0:
		// Configure INT0 mode
		switch (mode) {
			case LOW_LEVEL:
			MCUCR &= ~(1 << ISC01) & ~(1 << ISC00);
			break;
			case ANY_CHANGE:
			MCUCR |= (1 << ISC00);
			MCUCR &= ~(1 << ISC01);
			break;
			case FALLING_EDGE:
			MCUCR |= (1 << ISC01);
			MCUCR &= ~(1 << ISC00);
			break;
			case RISING_EDGE:
			MCUCR |= (1 << ISC01) | (1 << ISC00);
			break;
		}
		break;
		case EXT_INT1:
		// Configure INT1 mode
		switch (mode) {
			case LOW_LEVEL:
			MCUCR &= ~(1 << ISC11) & ~(1 << ISC10);
			break;
			case ANY_CHANGE:
			MCUCR |= (1 << ISC10);
			MCUCR &= ~(1 << ISC11);
			break;
			case FALLING_EDGE:
			MCUCR |= (1 << ISC11);
			MCUCR &= ~(1 << ISC10);
			break;
			case RISING_EDGE:
			MCUCR |= (1 << ISC11) | (1 << ISC10);
			break;
		}
		break;
		case EXT_INT2:
		// Configure INT2 mode
		switch (mode) {
			case FALLING_EDGE:
			MCUCSR &= ~(1 << ISC2);
			break;
			case RISING_EDGE:
			MCUCSR |= (1 << ISC2);
			break;
			default:
			break;
		}
		break;
	}
}

// Enable external interrupts
void ExtInterrupt_Enable(ExtInterrupt_t intPin) {
		sei();
	switch (intPin) {
		case EXT_INT0:
		GICR |= (1 << INT0);
		break;
		case EXT_INT1:
		GICR |= (1 << INT1);
		break;
		case EXT_INT2:
		GICR |= (1 << INT2);
		break;
	}
}

// Disable external interrupts
void ExtInterrupt_Disable(ExtInterrupt_t intPin) {
	switch (intPin) {
		case EXT_INT0:
		GICR &= ~(1 << INT0);
		break;
		case EXT_INT1:
		GICR &= ~(1 << INT1);
		break;
		case EXT_INT2:
		GICR &= ~(1 << INT2);
		break;
	}
}

// Set callback functions
void ExtInterrupt_SetCallback(ExtInterrupt_t intPin, void (*callback)(void)) {
	switch (intPin) {
		case EXT_INT0:
		ExtInt0_Callback = callback;
		break;
		case EXT_INT1:
		ExtInt1_Callback = callback;
		break;
		case EXT_INT2:
		ExtInt2_Callback = callback;
		break;
	}
}

// ISR for INT0
ISR(INT0_vect) {
	if (ExtInt0_Callback != 0) {
		ExtInt0_Callback();
	}
	GICR|=1<<6;
}

// ISR for INT1
ISR(INT1_vect) {
	if (ExtInt1_Callback != 0) {
		ExtInt1_Callback();
	}
		GICR|=1<<7;
}

// ISR for INT2
ISR(INT2_vect) {
	if (ExtInt2_Callback != 0) {
		ExtInt2_Callback();
	}
		GICR|=1<<5;
}