#ifndef GPIO_H
#define GPIO_H
#define F_CPU 1000000UL
#include <xc.h>
#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>
// Define direction constants
#define INPUT  0
#define OUTPUT 1

// Define logic level constants
#define LOW  0
#define HIGH 1

typedef struct {
	uint8_t pin_number;  // Pin number (0-7)
	uint8_t port;        // Port (0 = PORTA, 1 = PORTB, 2 = PORTC, 3 = PORTD)
	uint8_t direction;   // Direction (INPUT or OUTPUT)
	uint8_t logic;       // Logic level (LOW or HIGH)
} Pin;

bool Pin_init(Pin *pin);
void Pin_setDirection(Pin *pin);
void Pin_setLogic(Pin *pin);
void Pin_toggel(Pin *pin);

#endif // GPIO_H
