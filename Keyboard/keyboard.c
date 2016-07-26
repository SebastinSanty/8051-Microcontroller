#include<reg52.h> //including sfr registers for ports of the controller
#include<lcd.h>

//LCD Module Connections
sbit RS = P2^0;
sbit EN = P2^1;
sbit D0 = P1^0;
sbit D1 = P1^1;
sbit D2 = P1^2;
sbit D3 = P1^3;
sbit D4 = P1^4;
sbit D5 = P1^5;
sbit D6 = P1^6;
sbit D7 = P1^7;
//End LCD Module Connections

//Keypad Connections
sbit R1 = P0^0;
sbit R2 = P0^1;
sbit R3 = P0^2;
sbit R4 = P0^3;
sbit C1 = P0^4;
sbit C2 = P0^5;
sbit C3 = P0^6;
sbit C4 = P0^7;
//End Keypad Connections

void Delay(int a)
{
  int j;
  int i;
  for(i=0;i<a;i++)
  {
    for(j=0;j<100;j++)
    {
    }
  }
}

char Read_Keypad()
{
  C1=1;
  C2=1;
  C3=1;
  C4=1;
  R1=0;
  R2=1;
  R3=1;
  R4=1;
  if(C1==0){Delay(100);while(C1==0);return '7';}
  if(C2==0){Delay(100);while(C2==0);return '8';}
  if(C3==0){Delay(100);while(C3==0);return '9';}
  if(C4==0){Delay(100);while(C4==0);return '/';}
  R1=1;
  R2=0;
  R3=1;
  R4=1;
  if(C1==0){Delay(100);while(C1==0);return '4';}
  if(C2==0){Delay(100);while(C2==0);return '5';}
  if(C3==0){Delay(100);while(C3==0);return '6';}
  if(C4==0){Delay(100);while(C4==0);return 'X';}
  R1=1;
  R2=1;
  R3=0;
  R4=1;
  if(C1==0){Delay(100);while(C1==0);return '1';}
  if(C2==0){Delay(100);while(C2==0);return '2';}
  if(C3==0){Delay(100);while(C3==0);return '3';}
  if(C4==0){Delay(100);while(C4==0);return '-';}
  R1=1;
  R2=1;
  R3=1;
  R4=0;
  if(C1==0){Delay(100);while(C1==0);return 'C';}
  if(C2==0){Delay(100);while(C2==0);return '0';}
  if(C3==0){Delay(100);while(C3==0);return '=';}
  if(C4==0){Delay(100);while(C4==0);return '+';}
  return 0;
}

void main()
{
  int i=0;
  char c,p;
  Lcd8_Init();
  while(1)
  {
    Lcd8_Set_Cursor(1,1);
    Lcd8_Write_String("Keys Pressed:");
    Lcd8_Set_Cursor(2,1);
    Lcd8_Write_String("Times:");
    while(!(c = Read_Keypad()));
    p=c;
    while(p==c)
    {
      i++;
      Lcd8_Set_Cursor(1,14);
      Lcd8_Write_Char(c);
      Lcd8_Set_Cursor(2,7);
      Lcd8_Write_Char(i+48);
      Delay(100);
      while(!(c = Read_Keypad()));
    }
    i=0;
    Lcd8_Clear();
  }
}