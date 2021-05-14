#ifndef _SENSOR_H
#define _SENSOR_H

#include "stm32f10x.h"

#define ON		0
#define OFF   1

//�������ϴ���������
#define Sensor_FL_GPIO_PIN			GPIO_Pin_8
#define Sensor_FR_GPIO_PIN			GPIO_Pin_9
#define Sensor_BL_GPIO_PIN			GPIO_Pin_2
#define Sensor_BR_GPIO_PIN			GPIO_Pin_3
#define Sensor_GPIO_PORT		  	GPIOC
#define Sensor_GPIO_CLK				  RCC_APB2Periph_GPIOC


#define FL_Y 		(Sensor_Scan(Sensor_GPIO_PORT,Sensor_FL_GPIO_PIN) == ON) //��ǰ���ϰ�
#define FR_Y 		(Sensor_Scan(Sensor_GPIO_PORT,Sensor_FR_GPIO_PIN) == ON) //��ǰ���ϰ�
#define BL_Y 		(Sensor_Scan(Sensor_GPIO_PORT,Sensor_BL_GPIO_PIN) == ON) //������ϰ�
#define BR_Y 		(Sensor_Scan(Sensor_GPIO_PORT,Sensor_BR_GPIO_PIN) == ON) //�Һ����ϰ�

#define FL_N 		(Sensor_Scan(Sensor_GPIO_PORT,Sensor_FL_GPIO_PIN) == OFF) //��ǰ���ϰ�
#define FR_N 		(Sensor_Scan(Sensor_GPIO_PORT,Sensor_FR_GPIO_PIN) == OFF) //��ǰ���ϰ�
#define BL_N 		(Sensor_Scan(Sensor_GPIO_PORT,Sensor_BL_GPIO_PIN) == OFF) //������ϰ�
#define BR_N 		(Sensor_Scan(Sensor_GPIO_PORT,Sensor_BR_GPIO_PIN) == OFF) //�Һ����ϰ�

void Sensor_GPIO_Config(void);
uint8_t Sensor_Scan(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);
#endif /* _SENSOR_H */

