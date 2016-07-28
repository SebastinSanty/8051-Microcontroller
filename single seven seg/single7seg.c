#include <reg51.h>

sbit eseg1000 = P3^7;
sbit eseg100 = P3^6;
sbit eseg10 = P3^5;
sbit eseg1 = P3^4;
unsigned char d0;

unsigned char SetDisplay(unsigned char value)
{
 	unsigned char segment[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x83,0xf8,0x80,0x98};
	if (value<10)
	 	return segment[value];
	else
		return 0;
}

void delay()
{
 	int i;
	for (i=0;i<50;i++)
	{
	TMOD = 0x01;
	TH0 = 0x04B;
	TL0 = 0xFD;
	TR0 = 1;
	while(TF0==0)
	{
	}
	TR0 = 0;
	TF0 = 0;
	}
}
void main()
{
	d0=0;
 	eseg1000 = 1;
	eseg1=eseg10=eseg100=0;
	P2 = 0xff;
	while(1)
	{
	 	P2 = SetDisplay(d0);
		delay();
		d0++;
		if (d0>9)
		{
		 	d0=0;
		}
	}	
}