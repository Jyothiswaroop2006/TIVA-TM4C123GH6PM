#include<stdint.h>
#include "tm4c123gh6pm.h"

int main()
{
	SYSCTL_RCGCGPIO_R |=0X20;
	GPIO_PORTF_DIR_R |=0X02;
	GPIO_PORTF_DEN_R |=0X02;
	NVIC_ST_RELOAD_R =16000-1;
	NVIC_ST_CURRENT_R =0;
	NVIC_ST_CTRL_R =0X05;
	while(1)
	{
		if(NVIC_ST_CTRL_R & (1<<16))
		{
			GPIO_PORTF_DATA_R ^= 0X02;
			
		}
	}
}