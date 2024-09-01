/*
 * Schedular.c
 *
 *  Created on: Aug 31, 2024
 *      Author: xcite
 */
#include <string.h>
#include "Schedular.h"
#include "CortexMX_Os_Porting.h"
#include "RTOS_FIFO.h"
#define TASKS_MAX_NUM 100
struct
    {
	Task_ref *OSTasks[TASKS_MAX_NUM];
	unsigned _S_MSP_Task;     //NOT BY USER
	unsigned _E_MSP_Task;    //NOT BY USER
	unsigned PSP_Task_Locator;
	unsigned Number_ActiveTasks;
	Task_ref *Current_Task;
	Task_ref *Next_Task;
	enum
	    {
	    OS_Suspend,
	    OS_Running
	    } OS_ModeID;

    } OS_Control;

void OS_SVC(int *Stack_Frame)
    {
    //r0,r1,r2,r3,r12,LR,return address (PC) and XPSR
    unsigned char SVC_number;
    SVC_number = *((unsigned char*) (((unsigned char*) Stack_Frame[6]) - 2));

    switch (SVC_number)
	{

	}

    }

void PendSV_Handler(void)
    {

    }

void OS_SVC_Set(int SVC_ID)
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

void My_RTOS_Creat_Stack()
    {
    OS_Control._S_MSP_Task = (unsigned int) &_estack;
    OS_Control._E_MSP_Task = OS_Control._S_MSP_Task - Main_Stack_Size;
    OS_Control.PSP_Task_Locator = OS_Control._E_MSP_Task - 8;

    }
FIFO_Buf_t Ready_Queue;
Task_ref *Ready_Queue_FIFO[100];
Task_ref IDLE_Task;
void MYRTOS_Idle_Task();

MyRtos_error_id MYRTOS_Init()
    {

//update OS state
    MyRtos_error_id Error_ret = No_Error;
    OS_Control.OS_ModeID = OS_Suspend;
//main task stack
    My_RTOS_Creat_Stack();
//create OS Ready Queue
    if (FIFO_init(&Ready_Queue, Ready_Queue_FIFO, 100) != FIFO_NO_ERROR)
	{
	Error_ret += Ready_QUEUE_INIT_ERROR;

	}
//Configure idle task
    strcpy(IDLE_Task.Task_Name, "idle Task");
    IDLE_Task.Priority = 255;
    IDLE_Task.p_Task_Entry = MYRTOS_Idle_Task;
    IDLE_Task.Stack_Size = 300;

    Error_ret += My_RTOS_Creat_Task(&IDLE_Task);
    return Error_ret;

    }
void MYRTOS_Idle_Task()
    {
    while (1)
	{
	__asm("NOP");
	}
    }
void MY_RTOS_TaskStack(Task_ref *Tref)
    {

    /*Task Frame
     * ======
     * XPSR
     * PC (Next Task Instruction which should be Run)
     * LR (return register which is saved in CPU while TASk1 running before TaskSwitching)
     * r12
     * r4
     * r3
     * r2
     * r1
     * r0
     *====
     *r5, r6 , r7 ,r8 ,r9, r10,r11 (Saved/Restore)Manual
     */
    Tref->Current_PSP = (unsigned int *)Tref->_S_PSP_Task;

    Tref->Current_PSP--;
    *(Tref->Current_PSP) = 0x01000000; //DUMMY_XPSR should T =1 to avoid BUS fault;//0x01000000

    Tref->Current_PSP--;
    *(Tref->Current_PSP) = (unsigned int) Tref->p_Task_Entry; //PC

    Tref->Current_PSP--; //LR = 0xFFFFFFFD (EXC_RETURN)Return to thread with PSP
    *(Tref->Current_PSP) = 0xFFFFFFFD;

    for (int j = 0; j < 13; j++)
	{
	Tref->Current_PSP--;
	*(Tref->Current_PSP) = 0;

	}

    }
MyRtos_error_id My_RTOS_Creat_Task(Task_ref *Tref)
    {
    MyRtos_error_id Error_ret = No_Error;
    //check if stack size exceeds stack or no
    Tref->_S_PSP_Task = OS_Control.PSP_Task_Locator;
    Tref->_E_PSP_Task = Tref->_S_PSP_Task - Tref->Stack_Size;
    if (Tref->_E_PSP_Task < ((unsigned int) (&_eheap)))
	{
	Error_ret = Task_exceeded_heap;
	return Error_ret;
	}
    OS_Control.PSP_Task_Locator = Tref->_E_PSP_Task - 8;
    //create psp stack
    MY_RTOS_TaskStack(Tref);

    //align 8 bytes

    //task state update(suspend)
    Tref->Task_State_t=Suspend;

    return Error_ret;
    }
