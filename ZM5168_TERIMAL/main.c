/**************************************/
/*                                    */ 
/*    zm5168项目终端部分实施代码      */
/*       俞传富、周洁、庞子皓         */ 
/*           2016/5/11                */
/*                                    */
/**************************************/

#include <reg52.h>
#include "delay.h"
#include "UART.h"

#define OPEN 0xf0
#define CLOSED 0x0f
#define ADDRESS 0x2001
#define MAX_LINE 5
#define BEGIN_FLAG 0xaa
#define STOP_FLAG 0x55

sbit resetn = P0^0;

unsigned char send_line[MAX_LINE];

void main()
{
	resetn = 0;
	delay_ms(2);
	resetn = 1;
	
	uart_init();


	send_line[0] = BEGIN_FLAG;
	send_line[MAX_LINE - 1] = STOP_FLAG;
 
	send_line[1] = ADDRESS >> 8;
	send_line[2] = ADDRESS & 0x00ff;
	send_line[3] = OPEN;
	
	uart_send_str(send_line);
	
	
	
	while(1)
	{
			delay_s(1);					
			uart_send_str(send_line);					  	      
	}
}
