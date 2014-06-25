#include <stm32f4xx.h>
#include "timer2.h"


//timer2 configuration pwm output at channel 1
//APB1 bus clock is 42 MHz 
//@ uint16_t period: pwm period(us)
//@ uint16_t dutycycle: pwm dutycycle(us)
void timer2_pwm_init(uint16_t period, uint16_t dutycycle)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
    TIM_OCInitTypeDef TIM_OCInitStruct;
    GPIO_InitTypeDef GPIOInitStructure;

    //timebase configuration
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    TIM_TimeBaseStructure.TIM_Period = period-1;
    TIM_TimeBaseStructure.TIM_Prescaler = 42-1;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;;
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
    TIM_Cmd(TIM2, ENABLE);
    //pwm output channel1 configuration
    TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStruct.TIM_Pulse = dutycycle;
    TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OC2Init(TIM2, &TIM_OCInitStruct);
    TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);
    //pwm output pin configuration 
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

    GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_TIM2);
    GPIOInitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIOInitStructure.GPIO_OType = GPIO_OType_PP;
    GPIOInitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIOInitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIOInitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &GPIOInitStructure);   
}
