 /**
 ******************************************************************************
 * @file    Sensor.c
 * @author  Hua
 * @version V6.0
 * @date    2021-05-04
 * @brief   ���⴫������ʼ��
 ******************************************************************************
 * @attention
 *
 *    IO���䣺
 *
 *        -λ��-    IO   
 *         ��ǰ     E0
 *         ��ǰ     E1
 *         ���     E2
 *         �Һ�     E3
 *
 *		����˵����
 *
 *         FL_Y 		��ǰ���ϰ�
 *				 FR_Y 		��ǰ���ϰ�
 *         BL_Y 		������ϰ�
 *				 BR_Y 		�Һ����ϰ�
 *
 *         FL_N 		��ǰ���ϰ�
 *         FR_N 		��ǰ���ϰ�
 *         BL_N 		������ϰ�
 *         BR_N 		�Һ����ϰ�
 ******************************************************************************
**/

#include "Sensor.h"

void Sensor_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	//�����˿�����ʱ�� ��ѡ������˿ڣ�ENABLE/DISABLE��
	RCC_APB2PeriphClockCmd(Sensor_GPIO_CLK, ENABLE); 
	
	//ѡ��Ҫ���Ƶ�����
	GPIO_InitStruct.GPIO_Pin = Sensor_FL_GPIO_PIN|Sensor_FR_GPIO_PIN|Sensor_BL_GPIO_PIN|Sensor_BR_GPIO_PIN;
	//��������ģʽΪ
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;

	//���ÿ⺯������ʼ��GPIO
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

