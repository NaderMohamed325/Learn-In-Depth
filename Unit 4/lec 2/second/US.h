#ifndef ULTRASONICSENSOR_H_
#define ULTRASONICSENSOR_H_
#include "state.h"
#include "stdio.h"
#include "stdlib.h"

// Define states of the module
enum {
	UltrasonicSensor_busy
}UltrasonicSensor_STATE_ID;

// Declare states for Collision Avoidance : Ultrasonic Sensor
STATE_DEFINE(UltrasonicSensor_busy);

void UltrasonicSensor_init();

extern void (*UltrasonicSensor_STATE)();

#endif /* ULTRASONICSENSOR_H_ */