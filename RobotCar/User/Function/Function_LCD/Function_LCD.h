#ifndef LCD_H
#define LCD_H
#include "stm32f10x.h"

 void Delay ( __IO uint32_t nCount );
 
 void Interface(void);//����չʾ
 void ADC_LCD(void);//ADC��� ����/��ҹ
 void TH_Warning(void);//�¶Ⱦ���
void obtain_State(void);
 void Firstface(void);
 
 
 #endif /*  __LCD_H */
 
 
 