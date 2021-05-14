#ifndef __Dianji_H
#define __Dianji_H

#include "stm32f10x.h"

//					����������ź�
//INA
#define D_INA_GPIO_PIN		GPIO_Pin_13
#define D_INB_GPIO_PIN		GPIO_Pin_12
#define D_INC_GPIO_PIN		GPIO_Pin_15
#define D_IND_GPIO_PIN		GPIO_Pin_14

#define D_GPIO_PORT		GPIOB
#define D_GPIO_CLK		RCC_APB2Periph_GPIOB



#define High 1 //�궨�� ��Ϊ1
#define Low  0 //�궨�� ��Ϊ0

#define INA(a) if (a) GPIO_SetBits(D_GPIO_PORT,D_INA_GPIO_PIN); else GPIO_ResetBits(D_GPIO_PORT,D_INA_GPIO_PIN) // ����Ϊ�͵�ƽ 
#define INB(a) if (a) GPIO_SetBits(D_GPIO_PORT,D_INB_GPIO_PIN); else GPIO_ResetBits(D_GPIO_PORT,D_INB_GPIO_PIN)
#define INC(a) if (a) GPIO_SetBits(D_GPIO_PORT,D_INC_GPIO_PIN); else GPIO_ResetBits(D_GPIO_PORT,D_INC_GPIO_PIN)
#define IND(a) if (a) GPIO_SetBits(D_GPIO_PORT,D_IND_GPIO_PIN); else GPIO_ResetBits(D_GPIO_PORT,D_IND_GPIO_PIN)


void Dianji_GPIO_Config(void);

#define P			50 //����ٶ�

/****     1.��������ж�   ****/
void Motor_1_STOP(void); //ֹͣ
void Motor_1_GRun(void); //ǰ��
void Motor_1_BRun(void); //����
void Motor_1_TR(void);   //��ת
void Motor_1_MTR(void);	//����ת
void Motor_1_MTL(void);//����ת
void Motor_1_TL(void);   //��ת

/****     2.���ٵ���ж�   ****/
void Motor_2_GRun(void); //ǰ��
void Motor_2_BRun(void); //����
void Motor_2_TR(void);   //��ת
void Motor_2_TL(void);   //��ת

/****     3.�߼�����ж�   ****/
void Motor_3_STOP(void);      //Motor_3_STOP();   ֹͣ ��ʱ  
void Motor_3_GRun(void);			//Motor_3_GRun();   ǰ��	��ʱ
void Motor_3_BRun(void);			//Motor_3_BRun();   ���� ��ʱ  
void Motor_3_S_TR(void);			//Motor_3_S_TR();   ֹͣ ��ת  
void Motor_3_S_TL(void);			//Motor_3_S_TL();   ֹͣ ��ת  
void Motor_3_S_B_TR(void);		//Motor_3_S_B_TR(); ֹͣ ���� ��ת  
void Motor_3_S_B_TL(void);		//Motor_3_S_B_TL(); ֹͣ ���� ��ת  


#endif /* __Dianji_H*/

