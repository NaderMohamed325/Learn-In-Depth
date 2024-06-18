

#include "CA.h"
#include "US.h"
#include "DC.h"

void setup();



void main()
{
	setup();
	while(1)
	{
		US_STATE();
		CA_STATE();
		DC_STATE();

	}

}


void setup()
{
	//init all drivers
	//init IRQ
	//init HAL US_Driver DC_Driver
	//init Block
	US_init();
	DC_init();
	//Set state pointer for each block
	CA_STATE = STATE(CA_waiting);
	US_STATE = STATE(US_busy);
	DC_STATE = STATE(DC_idle);

}
