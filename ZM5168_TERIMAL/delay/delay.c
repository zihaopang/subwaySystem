
void delay_us(unsigned char t)
{
    while(--t);
}

void delay_ms(unsigned char t)
{
    while(t--)
		{
        delay_us(245);
			  delay_us(245);
    }
}

void delay_s(unsigned char t)
{
    unsigned char i;
	  
	  for(i = 0; i < t; i++)
	  {
        delay_ms(200);
			  delay_ms(200);
			  delay_ms(200);
			  delay_ms(200);
			  delay_ms(200);
    }
}
