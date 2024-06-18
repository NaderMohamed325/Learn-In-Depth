
#ifndef DC_H_
#define DC_H_
#include "state.h"



//Define states of the module
enum {
	DC_idle,
	DC_busy
}DC_STATE_ID;


//declare states for Collision Avoidance : DC
STATE_DEFINE(DC_idle);
STATE_DEFINE(DC_busy);

void DC_init();


extern void (*DC_STATE)();


#endif /* DC_H_ */
