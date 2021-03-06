#include <stm32f4xx.h>
#include "led.h"

static void delay(int32_t time)
{
	while(time--);
}

int main(void)
{	
	LED_Init();
	while(1) 
	{
		LED_GREEN_ON();
		LED_ORANGE_ON();
		LED_BLUE_ON();
		LED_RED_ON();		
		delay(800000);
		LED_GREEN_OFF();
		LED_ORANGE_OFF();
		LED_BLUE_OFF();
		LED_RED_OFF();
		delay(800000);
	}

	return 0;
}
