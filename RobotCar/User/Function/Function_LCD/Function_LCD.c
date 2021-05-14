#include "LCD_ili9341.h"
#include "Function_LCD.h"
#include "Function.h"
#include "fonts.h"
#include "DHT11.h"
#include "beep.h"
#include "SysTick.h"
#include "Function_ADC.h"

char Humidity[100];
char Temperature[100];
extern distance;
extern  uint8_t LED_State;


DHT11_Data_TypeDef DHT11_Data;


void Firstface(void)
{
	uint8_t i;
	LCD_SetFont(&Font8x16);
  LCD_SetColors(RED,BLACK);
	ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);	/* 清屏，显示全黑 */
	
	//边框
	
//		ILI9341_DrawLine(70,220,250,220); //下
//		ILI9341_DrawLine(70,20,250,20); //上	
//		ILI9341_DrawLine(70,20,70,220);   //左
//		ILI9341_DrawLine(250,20,250,220); //右

//	ILI9341_DrawLine(12,228,308,228);//下
//	ILI9341_DrawLine(12,12,308,12); //上	
//	ILI9341_DrawLine(12,12,12,228);   //左
//	ILI9341_DrawLine(308,12,308,228); //右
//	Delay_ms(x)

	
	//16s
		LCD_SetTextColor(WHITE);	
		ILI9341_DisplayStringEx(90,35,35,35,(uint8_t *)"正在启动",0);
		ILI9341_DisplayStringEx(280,210,25,25,(uint8_t *)"16s",0);
	  LCD_SetTextColor(RED);	
		ILI9341_DisplayStringEx(90,120,20,20,(uint8_t *)"机械臂检测中..",0);
		ILI9341_DisplayStringEx(90,160,20,20,(uint8_t *)" WIFI启动中..",0);
		Delay_ms(1000);
		ILI9341_Clear(210,120,30,20);
		ILI9341_Clear(200,160,30,20);
		
	//15s
		LCD_SetTextColor(WHITE);	
		ILI9341_DisplayStringEx(90,35,35,35,(uint8_t *)"正在启动",0);
		ILI9341_DisplayStringEx(280,210,25,25,(uint8_t *)"15s",0);
	  LCD_SetTextColor(RED);	
		ILI9341_DisplayStringEx(90,120,20,20,(uint8_t *)"机械臂检测中...",0);
		ILI9341_DisplayStringEx(90,160,20,20,(uint8_t *)" WIFI启动中...",0);
		Delay_ms(1000);
		ILI9341_Clear(210,120,30,20);
		ILI9341_Clear(200,160,30,20);
		

	//14s
		LCD_SetTextColor(WHITE);	
		ILI9341_DisplayStringEx(90,35,35,35,(uint8_t *)"正在启动",0);
		ILI9341_DisplayStringEx(280,210,25,25,(uint8_t *)"14s",0);
	  LCD_SetTextColor(RED);	
		ILI9341_DisplayStringEx(90,120,20,20,(uint8_t *)"机械臂检测中",0);
		ILI9341_DisplayStringEx(90,160,20,20,(uint8_t *)" WIFI启动中",0);
		Delay_ms(1000);
		ILI9341_Clear(210,120,30,20);
		ILI9341_Clear(200,160,30,20);
		
		
	//13s
		LCD_SetTextColor(WHITE);	
		ILI9341_DisplayStringEx(90,35,35,35,(uint8_t *)"正在启动",0);
		ILI9341_DisplayStringEx(280,210,25,25,(uint8_t *)"13s",0);
	  LCD_SetTextColor(RED);	
		ILI9341_DisplayStringEx(90,120,20,20,(uint8_t *)"机械臂检测中.",0);
		ILI9341_DisplayStringEx(90,160,20,20,(uint8_t *)" WIFI启动中.",0);
		Delay_ms(1000);
		ILI9341_Clear(210,120,30,20);
		ILI9341_Clear(200,160,30,20);
		
		
	//12s
		LCD_SetTextColor(WHITE);	
		ILI9341_DisplayStringEx(90,35,35,35,(uint8_t *)"正在启动",0);
		ILI9341_DisplayStringEx(280,210,25,25,(uint8_t *)"12s",0);
	  LCD_SetTextColor(RED);	
		ILI9341_DisplayStringEx(90,120,20,20,(uint8_t *)"机械臂检测中..",0);
		ILI9341_DisplayStringEx(90,160,20,20,(uint8_t *)" WIFI启动中..",0);
		Delay_ms(1000);
		ILI9341_Clear(210,120,30,20);
		ILI9341_Clear(200,160,30,20);
		

	//11s
		LCD_SetTextColor(WHITE);	
		ILI9341_DisplayStringEx(90,35,35,35,(uint8_t *)"正在启动",0);
		ILI9341_DisplayStringEx(280,210,25,25,(uint8_t *)"11s",0);
	  LCD_SetTextColor(RED);	
		ILI9341_DisplayStringEx(90,120,20,20,(uint8_t *)"机械臂检测中...",0);
		ILI9341_DisplayStringEx(90,160,20,20,(uint8_t *)" WIFI启动中...",0);
		Delay_ms(1000);
		ILI9341_Clear(210,120,30,20);
		ILI9341_Clear(200,160,30,20);
		

	//10s
		LCD_SetTextColor(WHITE);	
		ILI9341_DisplayStringEx(90,35,35,35,(uint8_t *)"正在启动",0);
		ILI9341_DisplayStringEx(280,210,25,25,(uint8_t *)"10s",0);
	  LCD_SetTextColor(RED);	
		ILI9341_DisplayStringEx(90,120,20,20,(uint8_t *)"机械臂检测中",0);
		ILI9341_DisplayStringEx(90,160,20,20,(uint8_t *)" WIFI启动中",0);
		Delay_ms(1000);
		ILI9341_Clear(210,120,30,20);
		ILI9341_Clear(200,160,30,20);
		
		
	//9s
		LCD_SetTextColor(WHITE);	
		ILI9341_DisplayStringEx(90,35,35,35,(uint8_t *)"正在启动",0);
		ILI9341_DisplayStringEx(280,210,25,25,(uint8_t *)"09s",0);
	  LCD_SetTextColor(RED);	
		ILI9341_DisplayStringEx(90,120,20,20,(uint8_t *)"机械臂检测中.",0);
		ILI9341_DisplayStringEx(90,160,20,20,(uint8_t *)" WIFI启动中.",0);
		Delay_ms(1000);
		ILI9341_Clear(210,120,30,20);
		ILI9341_Clear(200,160,30,20);

		
	//8s
		LCD_SetTextColor(WHITE);	
		ILI9341_DisplayStringEx(90,35,35,35,(uint8_t *)"正在启动",0);
		ILI9341_DisplayStringEx(280,210,25,25,(uint8_t *)"08s",0);
	  LCD_SetTextColor(RED);	
		ILI9341_DisplayStringEx(90,120,20,20,(uint8_t *)"机械臂检测中..",0);
		ILI9341_DisplayStringEx(90,160,20,20,(uint8_t *)" WIFI启动中..",0);
		Delay_ms(1000);
		ILI9341_Clear(210,120,30,20);
		ILI9341_Clear(200,160,30,20);
		
	//7s
		LCD_SetTextColor(WHITE);	
		ILI9341_DisplayStringEx(90,35,35,35,(uint8_t *)"正在启动",0);
		ILI9341_DisplayStringEx(280,210,25,25,(uint8_t *)"07s",0);
	  LCD_SetTextColor(RED);	
		ILI9341_DisplayStringEx(90,120,20,20,(uint8_t *)"机械臂检测中...",0);
		ILI9341_DisplayStringEx(90,160,20,20,(uint8_t *)" WIFI启动中...",0);
		Delay_ms(1000);
		ILI9341_Clear(210,120,30,20);
		ILI9341_Clear(200,160,30,20);

	//6s
		LCD_SetTextColor(WHITE);	
		ILI9341_DisplayStringEx(90,35,35,35,(uint8_t *)"正在启动",0);
		ILI9341_DisplayStringEx(280,210,25,25,(uint8_t *)"06s",0);
	  LCD_SetTextColor(RED);	
		ILI9341_DisplayStringEx(90,120,20,20,(uint8_t *)"机械臂检测中",0);
		ILI9341_DisplayStringEx(90,160,20,20,(uint8_t *)" WIFI启动中",0);
		Delay_ms(1000);
		ILI9341_Clear(210,120,30,20);
		ILI9341_Clear(200,160,30,20);
		
	//5s
		LCD_SetTextColor(WHITE);	
		ILI9341_DisplayStringEx(90,35,35,35,(uint8_t *)"正在启动",0);
		ILI9341_DisplayStringEx(280,210,25,25,(uint8_t *)"05s",0);
	  LCD_SetTextColor(GREEN);	
		ILI9341_DisplayStringEx(90,120,20,20,(uint8_t *)"机械臂检测完成",0);
		BeepL();
		LCD_SetTextColor(RED);	
		ILI9341_DisplayStringEx(90,160,20,20,(uint8_t *)" WIFI启动中.",0);
		Delay_ms(1000);
		//ILI9341_Clear(210,120,30,20);
		ILI9341_Clear(200,160,30,20);
		
		
	//4s
		LCD_SetTextColor(WHITE);	
		ILI9341_DisplayStringEx(90,35,35,35,(uint8_t *)"正在启动",0);
		ILI9341_DisplayStringEx(280,210,25,25,(uint8_t *)"04s",0);
	  LCD_SetTextColor(GREEN);	
		ILI9341_DisplayStringEx(90,120,20,20,(uint8_t *)"机械臂检测完成",0);
		LCD_SetTextColor(RED);	
		ILI9341_DisplayStringEx(90,160,20,20,(uint8_t *)" WIFI启动中..",0);
		Delay_ms(1000);
		//ILI9341_Clear(210,120,30,20);
		ILI9341_Clear(200,160,30,20);
		

	//3s
		LCD_SetTextColor(WHITE);	
		ILI9341_DisplayStringEx(90,35,35,35,(uint8_t *)"正在启动",0);
		ILI9341_DisplayStringEx(280,210,25,25,(uint8_t *)"03s",0);
	  LCD_SetTextColor(GREEN);	
		ILI9341_DisplayStringEx(90,120,20,20,(uint8_t *)"机械臂检测完成",0);
		LCD_SetTextColor(RED);	
		ILI9341_DisplayStringEx(90,160,20,20,(uint8_t *)" WIFI启动中...",0);
		Delay_ms(1000);
		//ILI9341_Clear(210,120,30,20);
		ILI9341_Clear(200,160,30,20);
	
		
	//2s
		LCD_SetTextColor(WHITE);	
		ILI9341_DisplayStringEx(90,35,35,35,(uint8_t *)"正在启动",0);
		ILI9341_DisplayStringEx(280,210,25,25,(uint8_t *)"02s",0);
	  LCD_SetTextColor(GREEN);	
		ILI9341_DisplayStringEx(90,120,20,20,(uint8_t *)"机械臂检测完成",0);
		LCD_SetTextColor(RED);	
		ILI9341_DisplayStringEx(90,160,20,20,(uint8_t *)" WIFI启动中",0);
		Delay_ms(1000);
		//ILI9341_Clear(210,120,30,20);
		ILI9341_Clear(200,160,30,20);
		

	//1s
		LCD_SetTextColor(WHITE);	
		ILI9341_DisplayStringEx(90,35,35,35,(uint8_t *)"正在启动",0);
		ILI9341_DisplayStringEx(280,210,25,25,(uint8_t *)"01s",0);
	  LCD_SetTextColor(GREEN);	
		ILI9341_DisplayStringEx(90,120,20,20,(uint8_t *)"机械臂检测完成",0);
		ILI9341_DisplayStringEx(90,160,20,20,(uint8_t *)" WIFI启动完成",0);
		BeepL();
		Delay_ms(1000);
		
	//0s
		LCD_SetTextColor(WHITE);	
		ILI9341_DisplayStringEx(90,35,35,35,(uint8_t *)"正在启动",0);
		ILI9341_DisplayStringEx(280,210,25,25,(uint8_t *)"00s",0);
	  LCD_SetTextColor(GREEN);	
		ILI9341_DisplayStringEx(90,120,20,20,(uint8_t *)"机械臂检测完成",0);
		ILI9341_DisplayStringEx(90,160,20,20,(uint8_t *)" WIFI启动完成",0);
		Delay_ms(2000);
		
}

