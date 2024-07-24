#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "../gpio/gpio.h"
#include <avr/interrupt.h>

// External Interrupt Pins
typedef enum {
	EXT_INT0,
	EXT_INT1,
	EXT_INT2
} ExtInterrupt_t;

// Interrupt Trigger Modes
typedef enum {
	LOW_LEVEL,
	ANY_CHANGE,
	FALLING_EDGE,
	RISING_EDGE
} InterruptMode_t;

// Function prototypes
void ExtInterrupt_Init(ExtInterrupt_t intPin, InterruptMode_t mode);
void ExtInterrupt_Enable(ExtInterrupt_t intPin);
void ExtInterrupt_Disable(ExtInterrupt_t intPin);
void ExtInterrupt_SetCallback(ExtInterrupt_t intPin, void (*callback)(void));
#endif /* INTERRUPT_H_ */
