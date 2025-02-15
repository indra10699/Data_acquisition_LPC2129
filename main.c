#include<lpc21xx.h>
#include"header.h"
main()
{


u8 h1,h,m,s,date,mon,year;
float vout,v1out,temp;
u32 tout,pout,ldr,vtg;
i2c_init();
lcd_init();
adc_init();
spi0_init();
//set rtc time to 11:59:57pm/
I2C_byte_write_frame(0XD0,0X0,0X55);
I2C_byte_write_frame(0XD0,0X1,0X27);
I2C_byte_write_frame(0XD0,0X2,0X07);

I2C_byte_write_frame(0XD0,0X4,0X05);
I2C_byte_write_frame(0XD0,0X5,0X09);
I2C_byte_write_frame(0XD0,0X6,0X24);


//read rtc time & print it on lcd///
while(1)
{
   lcd_cmd(0x80);
h=i2c_byte_read_frame(0xD0,0x2);//read hrs
m=i2c_byte_read_frame(0xD0,0x1);//read mins
s=i2c_byte_read_frame(0xD0,0x0);//read sec
date=i2c_byte_read_frame(0xD0,0x04);
mon=i2c_byte_read_frame(0xD0,0x05);
year=i2c_byte_read_frame(0xD0,0x06);
h1=h&0x1f;


lcd_data((h1/0x10)+48);
lcd_data((h1%0x10)+48);
lcd_data(':');
lcd_data((m/0x10)+48);
lcd_data((m%0x10)+48);
lcd_data(':');
lcd_data((s/0x10)+48);
lcd_data((s%0x10)+48);



lcd_cmd(0xc0);
lcd_data((date/0x10)+48);
lcd_data((date%0x10)+48);
lcd_data('/');
lcd_data((mon/0x10)+48);
lcd_data((mon%0x10)+48);
lcd_data('/');
lcd_data((year/0x10)+48);
lcd_data((year%0x10)+48);

//////////LDR/////////////
      lcd_cmd(0x8b);
          ldr=mcp3204_read(2);
          
					vtg=(4095-ldr)/40.95;
          lcd_string("L:");
					
	
          lcd_integer(vtg);
					
        ////////////TEMP/////////////////
        lcd_data(' ');
        lcd_cmd(0xc9);
          tout=adc_read(1);
          vout=(tout*3.3)/1023;
          temp=(vout-0.5)/0.01;
          
          lcd_integer(temp);
         
         lcd_data('C');

          ////////pot////////
          lcd_cmd(0xcd);
					pout=adc_read(2);
          v1out=(pout*3.3)/1023;
          lcd_data(' ');
          
          lcd_integer(v1out);
          lcd_data('V');
          }
}
