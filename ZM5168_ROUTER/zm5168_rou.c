#include <reg52.h>

#include "delay.h"
#include "UART.h"

sbit resetn = P0^0;

void main()
{
	  resetn = 0;
	  delay_ms(1);
	  resetn = 1;  
	
    uart_init();
	  
	  while(1);
}