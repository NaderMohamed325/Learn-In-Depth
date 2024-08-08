
#include "MCAL/gpio/gpio.h"
int main(void) {
	uint8_t counter=0;
	Port_Direction(C,Output);
	while (1) {
		
		Port_Set(C,counter++);
		_delay_ms(100);
	}

	return 0;
}