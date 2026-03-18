#include<stdint.h>
#include "tm4c123gh6pm.h"
unsigned char a[5]={0x60,0xDA,0XF2,0X66,0XFF};
void delayms(void);
void shift_out(unsigned char str);
int main()
{
	SYSCTL_RCGCGPIO_R=0X24;
	GPIO_PORTC_DIR_R |= 0X10;
	GPIO_PORTF_DIR_R |= 0X0C;
	GPIO_PORTF_DEN_R |=0X0C;
	GPIO_PORTC_DEN_R |= 0X10;
	while(1)
	{
		shift_out(a[0]);
		shift_out(0);
		shift_out(0);
		shift_out(0);
		shift_out(0);
		delayms();
		shift_out(0);
		shift_out(0);
		shift_out(0);
		shift_out(0);
		delayms();
	}
}
void shift_out(unsigned char str)
{
	unsigned int j,check;
	for(j=0;j<=7;j++)
	{
		GPIO_PORTF_DATA_R |= 0X00000000;
		check=(str & (1<<j));
		if(check)
		{
			GPIO_PORTF_DATA_R |=0X04;
			
		}
		else{
		GPIO_PORTF_DATA_R |= 0X00;
		}
		GPIO_PORTF_DATA_R |= 0X08;
	}
	GPIO_PORTF_DATA_R |= 0X10;
}

void delayms(void)
{
	for(int k=0;k<1000;k++)
	{
		for(int i=0;i<3200;i++)
		{
		}
	}
}
