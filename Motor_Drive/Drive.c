#include "stm32f10x.h"                  // Device header
#include "PWM.h"            //pwm为255最高

uint8_t Speed_Forward(uint16_t Target_speed,int16_t Encoder_L,int16_t Encoder_R)
{
	static uint8_t L=111,R=110;
	PWM_Set_F_F(255);
	PWM_Set_F_R(255);     //前电机刹车；
	PWM_Set_L_R(0);
	PWM_Set_R_F(0);
	
	
	
	if(Encoder_L==Target_speed)			{L+=0;}
	if(Encoder_L <Target_speed)			{L+=1;}
	if(Encoder_L >Target_speed)			{L-=1;}
	
	if((-Encoder_R)==Target_speed)		{R+=0;}
	if((-Encoder_R) <Target_speed)		{R+=1;}
	if((-Encoder_R) >Target_speed)		{R-=1;}
	PWM_Set_L_F(L);
	PWM_Set_R_R(R);
	return R;
	
}


//void Speed_Forward(uint16_t Target_speed,int16_t Encoder_L,int16_t Encoder_R)
//{
//	static uint8_t L,R;
//	PWM_Set_F_F(255);
//	PWM_Set_F_R(255);     //前电机刹车；
//	PWM_Set_L_R(0);
//	PWM_Set_R_F(0);
//	
//	
//	
//	if(Encoder_L==Target_speed)			{L+=0;}
//	if(Encoder_L <Target_speed)			{L+=(Target_speed-Encoder_L);}
//	if(Encoder_L >Target_speed)			{L-=(Encoder_L-Target_speed);}
//	
//	if((-Encoder_R)==Target_speed)		{R+=0;}
//	if((-Encoder_R) <Target_speed)		{R+=(Target_speed-(-Encoder_R));}
//	if((-Encoder_R) >Target_speed)		{R-=((-Encoder_R)-Target_speed);}
//	PWM_Set_L_F(L);
//	PWM_Set_R_R(R);
//	
//}

void Speed_Back(uint16_t Target_speed,int16_t Encoder_L,int16_t Encoder_R)
{
	static uint8_t L=111,R=110;
	PWM_Set_F_F(255);
	PWM_Set_F_R(255);     //前电机刹车；
	PWM_Set_L_F(0);
	PWM_Set_R_R(0);
	
	if(Encoder_R==Target_speed)			{R+=0;}
	if(Encoder_R<Target_speed)			{R+=1;}
	if(Encoder_R>Target_speed)			{R-=1;}
	
	if((-Encoder_L)==Target_speed)		{L+=0;}
	if((-Encoder_L) <Target_speed)		{L+=1;}
	if((-Encoder_L) >Target_speed)		{L-=1;}
	PWM_Set_L_R(L);
	PWM_Set_R_F(R);	
	
}
//void Speed_Back(uint16_t Target_speed,int16_t Encoder_L,int16_t Encoder_R)
//{
//	static uint8_t L=111,R=110;
//	PWM_Set_F_F(255);
//	PWM_Set_F_R(255);     //前电机刹车；
//	PWM_Set_L_F(0);
//	PWM_Set_R_R(0);
//	
//	if(Encoder_R==Target_speed)			{R+=0;}
//	if(Encoder_R<Target_speed)			{R+=(Target_speed-Encoder_R);}
//	if(Encoder_R>Target_speed)			{R-=(Encoder_R-Target_speed);}
//	
//	if((-Encoder_L)==Target_speed)		{L+=0;}
//	if((-Encoder_L) <Target_speed)		{L+=(Target_speed-(-Encoder_L));}
//	if((-Encoder_L) >Target_speed)		{L-=((-Encoder_L)-Target_speed);}
//	PWM_Set_L_R(L);
//	PWM_Set_R_F(R);	
//	
//}
uint8_t Speed_Right(uint16_t Target_speed,int16_t Encoder_L,int16_t Encoder_R,int16_t Encoder_F)
{ 
	static uint8_t F=111,L=111,R=110;
	PWM_Set_F_R(0);
	PWM_Set_L_R(0);
	PWM_Set_R_R(0);
	
	
	
	if(Encoder_F==(35*Target_speed/19))			{F+=0;}
	if(Encoder_F <(35*Target_speed/19))			{F+=1;}
	if(Encoder_F >(35*Target_speed/19))			{F-=1;}
	
	if(Encoder_L==Target_speed)			{L+=0;}
	if(Encoder_L <Target_speed)			{L+=1;}
	if(Encoder_L >Target_speed)			{L-=1;}

	if(Encoder_R==Target_speed)			{R+=0;}
	if(Encoder_R <Target_speed)			{R+=1;}
	if(Encoder_R >Target_speed)			{R-=1;}

	
	
	
	
	PWM_Set_F_F(F);
	PWM_Set_L_F(L);
	PWM_Set_R_F(R);
	return R;
	
}
	
