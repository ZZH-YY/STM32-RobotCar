/**
 ******************************************************************************
 * @file    Motor.c
 * @author  Hua
 * @version V6.0
 * @date    2021-05-04
 * @brief   ���ģ���ʼ��
 ******************************************************************************
 * @attention
 *
 *���ܺ�������ֱ�����ã���
 *
 *    1.��������ж�����
 *	  		Motor_1_STOP();   ֹͣ
 *	  		Motor_1_GRun();   ǰ��
 *	  		Motor_1_BRun();   ����
 *		  	Motor_1_TR();     ��ת
 *		  	Motor_1_TL();     ��ת
 *
 *    2.���ٵ���ж�
 *        Motor_2_GRun();   ǰ��
 *        Motor_2_BRun();   ����
 *        Motor_2_TR();     ��ת
 *        Motor_2_TL();     ��ת
 *
 *    3.�߼�����ж�   
 *        Motor_3_STOP();   ֹͣ ��ʱ  
 *        Motor_3_BRun();	  ���� ��ʱ 
 *        Motor_3_GRun();	  ǰ��	��ʱ 
 *        Motor_3_S_TR();	  ֹͣ ��ת  
 *        Motor_3_S_TL();	  ֹͣ ��ת  
 *        Motor_3_S_B_TR();	ֹͣ ���� ��ת  
 *        Motor_3_S_B_TL();	ֹͣ ���� ��ת  
 ******************************************************************************
**/


#include "Motor.h"
#include "LCD_ili9341.h"
#include "fonts.h"
void Dianji_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(D_GPIO_CLK,ENABLE);//��GPIOAʱ��
	//��������ģʽΪ�������
	GPIO_InitStruct.GPIO_Mode	=	GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin	=	D_INA_GPIO_PIN|D_INB_GPIO_PIN|D_INC_GPIO_PIN|D_IND_GPIO_PIN;
	//	//������������Ϊ50MHz
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(D_GPIO_PORT,&GPIO_InitStruct);
}

uint32_t i;




/********************************   1.��������ж�����      *********************************/
void Motor_1_STOP(void)      //ֹͣ
{
	ILI9341_DisplayStringEx(205,195,35,35,(uint8_t *)"ֹͣ",0);
	INA(Low);
	INB(Low); 
  INC(Low);
	IND(Low);

}
void Motor_1_GRun(void)				//ǰ��
{
	ILI9341_DisplayStringEx(205,195,35,35,(uint8_t *)"ǰ��",0);
	INA(High);
	INB(Low);
	INC(Low);
	IND(High);

}

void Motor_1_BRun(void)			//����
{
	ILI9341_DisplayStringEx(205,195,35,35,(uint8_t *)"����",0);
	INA(Low);
	INB(High);
	INC(High);
	IND(Low);

}


void Motor_1_TR(void)				//��ת
{
  ILI9341_DisplayStringEx(205,195,35,35,(uint8_t *)"��ת",0);
	INA(High);
	INB(Low);
	INC(High);
	IND(Low);

}

void Motor_1_TL(void)				//��ת
{
	ILI9341_DisplayStringEx(205,195,35,35,(uint8_t *)"��ת",0);
	INA(Low);
	INB(High);
	INC(Low);
	IND(High);

}

void Motor_1_MTR(void)				//����ת
{
  ILI9341_DisplayStringEx(205,195,35,35,(uint8_t *)"��ת",0);
	INC(High);
	IND(Low);
	INA(High);
	INB(High); 
}

void Motor_1_MTL(void)				//����ת
{
  ILI9341_DisplayStringEx(205,195,35,35,(uint8_t *)"��ת",0);
	INA(Low);
	INB(High);
	INC(High);
	IND(High);
}

/********************************   2.���ٵ���ж�����      *********************************/
void Motor_2_GRun(void)				//ǰ��
{
			for(i=0;i<100;i++)
			{
				if(i<P)
				{
					INA(High);
					INB(Low);
					INC(Low);
					IND(High);
				}
				else
				{
					INA(High);
					INB(High); 
					INC(High);
					IND(High);
				}
			}
}

void Motor_2_BRun(void)			//����
{

	for(i=0;i<100;i++)
			{
				if(i<P)
				{
					INA(Low);
					INB(High);
					INC(High);
					IND(Low);
				}
				else
				{
					INA(High);
					INB(High); 
					INC(High);
					IND(High);
				}
			}
}


void Motor_2_TR(void)				//��ת
{
	for(i=0;i<100;i++)
			{
				if(i<P)
				{
					INA(High);
					INB(Low);
					INC(High);
					IND(Low);
				}
				else
				{
					INA(High);
					INB(High); 
					INC(High);
					IND(High);
				}
			}
}

void Motor_2_TL(void)				//��ת
{

	for(i=0;i<100;i++)
			{
				if(i<P)
				{
					INA(Low);
					INB(High);
					INC(Low);
					IND(High);
				}
				else
				{
					INA(High);
					INB(High); 
					INC(High);
					IND(High);
				}
			}
}

//***************************************************************************************//

/********************************   3.�߼�����ж�����      *********************************/
void Motor_3_STOP(void)      //ֹͣ ��ʱ
{
	INA(High);
	INB(High); 
  INC(High);
	IND(High);
	Delay(0x4fffff);

}


void Motor_3_BRun(void)			//����	��ʱ
{
	INA(Low);
	INB(High);
	INC(High);
	IND(Low);
	Delay(0x4fffff);

}

void Motor_3_GRun(void)			//ǰ��	��ʱ
{
	INA(High);
	INB(Low);
	INC(Low);
	IND(High);
	Delay(0x4fffff);

}


void Motor_3_S_TR(void)				//ֹͣ ��ת
{
	Motor_1_STOP();
	Delay(0x4fffff);
	INA(High);
	INB(Low);
	INC(High);
	IND(Low);
	Delay(0xfffff);

}

void Motor_3_S_TL(void)				//ֹͣ ��ת
{
	Motor_1_STOP();
	Delay(0x4fffff);
	INA(Low);
	INB(High);
	INC(Low);
	IND(High);
	Delay(0xfffff);

}

void Motor_3_S_B_TR(void)				//ֹͣ ���� ��ת
{
	Motor_1_STOP();
	Delay(0x4fffff);
	Motor_1_BRun();
	Delay(0x3fffff);
	INA(High);
	INB(Low);
	INC(High);
	IND(Low);
	Delay(0x2fffff);

}

void Motor_3_S_B_TL(void)				//ֹͣ ���� ��ת
{
	Motor_1_STOP();
	Delay(0x4fffff);
	Motor_1_BRun();
	Delay(0x3fffff);
	INA(Low);
	INB(High);
	INC(Low);
	IND(High);
	Delay(0x2fffff);

}

