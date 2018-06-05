//clk = 0.125 mks
//------------------------------------------------------------------------------
#include "built_in.h"
#include "global.h"
#include "keyboard\keybrd.h"
#include "led\led.h"
//------------------------------------------------------------------------------
extern unsigned char duty;
extern unsigned int adc_Vprev;
//------------------------------------------------------------------------------
void main() {
 char key;
 InitMega();
 Sound_Play(2000, 100);
 adc_Vprev = 0;
 //40%
 duty = 10;
 PWM16bit_Init(_PWM16_FAST_MODE_8BIT, _PWM16_PRESCALER_16bit_1, _PWM16_NON_INVERTED, duty, 1);
 //отключить OC1B
 TCCR1A.COM1B1 = 0;
 TCCR1A.COM1B0 = 1;
 //slow on
 do{
  //show Uout
  My_ShowU();
  PWM16bit_Change_Duty(duty, _TIMER1_CH_A );
  Delay_ms(40);
 }while((++duty) < duty_min);
 //slow on end
 while(1){
  //меряем в ожидании клаві
  do{
   My_ShowU();
   Delay_80us();
  }while( (key = GetPresedKey()) == key_nothing);
  //select
  if (key == key_select){
  }
  //up
  else if (key == key_up){
   if (duty <= duty_max)
    duty ++;
    PWM16bit_Change_Duty(duty, _TIMER1_CH_A );
  }
  //down
  else if (key == key_down){
   if (duty >= duty_min)
   duty --;
   PWM16bit_Change_Duty(duty, _TIMER1_CH_A );
  }//up long
  else if (key == key_up_long){
   duty = duty_max;
   PWM16bit_Change_Duty(duty, _TIMER1_CH_A );
  }//down long
  else if (key == key_down_long){
   duty = duty_min;
   PWM16bit_Change_Duty(duty, _TIMER1_CH_A );
  }
 }
}