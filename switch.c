#include<stdint.h>
#include "tm4c123gh6pm.h"
void delayms(void);
unsigned int sw;
int main(void)
{
	SYSCTL_RCGCGPIO_R |=0x20;
	GPIO_PORTF_DIR_R |=0X02;
	GPIO_PORTF_DEN_R |=0X02;
	GPIO_PORTF_PUR_R |=0X10;
	while(1)
	{
		sw=~(GPIO_PORTF_DATA_R & 0X00000002);
		if(sw)
		{
			GPIO_PORTF_DATA_R |=0X02;
		}
		else{
			GPIO_PORTF_DATA_R &=~0X02;
		}
	}
}