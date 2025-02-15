#include<LPC21xx.h>

                         /*header.h*/
typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned short int u16;
typedef signed short int s16;

extern void delay_ms(u32 ms);
extern void delay_sec(u32 sec);

/*lcd*//////////////////////////////////////
extern void lcd_data(unsigned char );
extern  void lcd_cmd(unsigned char ) ;
extern void lcd_init(void);
extern  void lcd_string(char *);
extern void lcd_integer(int );
extern void lcd_float(float );

/////adc driver///

extern u32 adc_read(u8 ch_num);
extern void adc_init(void);


////////////////////I2C////////////
extern u8 i2c_byte_read_frame(u8 sa, s8 mr);
extern void I2C_byte_write_frame(u8 sa, s8 mr, s8 data);
void i2c_init(void);


///////////////mcp3204/////////////
extern u32 mcp3204_read(u8 ch_num);


 //////////////spi////////////////
 extern void spi0_init(void);
 extern u8 spi0(u8 data);
