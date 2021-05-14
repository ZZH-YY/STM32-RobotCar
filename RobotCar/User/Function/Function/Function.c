/**
  ******************************************************************************
  * @file    Function.c
  * @author  Hua
  * @version V6.0
  * @date    2021-05-04
  * @brief   �ܿ��ƺ���
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
extern uint8_t buffer[3];  //���崮�ڻ����������
extern uint8_t rec_flag;   //���崮�ڽ��ձ�־ 1-���ڽ��� 
//extern uint8_t Angle[8];

uint8_t LED_State;//���ƿ��ؼ��
uint8_t distance = 30; //ADC������������

extern int Communication_Decode_flag; //������ɱ�־λ�� 1-���ܽ���



/********************************************************************************************/
/*																		 ���ڶ�����																		        */
/********************************************************************************************/
unsigned char DM_Action0[5]   = { 0xff, 0x09, 0x00, 0x00, 0x00 };               //������0
unsigned char DM_Action1[5]   = { 0xff, 0x09, 0x00, 0x01, 0x00 };               //������1
unsigned char DM_Action2[5]   = { 0xff, 0x09, 0x00, 0x02, 0x00 };               //������2
unsigned char DM_Action3[5]   = { 0xff, 0x09, 0x00, 0x03, 0x00 };               //������3
unsigned char DM_Action4[5]   = { 0xff, 0x09, 0x00, 0x04, 0x00 };               //������4
unsigned char DM_Action5[5]   = { 0xff, 0x09, 0x00, 0x05, 0x00 };               //������5
unsigned char DM_Action6[5]   = { 0xff, 0x09, 0x00, 0x06, 0x00 };               //������6
unsigned char DM_Action7[5]   = { 0xff, 0x09, 0x00, 0x07, 0x00 };               //������7
unsigned char DM_Action8[5]   = { 0xff, 0x09, 0x00, 0x08, 0x00 };               //������8
unsigned char DM_Action9[5]   = { 0xff, 0x09, 0x00, 0x09, 0x00 };               //������9
unsigned char DM_Action10[5]  = { 0xff, 0x09, 0x00, 0x0a, 0x00 };               //������a
unsigned char DM_Action11[5]  = { 0xff, 0x09, 0x00, 0x0b, 0x00 };               //������b
unsigned char DM_Action12[5]  = { 0xff, 0x09, 0x00, 0x0c, 0x00 };               //������c
unsigned char DM_Action13[5]  = { 0xff, 0x09, 0x00, 0x0d, 0x00 };               //������d
unsigned char DM_Action14[5]  = { 0xff, 0x09, 0x00, 0x0e, 0x00 };               //������e
unsigned char DM_Action15[5]  = { 0xff, 0x09, 0x00, 0x0f, 0x00 };               //������f

/********************************************************************************************/




/********************************************************************************************/
/*																		 �ܿ��ƺ���																		        */
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
						 return; //ֹͣ
					 case 0x01:					 
						 while(1)
						 {                                 
							 
		 					if(ADC_ConvertedValueLocal_Sensor(0) >= distance && \
							  ADC_ConvertedValueLocal_Sensor(1) >= distance && \
						    ADC_ConvertedValueLocal_Sensor(2) >= distance && \
						    ADC_ConvertedValueLocal_Sensor(3) >= distance && \
						    FR_Y && FR_Y)
								Motor_1_GRun(); //���ϰ� �ޱ�Ե ֱ��	
							
						 if(ADC_ConvertedValueLocal_Sensor(0) <  distance && \
							  ADC_ConvertedValueLocal_Sensor(1) >= distance || \
						    ADC_ConvertedValueLocal_Sensor(2) <  distance && \
						    ADC_ConvertedValueLocal_Sensor(3) >= distance)
						 {
								Motor_1_MTR();                                    //����ϰ� ��ת
								Beep1();
						 }
						 
						 if(ADC_ConvertedValueLocal_Sensor(0) >= distance && \
							  ADC_ConvertedValueLocal_Sensor(1) <  distance || \
						    ADC_ConvertedValueLocal_Sensor(2) >= distance && \
						    ADC_ConvertedValueLocal_Sensor(3) <  distance)
						 {
								Motor_1_MTL();                                    //�Ҳ��ϰ� ��ת
								Beep1();
						 }
						 
						 if(ADC_ConvertedValueLocal_Sensor(0) < distance && \
							  ADC_ConvertedValueLocal_Sensor(1) < distance || \
						    ADC_ConvertedValueLocal_Sensor(2) < distance && \
						    ADC_ConvertedValueLocal_Sensor(3) < distance)
						 {
								Motor_1_BRun();                                  //�����ϰ� ����
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
					   return; //����
					 case 0x03:
					   Motor_1_TR();
					   return;   //��ת
					 case 0x04:
					   Motor_1_TL();
					   return;   //��ת 
					 case 0x05:
					   Motor_1_MTL();
					   return;   //����ת 
           case 0x06:
					   Motor_1_MTR();
					   return;   //����ת 
				 }
			}
			//��е��
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
			//����
			else if(buffer[0]==0x05)
			{
				 switch(buffer[1])
         {
					 case 0x00:
						 LED_ON;
					   Beep1();
						 LED_State = 1;
					 return; //����
					 case 0x01: 
						 LED_OFF;
					   Beep1();
					   LED_State = 0;
					 return; //�ص�
				 }
			}
		}
}
/********************************************************************************************/



/********************************************************************************************/
/*																		 ��е�ۼ�⺯��																		        */
/********************************************************************************************/
void Actuator_initialization(void)
{
	UART_DM_ReportData(DM_Action15);
}
/********************************************************************************************/


/********************************************************************************************/
/*																		  ����ģʽ����																		        */
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




