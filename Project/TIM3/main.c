#include <stm32f4xx.h>
#include "led.h"
#include "usart2.h"
#include "timer2.h"
#include "timer3.h"

int8_t led_flag=0;

static void delay(int32_t time)
{
	while(time--);
}

int main(void)
{	
	LED_Init();
	Usart2_Init(9600);
	timer2_pwm_init(2000,1388);
	Timer3_Interrupt_Init(50,84);
	while(1) 
	{}

	return 0;
}

//timer3 IRQ Handler
void TIM3_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM3, TIM_IT_Update) == SET)
    {
	if(led_flag==0)
	{
		led_flag=1;
		LED_GREEN_ON();				
	}	
	else
	{
		led_flag=0;
		LED_GREEN_OFF();		
	}
	TIM_ClearITPendingBit(TIM3,TIM_FLAG_Update);	
    }
}
