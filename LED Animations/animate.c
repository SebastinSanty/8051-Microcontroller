#include <reg51.h>

sbit pp[] = (P1^0,P1^1,P1^2,P1^3,P1^4,P1^5,P1^6,P1^7);

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

void main()
{
 	int i=0;
	int j=0;
	while(1)
	{
		for(j=0;j<8;j++)
			pp[j]=0;
		if (i>7)
			i=0;
	 	pp[i]=pp[i+1]=1
		i++;
		delay_1();	
	}
}