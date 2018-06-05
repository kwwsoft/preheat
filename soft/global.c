#include "built_in.h"
#include "keyboard\keybrd.h"
#include "led\led.h"
#include "global.h"
//------------------------------------------------------------------------------
/*
  2,55 на 1%
   10% = 2,55*10 = 25
   35% = 2,55 * 30 = 90  down value
   60% = 2,55 * 60 = 153  up value
*/
unsigned char duty;
unsigned int adc_adc, adc_V, adc_Vprev;
//напряжение на 1 шаг ацп  с учетом делителя
const float ku = (5.00 / 256.0);
//------------------------------------------------------------------------------
void InitMega(){
 DDRB = 0b11100111;
 DDRD = 0b11111111;
 DDRC = 0b11011111;
 PORTB = 0b11111100;
 PORTC = 0b11111111;
 PORTD = 0xFF;
 //
 ResetTimers();
 Sound_Init(&PORTD, 7);
 //************init ADC
 //Vcc, left, ch5
 ADMUX = 0b01100101;
 //div64  8000000/64=125000
 ADCSRA = 0b00000110;
 //comparator off, free running mode
 ADCSRB = 0;
 DIDR0 = 0;
 //enable adc
 ADCSRA |= (1<<ADEN);
 Delay_10ms();
  //************init ADC end

}
//------------------------------------------------------------------------------
void ResetTimers(){
  TCCR0A = 0;
  TCCR0B = 0;
  OCR0A = 0;
  OCR0B = 0;
  TIFR0 = 0;
  TIMSK0 = 0;
  TCNT0 = 0;
  //
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1C = 0;
  TCNT1H = 0;
  TCNT1L = 0;
  OCR1AH = 0;
  OCR1AL = 0;
  OCR1BH = 0;
  OCR1BL = 0;
  ICR1H = 0;
  ICR1L = 0;
  TIMSK1 = 0;
  TIFR1 = 0;
  //
  TCCR2A = 0;
  TCCR2B = 0;
  OCR2A = 0;
  OCR2B = 0;
  TIFR2 = 0;
  TIMSK2 = 0;
  ASSR = 0;
  GTCCR = 0;
  TCNT2 = 0;
}
//------------------------------------------------------------------------------
int My_ADC_Get_Sample(){
 short count = 127;
 unsigned int summa = 0;
 //
 do{
  Delay_50us();
  ADCSRA |= (1 << ADSC);
   do{
   }while (ADCSRA & (1 << ADSC));
   summa += ADCH;
  }while(count-- > 0);
 //
 return summa / 128;
}
//------------------------------------------------------------------------------
void My_ShowU(){
 adc_adc = My_ADC_Get_Sample();
 adc_V = ((float)adc_adc * ku) * 5.53 * 10.0;
 //если не поменялось - индикатор не дергаем
 if (adc_V != adc_Vprev){
  adc_Vprev = adc_V;
  LED_ShowValue(adc_V);
 }
}
//------------------------------------------------------------------------------