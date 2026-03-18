#include<stdint.h>
#include"tm4c123gh6pm.h"
void SysTick_Handler(void);
int main()
{
	SYSCTL_RCGCGPIO_R |=0X20;
	GPIO_PORTF_DIR_R |=0X02;
	GPIO_PORTF_DEN_R |=0X02;
	NVIC_ST_RELOAD_R =15999;
	NVIC_ST_CURRENT_R=0;
	NVIC_ST_CTRL_R=0X07;
	while(1)
	{
	}
}
void SysTick_Handler(void){
	GPIO_PORTF_DATA_R ^=0X02;
}