#include<stdint.h>
#include "tm4c123gh6pm.h"
void delayms(void);
unsigned int sw,sw1;
int main(void)
{
	SYSCTL_RCGCGPIO_R |=0x20;
	GPIO_PORTF_LOCK_R |=0X44C4F434B;
	GPIO_PORTF_CR_R |=0X01;
	GPIO_PORTF_DIR_R |=0X05;
	GPIO_PORTF_DEN_R |=0X05;
	GPIO_PORTF_PUR_R |=0X11;
	while(1)
	{
		sw=~(GPIO_PORTF_DATA_R & 0X00000002);
		sw1=~(GPIO_PORTF_DATA_R & 0X00000004);
		if(sw)
		{
			GPIO_PORTF_DATA_R |=0X02;
		}
		else if(sw1) {
			GPIO_PORTF_DATA_R |=0X04;
		}
		else{
			GPIO_PORTF_DATA_R &=~0X02;
			GPIO_PORTF_DATA_R &=~0X04;
		}
	}
}