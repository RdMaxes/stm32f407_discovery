#ifndef LED_H
#define LED_H

//LED GREEN
#ifndef LED_GREEN_PIN
	#define LED_GREEN_CLK				RCC_AHB1Periph_GPIOD
	#define LED_GREEN_PORT				GPIOD
	#define LED_GREEN_PIN				GPIO_Pin_12
#endif

//LED ORANGE
#ifndef LED_ORANGE_PIN
	#define LED_ORANGE_CLK				RCC_AHB1Periph_GPIOD
	#define LED_ORANGE_PORT				GPIOD
	#define LED_ORANGE_PIN				GPIO_Pin_13
#endif

//LED RED
#ifndef LED_RED_PIN
	#define LED_RED_CLK				RCC_AHB1Periph_GPIOD
	#define LED_RED_PORT				GPIOD
	#define LED_RED_PIN				GPIO_Pin_14
#endif

//LED BLUE
#ifndef LED_BLUE_PIN
	#define LED_BLUE_CLK				RCC_AHB1Periph_GPIOD
	#define LED_BLUE_PORT				GPIOD
	#define LED_BLUE_PIN				GPIO_Pin_15
#endif

//function declaration
void LED_Init(void);
#endif
