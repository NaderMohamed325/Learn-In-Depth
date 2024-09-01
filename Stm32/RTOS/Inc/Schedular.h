/*
 * Schedular.h
 *
 *  Created on: Aug 31, 2024
 *      Author: xcite
 */

#ifndef Schedular
#define Schedular
#include <string.h>
#include "stm32f103c6_gpio.h"
#include "ARMCM3.h"
#include "core_cm3.h"
#include "CortexMX_Os_Porting.h"
typedef enum
    {
    No_Error,
    Ready_QUEUE_INIT_ERROR,
    Task_exceeded_heap,
    } MyRtos_error_id;

typedef struct
    {
	unsigned Stack_Size;
	unsigned char Priority;
	void (*p_Task_Entry)(void); //pinter to task C function
	bool Auto_Start;           //
	unsigned _S_PSP_Task;     //NOT BY USER
	unsigned _E_PSP_Task;    //NOT BY USER
	unsigned *Current_PSP;  //NOT BY USER
	char Task_Name[30];
	enum
	    {
	    Suspend,
	    Running,
	    Waiting,
	    Ready
	    } Task_State_t;

	struct
	    {
		enum
		    {
		    Enable,
		    Disable
		    } Blocking;
		unsigned Ticks_Count;
	    } TimingWaiting_t;

    } Task_ref;

MyRtos_error_id MYRTOS_Init();
MyRtos_error_id My_RTOS_Creat_Task(Task_ref *Tref);
#endif
