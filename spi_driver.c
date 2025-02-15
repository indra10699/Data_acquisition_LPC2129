#include<lpc21xx.h>
#include"header.h"
//#define cs0(1<<7)
#define spif ((S0SPSR>>7)&1)

void spi0_init(void)
{
PINSEL0 |= 0X1500;
IODIR0 |= 1<<7;
IOSET0 |= 1<<7;
S0SPCR = 0X20;
S0SPCCR = 15;
}

u8 spi0(u8 data)
{
S0SPDR = data ;
while(spif==0);
return S0SPDR;
}
