/*
 * Schedular.c
 *
 *  Created on: Aug 31, 2024
 *      Author: xcite
 */

#include "Schedular.h"


void OS_SVC(int* Stack_Frame)
{
	//r0,r1,r2,r3,r12,LR,return address (PC) and XPSR
	unsigned char SVC_number ;
	SVC_number = *((unsigned char*)(((unsigned char*)Stack_Frame[6])-2)) ;

	switch (SVC_number)
	{

	}


}

void PendSV_Handler(void){

}

void OS_SVC_Set(int SVC_ID )
{
	switch (SVC_ID)
	{
	case 0:
		__asm("svc #0x00");
		break;
	case 1:
		__asm("svc #0x01");
		break;
	case 2:
		__asm("svc #0x02");
		break;
	case 3:
		__asm("svc #0x03");
		break;
	case 4:
		__asm("svc #0x04");
		break;
	}
}
