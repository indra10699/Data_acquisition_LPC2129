
#include"header.h"

unsigned int temp;
void lcd_data(unsigned char data)
{
IOCLR1 = 0xFE<<16;

	
//HIGHER NIBBLE
temp = (data & 0xF0)<<16;
IOSET1 = temp;

IOSET1 = 1<<17;	//RS
IOCLR1 = 1<<18;	//RW
IOSET1 = 1<<19;	//EN
	delay_ms(2);
IOCLR1 = 1<<19;

//LOWER NIBBLE
IOCLR1 = 0xFE<<16;
temp = (data & 0x0F)<<20;
IOSET1 = temp;

IOSET1 = 1<<17;	//RS
IOCLR1 = 1<<18;	//RW
IOSET1 = 1<<19;	//EN
	delay_ms(2);
IOCLR1 = 1<<19;
}

void lcd_cmd(unsigned char cmd)
{
unsigned int temp;
IOCLR1 = 0xFE<<16;

//HIGHER NIBBLE
temp = (cmd & 0xF0)<<16;
IOSET1 = temp;

IOCLR1 = 1<<17;	//RS
IOCLR1 = 1<<18;	//RW
IOSET1 = 1<<19;	//EN
	delay_ms(2);
IOCLR1 = 1<<19;

//LOWER NIBBLE
IOCLR1 = 0xFE<<16;
temp = (cmd & 0x0F)<<20;
IOSET1 = temp;

IOCLR1 = 1<<17;	//RS
IOCLR1 = 1<<18;	//RW
IOSET1 = 1<<19;	//EN
	delay_ms(2);
IOCLR1 = 1<<19;
}

void lcd_init()
{
IODIR1 = 0xFE<<16;
IOCLR1 = 1<<19;
PINSEL2 = 0x0;
lcd_cmd(0x02);	//enable 4bit mode
lcd_cmd(0x28);	//enable double line in 4bit
lcd_cmd(0x0e);	//enable cursor
lcd_cmd(0x01);
}

void lcd_string(char *p)
{
	while(*p!=0)
	{
		lcd_data(*p);
		p++;
	}
}

void lcd_integer(int num)
{
	int a[10],i;
	if(num == 0)
	{
		lcd_data('0');
		return;
	}
	if(num < 0)
	{
		lcd_data('-');
		num = -num;
	}
	i=0;
	while(num>0)
	{
		a[i] = num%10+48;
		num = num/10;
		i++;
	}
	for(i=i-1; i>=0; i--)
	{
		lcd_data(a[i]);
	}
}


void lcd_float(float num)
{
int temp,k=1000,j,i,t,a[15],c;
temp=num;
if(num<0)
num=-num;
j=k*num;
for(c=0,t=temp;t;t/=10,c++);
for(i=0;j;j/=10,i++)
a[i]=(j%10)+48;
lcd_integer(temp);
lcd_data('.');
for(i=i-c-1;i>=0;i--)
lcd_data(a[i]);
}
