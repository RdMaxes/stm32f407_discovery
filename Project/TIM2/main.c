#include <stm32f4xx.h>
#include "led.h"
#include "usart2.h"

uint8_t tx_buf[10] = {0xAA,0xAB,0xAC,0xAD,0xAE,0xAF,0xA1,0xA2,0xA3,0xA4};
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
	}

	return 0;
}
