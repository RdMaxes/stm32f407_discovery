#include <stm32f4xx.h>
#include "led.h"
#include "usart2.h"

uint8_t tx_buf[20] = "Hello Wrold!! It's\r\n";
static void delay(int32_t time)
{
	while(time--);
}

int main(void)
{	
	LED_Init();
	Usart2_Init(9600);

	while(1) 
	{
		Usart2_DMA_Send(tx_buf,sizeof(tx_buf));
		delay(8000000);
		LED_GREEN_ON();
		delay(8000000);
		LED_GREEN_OFF();		
	}

	return 0;
}
