
#include"header.h"

#define DONE ((ADDR>>31)&1)

void adc_init(void)

{
PINSEL1|=0X15400000;

ADCR = 0X00200400;
}

u32 adc_read(u8 ch_num)
{

u32 result=0;

ADCR|=(1<<ch_num);

ADCR|=(1<<24);

while(DONE==0);

ADCR^=(1<<24);

ADCR^=(1<<ch_num);

result=(ADDR>>6)&0X3FF;

return result;

}
