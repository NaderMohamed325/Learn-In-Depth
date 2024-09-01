#include "Schedular.h"

Task_ref task1, task2, task3;
MyRtos_error_id Error_id;
void task_1(void)
    {
    while (1)
	{

	}
    }
void task_2(void)
    {
    while (1)
	{

	}
    }
void task_3(void)
    {
    while (1)
	{

	}
    }
MyRtos_error_id error;
int main(void)
    {

    if (MYRTOS_Init() != No_Error)
	{
	while (1)
	    ;
	}

    task1.Stack_Size = 1024;
    task1.p_Task_Entry = task_1;
    task1.Priority = 3;
    strcpy(task1.Task_Name, "Task_1");

    task2.Stack_Size = 1024;
    task2.p_Task_Entry = task_2;
    task2.Priority = 3;
    strcpy(task2.Task_Name, "Task_2");

    task3.Stack_Size = 1024;
    task3.p_Task_Entry = task_3;
    task3.Priority = 3;
    strcpy(task3.Task_Name, "Task_3");

    error += My_RTOS_Creat_Task(&task1);
    error += My_RTOS_Creat_Task(&task2);
    error += My_RTOS_Creat_Task(&task3);
    while (1)
	{

	}
    }
