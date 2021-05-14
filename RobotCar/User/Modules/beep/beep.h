#ifndef __BEEP_H
#define __BEEP_H

#include "stm32f10x.h"

#define BEEP_GPIO_PIN		GPIO_Pin_8
#define BEEP_GPIO_PORT	GPIOA
#define BEEP_GPIO_CLK		RCC_APB2Periph_GPIOA


#define digitalHi(p,i)		{p->BSRR=i;}
#define digitalLo(p,i)		{p->BRR=i;}

#define BEEP_ON 			digitalHi(BEEP_GPIO_PORT,BEEP_GPIO_PIN)
#define BEEP_OFF 			digitalLo(BEEP_GPIO_PORT,BEEP_GPIO_PIN)

void BEEP_GPIO_Config(void);
void Beep1(void);
void Beep2(void);
void Beep3(void);
void BeepL(void);

#endif /*  __BEEP_H */
