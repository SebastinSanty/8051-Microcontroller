#include <reg51.h>

void comwrt (unsigned char);
void datawrt (unsigned char);
void delay ();
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

sbit RS = P2^0;
sbit RW = P2^1;
sbit EN = P2^2;

void main()
{
	int coun=0;
	char c[] = {'1','2','3','4','5','6','7','8','9'};
	comwrt(0x38);
	delay();
	comwrt(0x0E);
	delay();
	comwrt(0x01);
	delay();
	do
	{
		comwrt(0x80);
		datawrt(c[coun]);
		delay_1();
		coun++;
	}while(1);

}

void comwrt (unsigned char value)
{
	P1 = value;
	RS = 0;
	RW = 0;
	EN = 1;
	delay();
	EN = 0;
}

void datawrt (unsigned char value)
{
	P1 = value;
	RS = 1;
	RW = 0;
	EN = 1;
	delay();
	EN = 0;
}

void delay ()
{
	int i,j;
	for(i=0;i<10;i++)
	{	
		for(j=0;j<100;j++)
		{
		}
	}
}
