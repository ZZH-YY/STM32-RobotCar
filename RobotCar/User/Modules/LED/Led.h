#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "stm32f10x.h"



//					LED 控制引脚宏(PB1)

#define LED_GPIO_PIN		GPIO_Pin_6
#define LED_GPIO_PORT		GPIOC
#define LED_GPIO_CLK		RCC_APB2Periph_GPIOC


#define		NO		1
#define		OFF		0


//               直接操作寄存器控制IO
#define digitalHi(p,i)		{p->BSRR=i;}
#define digitalLo(p,i)		{p->BRR=i;}


#define LED_ON 			digitalHi(LED_GPIO_PORT,LED_GPIO_PIN)
#define LED_OFF 			digitalLo(LED_GPIO_PORT,LED_GPIO_PIN)




void LED_GPIO_Config(void);

#endif /* __BSP_LED_H */ 
