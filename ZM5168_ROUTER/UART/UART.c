#include <reg52.h>

unsigned char ch;

void uart_init()
{
    SCON = 0x50; //设置串口工作方式
	  TMOD |= 0x20;//设置定时器工作方式
	  TH1 = 0xF3;//设置波特率为4800
	  TR1 = 1;//打开定时器1
	  //中断服务法
	  ES = 1;//打开串口服务中断
	  EA = 1;
}

void uart_send_char(unsigned char ch)
{
    SBUF = ch;
	  while(!TI);//等待TI为1
	  TI = 0;//TI清零
}

void uart_send_str(unsigned char *str)
{
    while(*str != '\0')
		{
			  uart_send_char(*str++);
		}
}

void uart_isr() interrupt 4
{
	  ES = 0;
	  
	  if(RI)
		{
				RI = 0;	
        uart_send_char(SBUF);						
		}
		
		ES = 1;
}