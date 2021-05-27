/**
 ******************************************************************************
 * @file    main.c
 * @author  Hua
 * @version V10.0
 * @date    2021-05-08
 * @brief   更新蜂鸣器提示
 ******************************************************************************
 * @attention
 * 1.实现功能：
 *		1.串口通讯控制
 *		2.串口控制机械臂（机械臂自动初始化）
 *	  3.串口控制开关灯
 *    4.自动检测障碍，自动避障
 * 		5.自动检测边缘，防掉落
 *
 *2.基本串口通讯协议：
 *    	命令		 包头  类型位	命令位 数据位	包尾
 *			停止			FF		00			00	  00	   FF
 *			前进			FF		00			01	  00	   FF
 *			后退			FF		00			02  	00     FF
 *			左转			FF		00			03	  00	   FF
 *			右转			FF		00			04	  00	   FF
 * 			左前转		FF		00			05	  00	   FF
 *			左后转		FF		00			06	  00	   FF
 *			右前转		FF		00			07	  00	   FF
 *			右后转		FF		00			08	  00	   FF
 *      开灯	    FF	  05	    00	  00	   FF
 *      关灯	    FF	  05	    01	  00	   FF
 *      动作组n   FF    01      0n    00     FF	(n=0-15)
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
//全局延时函数
void Delay( uint32_t count)
{
	for(;count!=0;count--);
}

int main(void)
{
	ILI9341_Init(); 
	
	
	//Sensor_GPIO_Config();
	
	//USART初始化
	USART_Config();
	
	//USART2初始化
	USART2_Config();
	
	//LED初始化
	LED_GPIO_Config();
	
	//机械臂检测初始化
	Actuator_initialization();
	
	//蜂鸣器初始化
	BEEP_GPIO_Config();
	
	//温湿度初始化
	DHT11_Init();
	
	//SPI_FLASH初始化
	SPI_FLASH_Init();
	
	//Systick
	SysTick_Init();
	
	//初始化DTT11的引脚
	DHT11_Init ();
	
	Firstface();
	Interface();
	
	//电机初始化
	Dianji_GPIO_Config();
	//ADC初始化
	ADCx_Init();
	//Sensor初始化
	while(1)
	{	
		//信息动态显示
	 	obtain_State();
		//执行命令
		Communication_Decode();
	}
}



