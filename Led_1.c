#include<stdint.h>
#include "tm4c123gh6pm.h"
void delayms(void);

int main(void)
{
	SYSCTL_RCGCGPIO_R |=0x20;
	GPIO_PORTF_DEN_R |=0X0E;
	GPIO_PORTF_DIR_R |=0X0E;
	while(1)
	{
		GPIO_PORTF_DATA_R |=0X02;
		delayms();
		GPIO_PORTF_DATA_R |=0X04;
		delayms();
		GPIO_PORTF_DATA_R |=0X08;
		delayms();
	}
}
void delayms(void)
{
	for(int i=0;i<1000;i++)
	{
		for(int j=0;j<32000;j++)
		{
		}
	}
		
}