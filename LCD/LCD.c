#include <reg51.h>

void comwrt (unsigned char);
void datawrt (unsigned char);
void delay ();

sbit RS = P2^0;
sbit RW = P2^1;
sbit EN = P2^2;

void main()
{
	comwrt(0x38);
	delay();
	comwrt(0x0E);
	delay();
	comwrt(0x01);
	delay();
	comwrt(0x06);
	delay();
	comwrt(0x84);
	delay();
	datawrt('N');
	delay();

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
