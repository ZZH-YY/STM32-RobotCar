/**
 ******************************************************************************
 * @file    main.c
 * @author  Hua
 * @version V10.0
 * @date    2021-05-08
 * @brief   ���·�������ʾ
 ******************************************************************************
 * @attention
 * 1.ʵ�ֹ��ܣ�
 *		1.����ͨѶ����
 *		2.���ڿ��ƻ�е�ۣ���е���Զ���ʼ����
 *	  3.���ڿ��ƿ��ص�
 *    4.�Զ�����ϰ����Զ�����
 * 		5.�Զ�����Ե��������
 *
 *2.��������ͨѶЭ�飺
 *    	����		 ��ͷ  ����λ	����λ ����λ	��β
 *			ֹͣ			FF		00			00	  00	   FF
 *			ǰ��			FF		00			01	  00	   FF
 *			����			FF		00			02  	00     FF
 *			��ת			FF		00			03	  00	   FF
 *			��ת			FF		00			04	  00	   FF
 * 			��ǰת		FF		00			05	  00	   FF
 *			���ת		FF		00			06	  00	   FF
 *			��ǰת		FF		00			07	  00	   FF
 *			�Һ�ת		FF		00			08	  00	   FF
 *      ����	    FF	  05	    00	  00	   FF
 *      �ص�	    FF	  05	    01	  00	   FF
 *      ������n   FF    01      0n    00     FF	(n=0-15)
 ******************************************************************************
**/

#include "stm32f10x.h"
#include "LCD_ili9341.h"
#include "function_LCD.h"
#include "SysTick.h"
#include "DHT11.h"
#include "SPI_flash.h"
#include "Motor.h"
#include "Sensor.h"
#include "usart.h"
#include "usart2.h"
#include "Led.h"
#include "function.h"
#include "beep.h"
#include "Sensor_ADC.h"
#include "function_ADC.h"
//ȫ����ʱ����
void Delay( uint32_t count)
{
	for(;count!=0;count--);
}

int main(void)
{
	ILI9341_Init(); 
	
	
	//Sensor_GPIO_Config();
	
	//USART��ʼ��
	USART_Config();
	
	//USART2��ʼ��
	USART2_Config();
	
	//LED��ʼ��
	LED_GPIO_Config();
	
	//��е�ۼ���ʼ��
	Actuator_initialization();
	
	//��������ʼ��
	BEEP_GPIO_Config();
	
	//��ʪ�ȳ�ʼ��
	DHT11_Init();
	
	//SPI_FLASH��ʼ��
	SPI_FLASH_Init();
	
	//Systick
	SysTick_Init();
	
	//��ʼ��DTT11������
	DHT11_Init ();
	
	Firstface();
	Interface();
	
	//�����ʼ��
	Dianji_GPIO_Config();
	//ADC��ʼ��
	ADCx_Init();
	//Sensor��ʼ��
	while(1)
	{	
		//��Ϣ��̬��ʾ
	 	obtain_State();
		//ִ������
		Communication_Decode();
	}
}



