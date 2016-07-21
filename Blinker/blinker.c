#include <REG51.h>

void delay_1();

void main()
{
	P2 = 0x00;
	while(1)
	{
	 	P2 = 0xFF;
		delay_1();
		P2 = 0x00;
		delay_1();
	} 	
}

void delay_1()
{
	int d;
	for (d=0;d<20;d++)
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