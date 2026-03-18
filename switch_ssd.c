#include<stdint.h>
#include "tm4c123gh6pm.h"
 unsigned char a[2]={0xee,0xce};
 void shift_out(unsigned char str);
 void delayms(void);
 unsigned int sw1;
 int main()
 {
	 SYSCTL_RCGCGPIO_R |=0X24;
	 GPIO_PORTC_DIR_R |=0X10;
	 GPIO_PORTC_DEN_R |=0X10;
	 GPIO_PORTF_DIR_R |=0X0C;
	 GPIO_PORTF_DEN_R |=0X0C;
	 GPIO_PORTF_PUR_R |= 0X10;
	 GPIO_PORTF_DIR_R &= ~ 0X10;
	  while(1)
		{
			sw1=~(GPIO_PORTF_DATA_R &(1<<4));
			if(sw1)
			{
				shift_out(a[0]);
				shift_out(0);
				shift_out(0);
				shift_out(0);
				delayms();
			}
			else{
				shift_out(a[1]);
				shift_out(0);
				shift_out(0);
				shift_out(0);
				delayms();
			}
		}
	}
 void shift_out(unsigned char str)
 {
	 unsigned int j,check;
	  GPIO_PORTC_DATA_R &=~0X10;
	 for(j=0;j<8;j++)
	 {
		 GPIO_PORTF_DATA_R &=~0X04;
		 check=(str & (1<<j));
		 if(check)
		 {
			 GPIO_PORTF_DATA_R |= 0x04;
		 }
		 else{
			 GPIO_PORTF_DATA_R &=~0X04;
			 
		 }
		 GPIO_PORTF_DATA_R &=~0X08;
		 GPIO_PORTF_DATA_R |=0X08;
		 
	 }
	 GPIO_PORTC_DATA_R |=0X10;
 }
 
 void delayms(void)
 {
	 for(int k=0;k<1000;k++)
	 {
		 for (int i=0;i<3200;i++)
		 {}
		 }
	 }
 
 
 