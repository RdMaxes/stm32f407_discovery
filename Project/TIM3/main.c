#include <stm32f4xx.h>
#include "led.h"
#include "usart2.h"
#include "timer2.h"

static void delay(int32_t time)
{
	while(time--);
}

int main(void)
{	
	LED_Init();
	Usart2_Init(9600);
	timer2_pwm_init(2000,1388);
	while(1) 
	{
		LED_GREEN_ON();		
		delay(8000000);
		LED_GREEN_OFF();		
		delay(8000000);
	}

	return 0;
}
