#include <stm32f4xx.h>
#include "led.h"
#include "usart2.h"
#include "myprintf.h"

int32_t test_var = 343422;

void delay(int32_t time);

void delay(int32_t time)
{
	while(time--);
}

int main(void)
{	
	LED_Init();
	Usart2_Init(9600);
	Myprintf_Init(0x00,myputc);
	
	while(1) 
	{
		
	}

	return 0;
}

void LED_blink(void)
{
		delay(8000000);
		LED_GREEN_ON();
		delay(8000000);
		LED_GREEN_OFF();	
}
