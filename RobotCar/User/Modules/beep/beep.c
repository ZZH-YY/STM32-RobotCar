#include "beep.h"
#include "SysTick.h"

void BEEP_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	//�����˿�����ʱ�� ��ѡ������˿ڣ�ENABLE/DISABLE��
	RCC_APB2PeriphClockCmd(BEEP_GPIO_CLK, ENABLE); 
	
	//ѡ��Ҫ���Ƶ�����
	GPIO_InitStruct.GPIO_Pin = BEEP_GPIO_PIN;
	//��������ģʽΪ�������
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	//������������Ϊ50MHz
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	//���ÿ⺯������ʼ��GPIO
	GPIO_Init(BEEP_GPIO_PORT,&GPIO_InitStruct);
	
}

void Beep1(void)
{
	BEEP_ON;
	Delay_ms(100);
	BEEP_OFF;
}

void Beep2(void)
{
	BEEP_ON;
	Delay_ms(100);
	BEEP_OFF;
	Delay_ms(100);
	BEEP_ON;
	Delay_ms(100);
	BEEP_OFF;
}

void Beep3(void)
{
	BEEP_ON;
	Delay_ms(100);
	BEEP_OFF;
	Delay_ms(100);
	BEEP_ON;
	Delay_ms(100);
	BEEP_OFF;
	Delay_ms(100);
	BEEP_ON;
	Delay_ms(100);
	BEEP_OFF;
}

void BeepL(void)
{
	BEEP_ON;
	Delay_ms(500);
	BEEP_OFF;
}
