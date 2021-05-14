#ifndef LCD_H
#define LCD_H
#include "stm32f10x.h"

 void Delay ( __IO uint32_t nCount );
 
 void Interface(void);//界面展示
 void ADC_LCD(void);//ADC检测 白天/黑夜
 void TH_Warning(void);//温度警告
void obtain_State(void);
 void Firstface(void);
 
 
 #endif /*  __LCD_H */
 
 
 