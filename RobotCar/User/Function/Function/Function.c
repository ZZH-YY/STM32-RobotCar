/**
  ******************************************************************************
  * @file    Function.c
  * @author  Hua
  * @version V6.0
  * @date    2021-05-04
  * @brief   总控制函数
  ******************************************************************************
  * @attention
  *		
  ******************************************************************************
**/ 

#include "Function.h"
#include "Motor.h"
#include "Led.h"
#include "usart.h"
#include "usart2.h"
#include "Function_ADC.h"
#include "Sensor.h"

//extern uint8_t adjust;
extern uint8_t buffer[3];  //定义串口缓冲接收数组
extern uint8_t rec_flag;   //定义串口接收标志 1-正在接收 
//extern uint8_t Angle[8];

uint8_t LED_State;//车灯开关检测
uint8_t distance = 30; //ADC传感器检测距离

extern int Communication_Decode_flag; //接收完成标志位置 1-接受结束



/********************************************************************************************/
/*																		 串口动作组																		        */
/********************************************************************************************/
unsigned char DM_Action0[5]   = { 0xff, 0x09, 0x00, 0x00, 0x00 };               //动作组0
unsigned char DM_Action1[5]   = { 0xff, 0x09, 0x00, 0x01, 0x00 };               //动作组1
unsigned char DM_Action2[5]   = { 0xff, 0x09, 0x00, 0x02, 0x00 };               //动作组2
unsigned char DM_Action3[5]   = { 0xff, 0x09, 0x00, 0x03, 0x00 };               //动作组3
unsigned char DM_Action4[5]   = { 0xff, 0x09, 0x00, 0x04, 0x00 };               //动作组4
unsigned char DM_Action5[5]   = { 0xff, 0x09, 0x00, 0x05, 0x00 };               //动作组5
unsigned char DM_Action6[5]   = { 0xff, 0x09, 0x00, 0x06, 0x00 };               //动作组6
unsigned char DM_Action7[5]   = { 0xff, 0x09, 0x00, 0x07, 0x00 };               //动作组7
unsigned char DM_Action8[5]   = { 0xff, 0x09, 0x00, 0x08, 0x00 };               //动作组8
unsigned char DM_Action9[5]   = { 0xff, 0x09, 0x00, 0x09, 0x00 };               //动作组9
unsigned char DM_Action10[5]  = { 0xff, 0x09, 0x00, 0x0a, 0x00 };               //动作组a
unsigned char DM_Action11[5]  = { 0xff, 0x09, 0x00, 0x0b, 0x00 };               //动作组b
unsigned char DM_Action12[5]  = { 0xff, 0x09, 0x00, 0x0c, 0x00 };               //动作组c
unsigned char DM_Action13[5]  = { 0xff, 0x09, 0x00, 0x0d, 0x00 };               //动作组d
unsigned char DM_Action14[5]  = { 0xff, 0x09, 0x00, 0x0e, 0x00 };               //动作组e
unsigned char DM_Action15[5]  = { 0xff, 0x09, 0x00, 0x0f, 0x00 };               //动作组f

/********************************************************************************************/




