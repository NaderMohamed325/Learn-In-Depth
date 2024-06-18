

#ifndef STATE_H_
#define STATE_H_
#include "stdio.h"
#include "stdlib.h"


#define STATE_DEFINE(STATEFUN_) void ST_##STATEFUN_()
#define STATE(STATEFUN_) ST_##STATEFUN_

//States Connections
extern void US_Set_Distance(int d);
extern void DC_Motor(int S);



#endif /* STATE_H_ */
