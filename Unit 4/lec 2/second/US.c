#include "US.h"

// Global variables
int ultrasonic_distance = 0;

void UltrasonicSensor_init()
{
	// Initialize Ultrasonic Sensor Driver
	printf("Ultrasonic Sensor Init \n");
}

void (*UltrasonicSensor_STATE)();

int UltrasonicSensor_Random_Distance(int l , int r );

STATE_DEFINE(UltrasonicSensor_busy)
{
	// State Name
	UltrasonicSensor_STATE_ID = UltrasonicSensor_busy;
	// State Action
	ultrasonic_distance = UltrasonicSensor_Random_Distance(45,55);
	printf("\nUltrasonicSensor_Waiting State: distance =%d",ultrasonic_distance);

	// Send distance Signal
	UltrasonicSensor_Set_Distance(ultrasonic_distance);
	// Loop to self
	UltrasonicSensor_STATE=STATE(UltrasonicSensor_busy);
}

int UltrasonicSensor_Random_Distance(int l , int r )
{
	int random_number;
	random_number = (rand() % (r-l+1))+l;
	return random_number;
}