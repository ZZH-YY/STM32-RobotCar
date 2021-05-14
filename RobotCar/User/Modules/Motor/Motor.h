#ifndef __Dianji_H
#define __Dianji_H

#include "stm32f10x.h"

//					电机控制引脚宏
//INA
#define D_INA_GPIO_PIN		GPIO_Pin_13
#define D_INB_GPIO_PIN		GPIO_Pin_12
#define D_INC_GPIO_PIN		GPIO_Pin_15
#define D_IND_GPIO_PIN		GPIO_Pin_14

#define D_GPIO_PORT		GPIOB
#define D_GPIO_CLK		RCC_APB2Periph_GPIOB



#define High 1 //宏定义 高为1
#define Low  0 //宏定义 低为0

#define INA(a) if (a) GPIO_SetBits(D_GPIO_PORT,D_INA_GPIO_PIN); else GPIO_ResetBits(D_GPIO_PORT,D_INA_GPIO_PIN) // 否则为低电平 
#define INB(a) if (a) GPIO_SetBits(D_GPIO_PORT,D_INB_GPIO_PIN); else GPIO_ResetBits(D_GPIO_PORT,D_INB_GPIO_PIN)
#define INC(a) if (a) GPIO_SetBits(D_GPIO_PORT,D_INC_GPIO_PIN); else GPIO_ResetBits(D_GPIO_PORT,D_INC_GPIO_PIN)
#define IND(a) if (a) GPIO_SetBits(D_GPIO_PORT,D_IND_GPIO_PIN); else GPIO_ResetBits(D_GPIO_PORT,D_IND_GPIO_PIN)


void Dianji_GPIO_Config(void);

#define P			50 //电机速度

/****     1.基本电机行动   ****/
void Motor_1_STOP(void); //停止
void Motor_1_GRun(void); //前进
void Motor_1_BRun(void); //后退
void Motor_1_TR(void);   //右转
void Motor_1_MTR(void);	//慢右转
void Motor_1_MTL(void);//慢左转
void Motor_1_TL(void);   //左转

/****     2.减速电机行动   ****/
void Motor_2_GRun(void); //前进
void Motor_2_BRun(void); //后退
void Motor_2_TR(void);   //右转
void Motor_2_TL(void);   //左转

/****     3.高级电机行动   ****/
void Motor_3_STOP(void);      //Motor_3_STOP();   停止 延时  
void Motor_3_GRun(void);			//Motor_3_GRun();   前进	延时
void Motor_3_BRun(void);			//Motor_3_BRun();   后退 延时  
void Motor_3_S_TR(void);			//Motor_3_S_TR();   停止 右转  
void Motor_3_S_TL(void);			//Motor_3_S_TL();   停止 左转  
void Motor_3_S_B_TR(void);		//Motor_3_S_B_TR(); 停止 后退 右转  
void Motor_3_S_B_TL(void);		//Motor_3_S_B_TL(); 停止 后退 左转  


#endif /* __Dianji_H*/

