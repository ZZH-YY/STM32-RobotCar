/**
  ******************************************************************************
  * @file    Function_ADC.c
  * @author  Hua
  * @version V6.0
  * @date    2021-05-04
  * @brief   ADC函数
  ******************************************************************************
  * @attention
  *		
  ******************************************************************************
**/ 

#include "Function_ADC.h"
#include "Sensor_ADC.h"
#include "usart.h"


// ADC1转换的电压值通过MDA方式传到SRAM
extern __IO uint16_t ADC_ConvertedValue[NOFCHANEL];
// 局部变量，用于保存转换计算后的电压值 	 
float ADC_ConvertedValueLocal[NOFCHANEL]; 

float ADC_ConvertedValueLocal_Sensor(uint16_t num)
{
	
	float CM;
	ADC_ConvertedValueLocal[num] =((2547.8/((float)ADC_ConvertedValue[num]*0.35-10.41)-0.42)*10+5);
	CM = ADC_ConvertedValueLocal[num];
	if(CM > 0 && CM < 500)
	{
			printf("\r\n CH0 value = %.2f CM \r\n",ADC_ConvertedValueLocal[num]);
			return CM;
	}
	else
	return 100;
}
	


