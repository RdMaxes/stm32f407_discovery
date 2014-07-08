#include <stm32f4xx.h>
#include "led.h"
#include "usart2.h"
#include "myprintf.h"

int32_t test_var = 343422;

void delay(int32_t time);
void LED_blink(void);

void delay(int32_t time)
{
	while(time--);
}

int main(void)
{	
	void (*func)(void);	
	LED_Init();
	Usart2_Init(9600);
	Myprintf_Init(0x00,myputc);
	
	func = LED_blink;
	while(1) 
	{
		(*func)();
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
