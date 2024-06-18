#ifndef COLLISIONAVOIDANCE_H_
#define COLLISIONAVOIDANCE_H_
#include "state.h"
#include "stdio.h"
#include "stdlib.h"

// Define states of the module
enum {
	CollisionAvoidance_waiting,
	CollisionAvoidance_driving
}CollisionAvoidance_STATE_ID;

// Declare states for Collision Avoidance : Collision Avoidance
STATE_DEFINE(CollisionAvoidance_waiting);
STATE_DEFINE(CollisionAvoidance_driving);

extern void (*CollisionAvoidance_STATE)();

#endif /* COLLISIONAVOIDANCE_H_ */