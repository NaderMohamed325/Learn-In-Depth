/*
 * Memory_Map.h
 *
 * Created: 6/26/2024 10:14:08 PM
 *  Author: Nader
 */ 


#ifndef MEMORY_MAP_H_
#define MEMORY_MAP_H_


#define PINA  *((volatile unsigned char *)0x39)
#define DDRA  *((volatile unsigned char *)0x3A)
#define PORTA *((volatile unsigned char *)0x3B)


#define PINC  *((volatile unsigned char *)0x33)
#define DDRC  *((volatile unsigned char *)0x34)
#define PORTC *((volatile unsigned char *)0x35)





#endif /* MEMORY_MAP_H_ */