/********************************************************************************************/
/*																		 总控制函数																		        */
/********************************************************************************************/
void Communication_Decode(void)
{
	if(Communication_Decode_flag)
	 {
			Communication_Decode_flag=0;
			if(buffer[0]==0x00)
			{
				 switch(buffer[1])
         {
					 case 0x00:
						 Motor_1_STOP();
						 return; //停止
					 case 0x01:					 
						 while(1)
						 {                                 
							 
		 					if(ADC_ConvertedValueLocal_Sensor(0) >= distance && \
							  ADC_ConvertedValueLocal_Sensor(1) >= distance && \
						    ADC_ConvertedValueLocal_Sensor(2) >= distance && \
						    ADC_ConvertedValueLocal_Sensor(3) >= distance && \
						    FR_Y && FR_Y)
								Motor_1_GRun(); //无障碍 无边缘 直行	
							
						 if(ADC_ConvertedValueLocal_Sensor(0) <  distance && \
							  ADC_ConvertedValueLocal_Sensor(1) >= distance || \
						    ADC_ConvertedValueLocal_Sensor(2) <  distance && \
						    ADC_ConvertedValueLocal_Sensor(3) >= distance)
						 {
								Motor_1_MTR();                                    //左侧障碍 右转
								Beep1();
						 }
						 
						 if(ADC_ConvertedValueLocal_Sensor(0) >= distance && \
							  ADC_ConvertedValueLocal_Sensor(1) <  distance || \
						    ADC_ConvertedValueLocal_Sensor(2) >= distance && \
						    ADC_ConvertedValueLocal_Sensor(3) <  distance)
						 {
								Motor_1_MTL();                                    //右侧障碍 左转
								Beep1();
						 }
						 
						 if(ADC_ConvertedValueLocal_Sensor(0) < distance && \
							  ADC_ConvertedValueLocal_Sensor(1) < distance || \
						    ADC_ConvertedValueLocal_Sensor(2) < distance && \
						    ADC_ConvertedValueLocal_Sensor(3) < distance)
						 {
								Motor_1_BRun();                                  //两侧障碍 后退
						    Beep1();
						 }
						 
					 	 if(FL_N && FR_Y)
						 {
							 Motor_3_S_B_TR();
						   Beep1();
						 }
						 
					 	 if(FL_Y && FR_N)
						 {
							 Motor_3_S_B_TL();
							 Beep1();
						 }

					 	 if(FL_N && FR_N)						 
								Motor_3_BRun();
							if(buffer[1]!=0x01)
								return;
						}
						 
					 case 0x02:
					   Motor_1_BRun();
					   return; //后退
					 case 0x03:
					   Motor_1_TR();
					   return;   //右转
					 case 0x04:
					   Motor_1_TL();
					   return;   //左转 
					 case 0x05:
					   Motor_1_MTL();
					   return;   //慢左转 
           case 0x06:
					   Motor_1_MTR();
					   return;   //慢右转 
				 }
			}
			//机械臂
			else if(buffer[0]==0x01)
			{
				 switch(buffer[1])
         {
					 case 0x00:UART_DM_ReportData(DM_Action0);return; 
					 case 0x01:UART_DM_ReportData(DM_Action1);return;
					 case 0x02:UART_DM_ReportData(DM_Action2);return;
					 case 0x03:UART_DM_ReportData(DM_Action3);return;
					 case 0x04:UART_DM_ReportData(DM_Action4);return;
					 case 0x05:UART_DM_ReportData(DM_Action5);return;
					 case 0x06:UART_DM_ReportData(DM_Action6);return;
					 case 0x07:UART_DM_ReportData(DM_Action7);return;
					 case 0x08:UART_DM_ReportData(DM_Action8);return;
					 case 0x09:UART_DM_ReportData(DM_Action9);return;
					 case 0x10:UART_DM_ReportData(DM_Action10);return;
					 case 0x11:UART_DM_ReportData(DM_Action11);return;
					 case 0x12:UART_DM_ReportData(DM_Action12);return;
					 case 0x13:UART_DM_ReportData(DM_Action13);return;
					 case 0x14:UART_DM_ReportData(DM_Action14);return;
					 case 0x15:UART_DM_ReportData(DM_Action15);return;
				 }
			}
			//车灯
			else if(buffer[0]==0x05)
			{
				 switch(buffer[1])
         {
					 case 0x00:
						 LED_ON;
					   Beep1();
						 LED_State = 1;
					 return; //开灯
					 case 0x01: 
						 LED_OFF;
					   Beep1();
					   LED_State = 0;
					 return; //关灯
				 }
			}
		}
}
/********************************************************************************************/



/********************************************************************************************/
/*																		 机械臂检测函数																		        */
/********************************************************************************************/
void Actuator_initialization(void)
{
	UART_DM_ReportData(DM_Action15);
}
/********************************************************************************************/


/********************************************************************************************/
/*																		  警戒模式函数																		        */
/********************************************************************************************/
void Guard_model(void)
{
	 if(ADC_ConvertedValueLocal_Sensor(0) >= 40 && \
			ADC_ConvertedValueLocal_Sensor(1) >= 40 && \
			ADC_ConvertedValueLocal_Sensor(2) >= 40 && \
			ADC_ConvertedValueLocal_Sensor(3) >= 40 && \
			ADC_ConvertedValueLocal_Sensor(4) >= 40 && \
			ADC_ConvertedValueLocal_Sensor(5) >= 40)
			Motor_1_STOP();
	 
	 if(ADC_ConvertedValueLocal_Sensor(0) <  40 && \
			ADC_ConvertedValueLocal_Sensor(1) >= 40 || \
			ADC_ConvertedValueLocal_Sensor(2) <  40 && \
			ADC_ConvertedValueLocal_Sensor(3) >= 40)
			Motor_1_BRun();

	 if(ADC_ConvertedValueLocal_Sensor(0) >= 40 && \
			ADC_ConvertedValueLocal_Sensor(1) <  40 || \
			ADC_ConvertedValueLocal_Sensor(2) >= 40 && \
			ADC_ConvertedValueLocal_Sensor(3) <  40)
			Motor_1_BRun();	
	 
	 if(ADC_ConvertedValueLocal_Sensor(4) <  40 || \
			ADC_ConvertedValueLocal_Sensor(5) <  40 )
			Motor_1_GRun();	
}
/********************************************************************************************/




