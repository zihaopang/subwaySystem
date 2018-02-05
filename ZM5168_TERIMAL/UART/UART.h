#ifndef __UART_H__
#define __UART_H__

extern void uart_init();
extern void uart_send_char(unsigned char ch);
extern void uart_send_str(unsigned char *str);

#endif