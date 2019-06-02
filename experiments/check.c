#include<stdio.h>

void myMethod(){
  char cmd=0X65;
  char upperNibble=cmd&0xf0;
  char lowerNibble=cmd&0x0f;
  lowerNibble=lowerNibble<<4;
  char controlPins=1;//RS=0,RW=0 and E=1

//4 bit transmission
  char ja=upperNibble|controlPins;
  char v=lowerNibble|controlPins;
  printf("Upper Nibble:%x\n",upperNibble);
  printf("Lower Nibble:%x\n",lowerNibble);
  printf("first Trans:%x\n",ja);
  printf("Second Trans:%x\n",v);
}
void main(){
    char cmd=0X65;
  char upperNibble=cmd & 0xf0;//masking the lower 4 bits
  char ja=upperNibble+0x04;//Adding lower 4 bits 0100 for PB3-PB2-PB1-PB0 -->X-EN-RW-RS

  char lowerNibble=(cmd<<4)&0xf0;
  char v=lowerNibble+0x04;

  printf("Upper Nibble:%x\n",upperNibble);
  printf("Lower Nibble:%x\n",lowerNibble);
  printf("first Trans:%x\n",ja);
  printf("Second Trans:%x\n",v);
}
