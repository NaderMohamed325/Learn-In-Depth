#include "CA.h"

// Global variables
int CollisionAvoidance_speed = 0;
int CollisionAvoidance_distance = 0;
int CollisionAvoidance_threshold = 50;

void (*CollisionAvoidance_STATE)();

void UltrasonicSensor_Set_Distance(int d)
{
	CollisionAvoidance_distance = d;
	(CollisionAvoidance_distance <= CollisionAvoidance_threshold) ? (CollisionAvoidance_STATE=STATE(CollisionAvoidance_waiting)):(CollisionAvoidance_STATE=STATE(CollisionAvoidance_driving));
	printf("\nUltrasonic Sensor ---------distance = %d-----------> Collision Avoidance\n",CollisionAvoidance_distance);
}

STATE_DEFINE(CollisionAvoidance_waiting)
{
	// State Name
	CollisionAvoidance_STATE_ID = CollisionAvoidance_waiting;
	printf("\nCollisionAvoidance_Waiting State: distance =%d Speed =%d",CollisionAvoidance_distance,CollisionAvoidance_speed);
	// State Action
	CollisionAvoidance_speed = 0;
	// Send speed signal to DC motor module
	DC_motor(CollisionAvoidance_speed);
}

STATE_DEFINE(CollisionAvoidance_driving)
{
	// State Name
	CollisionAvoidance_STATE_ID = CollisionAvoidance_driving;
	printf("\nCollisionAvoidance_driving State: distance =%d Speed =%d",CollisionAvoidance_distance,CollisionAvoidance_speed);
	// State Action
	CollisionAvoidance_speed = 30;
	// Send speed signal to DC motor module
	DC_motor(CollisionAvoidance_speed);
}