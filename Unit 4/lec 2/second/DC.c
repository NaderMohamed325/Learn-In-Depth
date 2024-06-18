

#include "DC.h"

//Global variables
int DC_speed = 0;
void (*DC_STATE)();


void DC_init()
{
	//init PWM
	printf("DC_init\n");
}

void DC_motor(int s)
{
	DC_speed = s;
	printf("\nCA ---------speed = %d-----------> DC\n",DC_speed);
	DC_STATE = STATE(DC_busy);

}



STATE_DEFINE(DC_idle)
{
	//State Name
	DC_STATE_ID = DC_idle;
	//call PWM to make speed = DC_speed
	printf("\nDC_idle State: speed =%d",DC_speed);

}

STATE_DEFINE(DC_busy)
{
	//State Name
	DC_STATE_ID = DC_busy;
	//call PWM to make speed = DC_speed
	printf("\nDC_busy State: speed =%d",DC_speed);
	DC_STATE=STATE(DC_idle);

}

