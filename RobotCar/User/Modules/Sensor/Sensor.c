 /**
 ******************************************************************************
 * @file    Sensor.c
 * @author  Hua
 * @version V6.0
 * @date    2021-05-04
 * @brief   红外传感器初始化
 ******************************************************************************
 * @attention
 *
 *    IO分配：
 *
 *        -位置-    IO   
 *         左前     E0
 *         右前     E1
 *         左后     E2
 *         右后     E3
 *
 *		定义说明：
 *
 *         FL_Y 		左前无障碍
 *				 FR_Y 		右前无障碍
 *         BL_Y 		左后无障碍
 *				 BR_Y 		右后无障碍
 *
 *         FL_N 		左前有障碍
 *         FR_N 		右前有障碍
 *         BL_N 		左后有障碍
 *         BR_N 		右后有障碍
 ******************************************************************************
**/

#include "Sensor.h"

void Sensor_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	//开启端口外设时钟 （选择外设端口，ENABLE/DISABLE）
	RCC_APB2PeriphClockCmd(Sensor_GPIO_CLK, ENABLE); 
	
	//选择要控制的引脚
	GPIO_InitStruct.GPIO_Pin = Sensor_FL_GPIO_PIN|Sensor_FR_GPIO_PIN|Sensor_BL_GPIO_PIN|Sensor_BR_GPIO_PIN;
	//设置引脚模式为
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;

	//调用库函数，初始化GPIO
	GPIO_Init(Sensor_GPIO_PORT,&GPIO_InitStruct);

}

uint8_t Sensor_Scan(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
	if(GPIO_ReadInputDataBit( GPIOx, GPIO_Pin)== ON)
	{
		return ON;
	}
	else return OFF;
}