//界面展示
void Interface(void)
{
	
	LCD_SetFont(&Font8x16);
  LCD_SetColors(RED,BLACK);
	ILI9341_Clear(0,0,LCD_X_LENGTH,LCD_Y_LENGTH);	/* 清屏，显示全黑 */
	
	/*******显示边框******/
	LCD_SetTextColor(WHITE);
	ILI9341_DrawLine(5,239,315,239); //下
	ILI9341_DrawLine(5,28,315,28); //上	
	ILI9341_DrawLine(5,28,5,239);   //左
	ILI9341_DrawLine(315,28,315,239); //右2
	ILI9341_DrawLine(160,28,160,239); //右1
	
	
	

	/********显示标题*******/ 
	LCD_SetTextColor(WHITE);
	ILI9341_DisplayStringEx(40,0,24,24,(uint8_t *)"行车状态实时监测系统",0);
	LCD_SetTextColor(GREEN);
	ILI9341_DisplayStringEx(285,11,15,15,(uint8_t *)"V8.0",0);
	
	/********显示设备状态*******/ 
	LCD_SetTextColor(WHITE);
	ILI9341_DisplayStringEx(10,30,18,18,(uint8_t *)" ---设备状态---",0);
	LCD_SetTextColor(WHITE);
	ILI9341_DisplayStringEx(20,55,18,18,(uint8_t *)"无线网:",0);
	LCD_SetTextColor(GREEN);
	ILI9341_DisplayStringEx(85,55,18,18,(uint8_t *)"开启",0);
	
	LCD_SetTextColor(WHITE);
	ILI9341_DisplayStringEx(20,75,18,18,(uint8_t *)"摄像头:",0);
	LCD_SetTextColor(GREEN);
	ILI9341_DisplayStringEx(85,75,18,18,(uint8_t *)"开启",0);
	
	LCD_SetTextColor(WHITE);
	ILI9341_DisplayStringEx(20,95,18,18,(uint8_t *)"车  灯:",0);

	
	
	/********显示环境信息*******/ 
	LCD_SetTextColor(WHITE);
	ILI9341_DisplayStringEx(10,120,18,18,(uint8_t *)" ---环境信息---",0);
	LCD_SetTextColor(WHITE);
	ILI9341_DisplayStringEx(20,145,18,18,(uint8_t *)"温度:",0);
	LCD_SetTextColor(WHITE);
	ILI9341_DisplayStringEx(20,165,18,18,(uint8_t *)"湿度:",0);
	LCD_SetTextColor(GREEN);
	
	/********显示USART状态*******/ 
	LCD_SetTextColor(WHITE);
	ILI9341_DisplayStringEx(7,190,18,18,(uint8_t *)" ---USART状态---",0);
	LCD_SetTextColor(WHITE);
	ILI9341_DisplayStringEx(20,213,18,18,(uint8_t *)"RX:",0);
	LCD_SetTextColor(GREEN);
	ILI9341_DisplayStringEx(50,213,18,18,(uint8_t *)"YES",0);
	LCD_SetTextColor(WHITE);
	ILI9341_DisplayStringEx(90,213,18,18,(uint8_t *)"TX:",0);
	LCD_SetTextColor(GREEN);
	ILI9341_DisplayStringEx(120,213,18,18,(uint8_t *)"YES",0);
	
	/********显示车图*******/  
	LCD_SetTextColor(BLUE);
	ILI9341_DrawLine(215,75,265,75); //上	
	ILI9341_DrawLine(215,155,265,155); //下	
	ILI9341_DrawLine(215,75,215,155);   //左
	ILI9341_DrawLine(265,75,265,155); //右
	//左轮
	ILI9341_DrawLine(213,72,213,158);//右
	ILI9341_DrawLine(200,72,200,158);//左
	ILI9341_DrawLine(200,72,213,72); //上
	ILI9341_DrawLine(200,77,213,77); //上
	ILI9341_DrawLine(200,82,213,82); //上
	ILI9341_DrawLine(200,87,213,87); //上
	ILI9341_DrawLine(200,92,213,92); //上
	ILI9341_DrawLine(200,97,213,97); //上
	ILI9341_DrawLine(200,102,213,102); //上
	ILI9341_DrawLine(200,107,213,107); //上
	ILI9341_DrawLine(200,112,213,112); //上
	ILI9341_DrawLine(200,117,213,117); //上
	ILI9341_DrawLine(200,122,213,122); //上
	ILI9341_DrawLine(200,127,213,127); //上
	ILI9341_DrawLine(200,132,213,132); //上
	ILI9341_DrawLine(200,137,213,137); //上
	ILI9341_DrawLine(200,142,213,142); //上
	ILI9341_DrawLine(200,147,213,147); //上
	ILI9341_DrawLine(200,152,213,152); //上
	ILI9341_DrawLine(200,158,213,158); //上
	//右轮
	ILI9341_DrawLine(267,72,267,158); // 左
	ILI9341_DrawLine(280,72,280,158); //右
	ILI9341_DrawLine(267,72,280,72); //上
	ILI9341_DrawLine(267,77,280,77); //上
	ILI9341_DrawLine(267,82,280,82); //上
	ILI9341_DrawLine(267,87,280,87); //上
	ILI9341_DrawLine(267,92,280,92); //上
	ILI9341_DrawLine(267,97,280,97); //上
	ILI9341_DrawLine(267,102,280,102); //上
	ILI9341_DrawLine(267,107,280,107); //上
	ILI9341_DrawLine(267,112,280,112); //上
	ILI9341_DrawLine(267,117,280,117); //上
	ILI9341_DrawLine(267,122,280,122); //上
	ILI9341_DrawLine(267,127,280,127); //上
	ILI9341_DrawLine(267,132,280,132); //上
	ILI9341_DrawLine(267,137,280,137); //上
	ILI9341_DrawLine(267,142,280,142); //上
	ILI9341_DrawLine(267,147,280,147); //上
	ILI9341_DrawLine(267,152,280,152); //上
	ILI9341_DrawLine(267,158,280,158); //上
	//车灯
  ILI9341_DrawRectangle(250,72,10,4,0);
	ILI9341_DrawRectangle(220,72,10,4,0);

	//分割线
	LCD_SetTextColor(WHITE);
	ILI9341_DisplayStringEx(167,170,18,18,(uint8_t *)" ---车辆状态---",0);
	Beep3();
}
//数据动态显示
void obtain_State(void)
{
	/********温度显示*******/ 
	if( DHT11_Read_TempAndHumidity ( & DHT11_Data ) == SUCCESS)
	{
			LCD_SetTextColor(GREEN);
			sprintf(Temperature,"%d.%d℃",DHT11_Data.temp_int,DHT11_Data.temp_deci);
			ILI9341_DisplayStringEx(70,145,20,20,Temperature,0);
			sprintf(Humidity,"%d.%d％",DHT11_Data.humi_int,DHT11_Data.humi_deci);
			ILI9341_DisplayStringEx(70,165,20,20,Humidity,0);
	}	
	
	/********车灯开关显示*******/ 
	if(LED_State==1)
	{
		LCD_SetTextColor(GREEN);
		ILI9341_DisplayStringEx(85,95,18,18,(uint8_t *)"开启",0);
	}
	else if(LED_State==0)
	{
		LCD_SetTextColor(RED);
		ILI9341_DisplayStringEx(85,95,18,18,(uint8_t *)"关闭",0);
	}
	
	/********车辆状态显示*******/ 
  //车辆状态显示在Motor.c中
  
	//传感器状态显示在Function.c中
  //ADC传感器状态
//
	
	//ADC传感器状态
	LCD_SetTextColor(YELLOW);
	ILI9341_DrawCircle(225,85,5,1);//左前
	ILI9341_DrawCircle(255,85,5,1);//右前
	ILI9341_DrawCircle(225,145,5,1);//左后
	ILI9341_DrawCircle(255,145,5,1);//右后
}

static void Delay ( __IO uint32_t nCount )
{
  for ( ; nCount != 0; nCount -- );
	
}


