#include<lpc21xx.h>
#include"header.h"
#define cs0 (1<<7)
u32 mcp3204_read(u8 ch_num)
{
unsigned char byteh=0,bytel=0;
	unsigned int result;
	ch_num=ch_num<<6;
	IOCLR0=cs0;
	spi0(0x06);
	byteh=spi0(ch_num);
	bytel=spi0(0x0);
	byteh=byteh&0x0f;
	result=(byteh<<8)|bytel;
	IOSET0=cs0;
	return result;
}
