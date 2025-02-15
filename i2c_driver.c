
#include"header.h"

void i2c_init(void)
{
	PINSEL0 |= 0x50;	//p0.2-> scl, p0.3-> sda
	I2SCLH = I2SCLL = 75;	//100kbps
	I2CONSET = (1<<6);	//Enable i2c pheripheral and select master mode

}

#define SI ((I2CONSET >> 3) & 1)
void I2C_byte_write_frame(u8 sa, s8 mr, s8 data)
{
//1] generate start condition
I2CONSET = (1<<5);	//STA=1
I2CONCLR = (1<<3);	//SI=0
while(SI == 0);
	
I2CONCLR = (1<<5);	//STA=0
if(I2STAT != 0x8)
{
	lcd_string("Err: start\r\n");
	goto exit;
}

//2] send SA+W & check ack
I2DAT = sa;	//send SA+W
I2CONCLR = (1<<3);	//SI=0
while(SI==0);
if(I2STAT == 0x20)
{
	lcd_string("Err: SA+W\r\n");
	goto exit;
}

//3] send M/R address
I2DAT = mr;
I2CONCLR = (1<<3);	//SI=0
while(SI == 0);
if(I2STAT == 0x30)
{
	lcd_string("Err: M/R Address\r\n");
	goto exit;
}

//4] send data
I2DAT = data;
I2CONCLR = (1<<3);
while(SI == 0);
if(I2STAT == 0x30)
{
	lcd_string("Err: Data\r\n");
	goto exit;
}

//5] generate stop condition
exit:
I2CONCLR = (1<<3);	//SI=0
I2CONSET = (1<<4);	
}


u8 i2c_byte_read_frame(u8 sa, s8 mr)
{
u8 temp;
I2CONSET = (1<<5);
I2CONCLR = (1<<3);

while(SI == 0);
I2CONCLR = (1<<5);

if(I2STAT != 0x8)
{
	lcd_string("Err: Start\r\n");
	goto exit;
}

//2] send SA+W
I2DAT = sa;
I2CONCLR = (1<<3);
while(SI == 0);
if(I2STAT == 0x20)
{
	lcd_string("Err: sa+w\r\n");
	goto exit;
}

//3] send M/R address
I2DAT = mr;
I2CONCLR = (1<<3);	//SI=0
while(SI == 0);
if(I2STAT == 0x30)
{
	lcd_string("Err: M/R Address\r\n");
	goto exit;
}

//4] generate restart

I2CONSET = (1<<5);
I2CONCLR = (1<<3);
while(SI == 0);
I2CONCLR = (1<<5);

if(I2STAT != 0x10)
{
	lcd_string("Err: Restart\r\n");
	goto exit;
}

//5] send SA+R

I2DAT = sa|1;	//send sa+r
I2CONCLR = (1<<3);
while(SI == 0);
if(I2STAT == 0x48)
{
	lcd_string("Err: SA+R\r\n");
	goto exit;
}

//6] read data
I2CONCLR = (1<<3);
while(SI == 0);
temp = I2DAT;

//7] generate stop condition
exit:
I2CONCLR = (1<<3);
I2CONSET = (1<<4);

//8] return received data
return temp; 
}
