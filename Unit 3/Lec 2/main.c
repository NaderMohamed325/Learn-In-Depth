#include "uart.h"


unsigned char *p = "nader mohamed nader";
int  main(int argc, char const *argv[])
{
	

	Uart_Send(p);
	return 0;
}