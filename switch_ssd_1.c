#include<stdint.h>
#include "tm4c123gh6pm.h"
void shift_out(unsigned char str);
unsigned int sw1,sw2;
void delayms(void);
unsigned char a[2]={0xee,0xd2};
int main(void)
{
	SYSCTL_RCGCGPIO_R |=0X24;
	GPIO_PORTF_LOCK_R |= 0X4C4F434B;
	GPIO_PORTF_CR_R |=0X01;
	GPIO_PORTC_DIR_R |=0X10;
	GPIO_PORTC_DEN_R |=0X10;
	GPIO_PORTF_DIR_R |=0X0C;
	GPIO_PORTF_DEN_R |=0X0C;
	GPIO_PORTF_PUR_R |=0X11;
	while(1)
	{
		sw1=~(GPIO_PORTF_DATA_R &(1<<4));
		sw2=~(GPIO_PORTF_DATA_R & (1<<0));
		if(sw1)
		{
			shift_out(a[0]);
		shift_out(0);
		shift_out(0);
		shift_out(0);
		delayms();
		shift_out(0);
		shift_out(0);
		shift_out(0);
		shift_out(0);
		}
		else if(sw2)
		{
			shift_out(a[1]);
		shift_out(0);
		shift_out(0);
		shift_out(0);
		delayms();
		shift_out(0);
		shift_out(0);
		shift_out(0);
		shift_out(0);
		}
	}
}
void shift_out(unsigned char str)
{
	GPIO_PORTC_DATA_R &=~0X10;
	unsigned int j,check;
	for(j=0;j<=7;j++)
	{
		check=(str & (1<<j));
		if(check)
		{
			GPIO_PORTF_DATA_R |= 0X04;
		}
		else{
			GPIO_PORTF_DATA_R &=~0X04;
		}
		GPIO_PORTF_DATA_R &=~ 0X08;
		GPIO_PORTF_DATA_R |= 0X08;
	}
	GPIO_PORTC_DATA_R |= 0X10;
}
void delayms(void)
{
	for(int i=0;i<1000;i++)
	{
		for(int j=0;j<3200;j++)
		{}
		}
	}

	
 