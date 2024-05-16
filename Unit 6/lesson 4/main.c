#include <atmel_start.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


#define LED_PIN PB0
#define LED_DDR DDRB
#define LED_PORT PORTB


ISR(INT0_vect) {
	
	LED_PORT ^= (1 << LED_PIN);
}

int main(void) {
	atmel_start_init();  

	
	LED_DDR |= (1 << LED_PIN);

	
	MCUCR |= (1 << ISC00);  
	MCUCR |= (1 << ISC01);  

	
	EIMSK |= (1 << INT0);   

	
	
	sei();

	while (1) {
		
		
	}
}

