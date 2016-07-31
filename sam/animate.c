#include <reg51.h>

unsigned char num1,num2;

void delay_1()
{
	int d;
	for (d=0;d<20;d++)
	{
	 	TMOD = 0x01;
		TH0 = 0xEB;
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
	int j=0;
		num1=0x8;
		num2=0x1;
		P1 = (num1<<4)|(num2);
		delay_1();
	while(1)
	{
		for(j=0;j<3;j++)
		{
			num1>>=1;
			num2<<=1;
			P1 = (num1<<4)|(num2);
			delay_1();
		}
		for(j=0;j<3;j++)
		{
			num1<<=1;
			num2>>=1;
			P1 = (num1<<4)|(num2);
			delay_1();
		}
	}
}