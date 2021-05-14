/**
 ******************************************************************************
 * @file    Motor.c
 * @author  Hua
 * @version V6.0
 * @date    2021-05-04
 * @brief   电机模块初始化
 ******************************************************************************
 * @attention
 *
 *功能函数（可直接引用）：
 *
 *    1.基本电机行动函数
 *	  		Motor_1_STOP();   停止
 *	  		Motor_1_GRun();   前进
 *	  		Motor_1_BRun();   后退
 *		  	Motor_1_TR();     右转
 *		  	Motor_1_TL();     左转
 *
 *    2.减速电机行动
 *        Motor_2_GRun();   前进
 *        Motor_2_BRun();   后退
 *        Motor_2_TR();     右转
 *        Motor_2_TL();     左转
 *
 *    3.高级电机行动   
 *        Motor_3_STOP();   停止 延时  
 *        Motor_3_BRun();	  后退 延时 
 *        Motor_3_GRun();	  前进	延时 
 *        Motor_3_S_TR();	  停止 右转  
 *        Motor_3_S_TL();	  停止 左转  
 *        Motor_3_S_B_TR();	停止 后退 右转  
 *        Motor_3_S_B_TL();	停止 后退 左转  
 ******************************************************************************
**/


#include "Motor.h"
#include "LCD_ili9341.h"
#include "fonts.h"
void Dianji_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(D_GPIO_CLK,ENABLE);//用GPIOA时钟
	//设置引脚模式为推挽输出
	GPIO_InitStruct.GPIO_Mode	=	GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin	=	D_INA_GPIO_PIN|D_INB_GPIO_PIN|D_INC_GPIO_PIN|D_IND_GPIO_PIN;
	//	//设置引脚速率为50MHz
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(D_GPIO_PORT,&GPIO_InitStruct);
}

uint32_t i;




/********************************   1.基本电机行动机制      *********************************/
void Motor_1_STOP(void)      //停止
{
	ILI9341_DisplayStringEx(205,195,35,35,(uint8_t *)"停止",0);
	INA(Low);
	INB(Low); 
  INC(Low);
	IND(Low);

}
void Motor_1_GRun(void)				//前进
{
	ILI9341_DisplayStringEx(205,195,35,35,(uint8_t *)"前进",0);
	INA(High);
	INB(Low);
	INC(Low);
	IND(High);

}

void Motor_1_BRun(void)			//后退
{
	ILI9341_DisplayStringEx(205,195,35,35,(uint8_t *)"后退",0);
	INA(Low);
	INB(High);
	INC(High);
	IND(Low);

}


void Motor_1_TR(void)				//右转
{
  ILI9341_DisplayStringEx(205,195,35,35,(uint8_t *)"右转",0);
	INA(High);
	INB(Low);
	INC(High);
	IND(Low);

}

void Motor_1_TL(void)				//左转
{
	ILI9341_DisplayStringEx(205,195,35,35,(uint8_t *)"左转",0);
	INA(Low);
	INB(High);
	INC(Low);
	IND(High);

}

void Motor_1_MTR(void)				//慢右转
{
  ILI9341_DisplayStringEx(205,195,35,35,(uint8_t *)"右转",0);
	INC(High);
	IND(Low);
	INA(High);
	INB(High); 
}

void Motor_1_MTL(void)				//慢左转
{
  ILI9341_DisplayStringEx(205,195,35,35,(uint8_t *)"右转",0);
	INA(Low);
	INB(High);
	INC(High);
	IND(High);
}

/********************************   2.减速电机行动机制      *********************************/
void Motor_2_GRun(void)				//前进
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

void Motor_2_BRun(void)			//后退
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


void Motor_2_TR(void)				//右转
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

void Motor_2_TL(void)				//左转
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

/********************************   3.高级电机行动机制      *********************************/
void Motor_3_STOP(void)      //停止 延时
{
	INA(High);
	INB(High); 
  INC(High);
	IND(High);
	Delay(0x4fffff);

}


void Motor_3_BRun(void)			//后退	延时
{
	INA(Low);
	INB(High);
	INC(High);
	IND(Low);
	Delay(0x4fffff);

}

void Motor_3_GRun(void)			//前进	延时
{
	INA(High);
	INB(Low);
	INC(Low);
	IND(High);
	Delay(0x4fffff);

}


void Motor_3_S_TR(void)				//停止 右转
{
	Motor_1_STOP();
	Delay(0x4fffff);
	INA(High);
	INB(Low);
	INC(High);
	IND(Low);
	Delay(0xfffff);

}

void Motor_3_S_TL(void)				//停止 左转
{
	Motor_1_STOP();
	Delay(0x4fffff);
	INA(Low);
	INB(High);
	INC(Low);
	IND(High);
	Delay(0xfffff);

}

void Motor_3_S_B_TR(void)				//停止 后退 右转
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

void Motor_3_S_B_TL(void)				//停止 后退 左转
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

