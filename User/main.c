/*
 * @Author: JJ HE hjj20010422@163.com
 * @Date: 2022-07-26 12:26:58
 * @LastEditors: JJ HE hjj20010422@163.com
 * @LastEditTime: 2022-10-14 16:03:50
 * @FilePath: \NEWSTD\User\main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"						//加入TIM3定时10ms;给编码器记速
#include "Encoder.h"
#include "PWM.h"
#include "Drive.h"
#include "Serial.h"

int16_t EF,ER,EL,R;
int main(void)
{
	//uint8_t Myarray[]={'a','b','c'};
	OLED_Init();
	Serial_Init();
	//Serial_SendNum(123456789,9);
	//Serial_SendString("hhhhhh\r\n");
	//Serial_SendByte('A');
//while(a--)
	//Serial_SendArray(Myarray,3);
 	//Encoder_Init();
	//PWM_Init();
	//EXTI_TIM3_Init();	
//	OLED_ShowChar(1,1,'F');
//	OLED_ShowChar(2,1,'R');SX
//	OLED_ShowChar(3,1,'L');
//	printf("Num=%d\r\n",666);
//	sprintf(String,"Num=%d\r\n",666);
//	Serial_SendString(String);
//	
	Serial_printf("你好世界");
	while(1)
	{
		OLED_ShowNumber(1,1,55,10);
//		OLED_ShowSignedNum(1,3,EF,4);
//		OLED_ShowSignedNum(2,3,ER,4);
//		OLED_ShowSignedNum(3,3,EL,4);
//		OLED_ShowNum(4,1,R,8);
//																										//PWM_Set_R_F(110);
//																									

																										//Speed_Forward(50,EL,ER);
																										//Speed_Back(10,EL,ER);
																										//Speed_Left(30,EL,ER,EF);
																										//Speed_Right(3,EL,ER,EF);
																																																	
		
	}
	
}

void TIM3_IRQHandler(void)//定时时间位10毫秒；
{

	if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET)
		
	{
		
		EF=GetMf();//*100*65*3.14;
		ER=GetMr();//*100*65*3.14;
		EL=GetMl();//*100*65*3.14;
		
		R = Speed_Forward(70,EL,ER);
		//Speed_Back(10,EL,ER);
		//Speed_Left(30,EL,ER,EF);
		//R=Speed_Right(50,EL,ER,EF);
		
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
	}
}


