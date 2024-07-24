/*
 * Servo.h
 *
 * Created: 7/23/2024 6:11:02 PM
 *  Author: xcite
 */ 


#ifndef SERVO_H_
#define SERVO_H_
#include "../../MCAL/Timer/Timer.h"

void Servo_Init(void);
void Servo_Set_Position(uint8_t angle);



#endif /* SERVO_H_ */