//void Speed_Right(uint16_t Target_speed,int16_t Encoder_L,int16_t Encoder_R,int16_t Encoder_F)
//{ 
//	static uint8_t F=111,L=111,R=110;
//	PWM_Set_F_R(0);
//	PWM_Set_L_R(0);
//	PWM_Set_R_R(0);
//	
//	
//	
//	if(Encoder_F==(35*Target_speed/19))			{F+=0;}
//	if(Encoder_F <(35*Target_speed/19))			{F+=((35*Target_speed/19)-Encoder_F);}
//	if(Encoder_F >(35*Target_speed/19))			{F-=(Encoder_F-(35*Target_speed/19));}
//	
//	if(Encoder_L==Target_speed)			{L+=0;}
//	if(Encoder_L <Target_speed)			{L+=(Target_speed-Encoder_L);}
//	if(Encoder_L >Target_speed)			{L-=(Encoder_L-Target_speed);}

//	if(Encoder_R==Target_speed)			{R+=0;}
//	if(Encoder_R <Target_speed)			{R+=(Target_speed-Encoder_R);}
//	if(Encoder_R >Target_speed)			{R-=(Encoder_R-Target_speed);}

//	
//	
//	
//	
//	PWM_Set_F_F(F);
//	PWM_Set_L_F(L);
//	PWM_Set_R_F(R);
//	
//	
//}
//	
void Speed_Left(uint16_t Target_speed,int16_t Encoder_L,int16_t Encoder_R,int16_t Encoder_F)
{
	static uint8_t F=111,L=111,R=110;
	
	PWM_Set_F_F(0);
	PWM_Set_L_F(0);
	PWM_Set_R_F(0);
	
	if((-Encoder_F)==(35*Target_speed/19))		{F+=0;}
	if((-Encoder_F) <(35*Target_speed/19))		{F+=1;}
	if((-Encoder_F) >(35*Target_speed/19))		{F-=1;}
	
	if((-Encoder_L)==Target_speed)		{L+=0;}
	if((-Encoder_L) <Target_speed)		{L+=1;}
	if((-Encoder_L) >Target_speed)		{L-=1;}
	
	if((-Encoder_R)==Target_speed)		{R+=0;}
	if((-Encoder_R) <Target_speed)		{R+=1;}
	if((-Encoder_R) >Target_speed)		{R-=1;}
	
	PWM_Set_F_R(F);
	PWM_Set_L_R(L);
	PWM_Set_R_R(R);
}

//void Speed_Left(uint16_t Target_speed,int16_t Encoder_L,int16_t Encoder_R,int16_t Encoder_F)
//{
//	static uint8_t F=111,L=111,R=110;
//	
//	PWM_Set_F_F(0);
//	PWM_Set_L_F(0);
//	PWM_Set_R_F(0);
//	
//	if((-Encoder_F)==(35*Target_speed/19))		{F+=0;}
//	if((-Encoder_F) <(35*Target_speed/19))		{F+=((35*Target_speed/19)-(-Encoder_F));}
//	if((-Encoder_F) >(35*Target_speed/19))		{F-=((-Encoder_F)-(35*Target_speed/19));}
//	
//	if((-Encoder_L)==Target_speed)		{L+=0;}
//	if((-Encoder_L) <Target_speed)		{L+=(Target_speed-(-Encoder_L));}
//	if((-Encoder_L) >Target_speed)		{L-=((-Encoder_L)-Target_speed);}
//	
//	if((-Encoder_R)==Target_speed)		{R+=0;}
//	if((-Encoder_R) <Target_speed)		{R+=(Target_speed-(-Encoder_R));}
//	if((-Encoder_R) >Target_speed)		{R-=((-Encoder_R)-Target_speed);}
//	
//	PWM_Set_F_R(F);
//	PWM_Set_L_R(L);
//	PWM_Set_R_R(R);
//}
	
void Stop(void){
	
	PWM_Set_F_F(255);//前面电机的轮子刹车；
	PWM_Set_F_R(255);
	            
	PWM_Set_L_F(255);//左边电机的轮子向前的速度；
	PWM_Set_L_R(255);
	            
	PWM_Set_R_F(255);//右边电机的轮子向前的数度；
	PWM_Set_R_R(255);
	
}
