#include "global.h"
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void LED_ShowD1(char var){
//показать единицы
 //выставить в 1 все биты кроме указанных
 PORTD |= 0b01111111;
 switch (var){
  //0
  case 0:
   PORTD &= 0x40;
  break;
  //1
  case 1:
   PORTD &= 0x79;
  break;
  //2
  case 2:
   PORTD &= 0x24;
  break;
  //3
  case 3:
   PORTD &= 0x30;
  break;
  //4
  case 4:
   PORTD &= 0x19;
  break;
  //5
  case 5:
   PORTD &= 0x12;
  break;
  //6
  case 6:
   PORTD &= 0x02;
  break;
  //7
  case 7:
   PORTD &= 0x78;
  break;
  //8
  case 8:
   PORTD &= 0x00;
  break;
  //9
  case 9:
   PORTD &= 0x10;
  break;
  //off
  case 10:
   PORTD |= 0b01111111;
  break;
 }
}
//------------------------------------------------------------------------------
void LED_ShowD2(char var){
//показать десятки
 //выставить в 1 все биты кроме указанных
 PORTC |= 0b00011111;
 PORTB |= 0b11000000;
 switch(var){
  case 0:
   PORTC &= 0b11100000;
   PORTB &= 0b10111111;
  break;
  case 1:
   PORTC &= 0b11111001;
   PORTB &= 0b11111111;
  break;
  case 2:
   PORTC &= 0b11100100;
   PORTB &= 0b01111111;
  break;
  case 3:
   PORTC &= 0b11110000;
   PORTB &= 0b01111111;
  break;
  case 4:
   PORTC &= 0b11111001;
   PORTB &= 0b00111111;
  break;
  case 5:
   PORTC &= 0b11110010;
   PORTB &= 0b00111111;
  break;
  case 6:
   PORTC &= 0b11100010;
   PORTB &= 0b00111111;
  break;
  case 7:
   PORTC &= 0b11111000;
   PORTB &= 0b11111111;
  break;
  case 8:
   PORTC &= 0b11100000;
   PORTB &= 0b00111111;
  break;
  case 9:
   PORTC &= 0b11110000;
   PORTB &= 0b00111111;
  break;
  case 10:
   PORTC |= 0b00011111;
   PORTB |= 0b11000000;
  break;
 }
}
//------------------------------------------------------------------------------
void LED_ShowValue(char var){
  LED_ShowD1((Dec2Bcd(var) & 0x0F));
  LED_ShowD2(((Dec2Bcd(var) & 0xF0)>>4));
}
//------------------------------------------------------------------------------