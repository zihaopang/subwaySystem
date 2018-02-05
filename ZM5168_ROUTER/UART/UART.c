#include <reg52.h>

unsigned char ch;

void uart_init()
{
    SCON = 0x50; //���ô��ڹ�����ʽ
	  TMOD |= 0x20;//���ö�ʱ��������ʽ
	  TH1 = 0xF3;//���ò�����Ϊ4800
	  TR1 = 1;//�򿪶�ʱ��1
	  //�жϷ���
	  ES = 1;//�򿪴��ڷ����ж�
	  EA = 1;
}

void uart_send_char(unsigned char ch)
{
    SBUF = ch;
	  while(!TI);//�ȴ�TIΪ1
	  TI = 0;//TI����
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