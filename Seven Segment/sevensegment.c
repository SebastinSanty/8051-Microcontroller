#include <reg51.h>
#include <stdio.h>

void delay();

sbit eseg1000 = P3^7;
sbit eseg100 = P3^6;
sbit eseg10 = P3^5;
sbit eseg1 = P3^4;

unsigned char d0,d1,d2,d3;

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
 /*	int i;
	for (i=0;i<500;i++)
		i=i+0;	   */
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

void main(void)
{
	unsigned char count = 0;
	unsigned long timer = 0;
	int turn = 1;
	P2 = 0xff;
	d0=d1=d2=d3=0;
	while(1) 
	{
		 	if (turn == 1)
				{
					eseg1000=eseg100=eseg10=0;
					P2=SetDisplay(d0);
					eseg1=1;
				}
			else if (turn==2)
				{
					eseg1000=eseg100=eseg1=0;
					P2=SetDisplay(d1);
					eseg10=1;
				}
			else if (turn==3)
				{
					eseg1000=eseg1=eseg10=0;
					P2=SetDisplay(d2);
					eseg100=1;
				}
			else
				{
					eseg1=eseg100=eseg10=0;
					P2=SetDisplay(d3);
					eseg1000=1;
				}

		if (turn>=4){
		 turn =0;
		}
		turn=turn+1;
		delay();
		if (timer == 20) {
		 	d0++;
			timer=0;
				if(d0>=10){
				 	d0=0;
					d1++;
				}
				if(d1>=6){
				 	d1=0;
					d2++;
				}
				if(d2>=10){
				 	d2=0;
					d3++;
				}
				if(d3>=6){
				 	d3=0;
				}

		}
		timer++;
	}
}