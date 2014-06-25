#ifndef USART2_H
#define USART2_H

//function declaration
void Usart2_Init(int baudrate);
void DMA2_Usart2_Config(void);
void Usart2_DMA_Send(int8_t *buf, int16_t len);

#endif
