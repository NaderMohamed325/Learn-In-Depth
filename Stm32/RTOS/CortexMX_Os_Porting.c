/*
 * CortexMX_Os_Porting.c
 *
 *  Created on: Aug 31, 2024
 *      Author: xcite
 */

#include "CortexMX_Os_Porting.h"

void HardFault_Handler(void)
    {
    while (1)
	;
    }
void MemManage_Handler(void)
    {
    while (1)
	;
    }
void BusFault_Handler(void)
    {
    while (1)
	;
    }
void UsageFault_Handlerr(void)
    {
    while (1)
	;
    }

__attribute ((naked)) void SVC_Handler()
    {

    __asm("tst lr ,#4\n\t"
	    "ITE EQ \n\t"
	    "mrseq r0,MSP\n\t"
	    "mrsne r0,PSP\n\t"
	    "B OS_SVC");

    }




void Hw_Init(void){




}









