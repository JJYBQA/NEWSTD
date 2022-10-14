#ifndef  __Drive_h_
#define  __Drive_h_

uint8_t Speed_Forward(uint16_t Target_speed,int16_t Encoder_L,int16_t Encoder_R);
void Speed_Back(uint16_t Target_speed,int16_t Encoder_L,int16_t Encoder_R);
uint8_t Speed_Right(uint16_t Target_speed,int16_t Encoder_L,int16_t Encoder_R,int16_t Encoder_F);
void Speed_Left(uint16_t Target_speed,int16_t Encoder_L,int16_t Encoder_R,int16_t Encoder_F);
void Stop(void);

#endif
