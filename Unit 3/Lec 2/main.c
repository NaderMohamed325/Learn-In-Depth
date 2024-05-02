#include "uart.h"


unsigned char p[] = "nader mohamed nader";
int  main()
{
	Uart_Send(p);
	return 0;
}