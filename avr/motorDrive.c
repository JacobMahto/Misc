#include<avr/io.h>
#include<util/delay.h>

//Motor directions
//  M2  M1  DIR
//  00  00  halt
//  01  01  forward
//  01  00  right
//  00  01  left
//  10  10  backward
//  10  00  back-right
//  00  10  back-left
//  10  01  sharp-right-forward
//  01  10  sharp-left-forward
int main(){
  DDRC=0XFF;
  while(1){
    //forward
    PORTC=0X05;
    _delay_ms(2000);

    //backward
    PORTC=0XC;
    _delay_ms(2000);

    //right
    PORTC=0X04;
    _delay_ms(2000);

    //left
    PORTC=0X01;
    _delay_ms(2000);

    //backward
    PORTC=0XC;
    _delay_ms(2000);

    //back-right
    PORTC=0X08;
    _delay_ms(2000);

    //back-left
    PORTC=0X02;
    _delay_ms(2000);

    //sharp-right-forward
    PORTC=0X09;
    _delay_ms(2000);

    //sharp-left-forward
    PORTC=0X06;
    _delay_ms(2000);
}}


//function to demonstrate movement of two motors in different directions one by one ,and altogether.
void basicMovement(){
  DDRC=0XFF;
  //Motor 1 Dir1
  PORTC=0X01;
  _delay_ms(1000);

  //Motor 1 Dir2
  PORTC=0X02;
  _delay_ms(1000);

  //Motor 2 Dir1
  PORTC=0X04;
  _delay_ms(1000);

  //Motor 2 Dir2
  PORTC=0X08;
  _delay_ms(1000);

  //Motor1-2 Parallel
  PORTC=0X5;
  _delay_ms(1000);

  //Motor1-2 Antiparallel
  PORTC=0X06;
  _delay_ms(1000);

}
