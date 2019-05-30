#include<avr/io.h>
#include<util/delay.h>
#include<avr/io.h>
#include<util/delay.h>

//initializes the connected to lcd
void lcd_init(){
  lcd_cmd(0x02);
  lcd_cmd(0x28);
  lcd_cmd(0x0c);
  lcd_cmd(0x06);
  lcd_cmd(0x02);
}

//sends data to lcd using port B
void lcd_cmd(int cmd){
  PORTB=cmd & 0xf0;//masking the lower 4 bits
  PORTB=PORTB+0x04;//Adding lower 4 bits 0100 for PB3-PB2-PB1-PB0 -->x-EN-RW-RS
  _delay_ms(2);
  PORTB=PORTB-0x04;
  PORTB=(cmd<<4)&0xf0;
  PORTB=PORTB+0x04;
  _delay_ms(2);
  PORTB=PORTB-0x04;
}

//sends data to lcd in 4 bit entry mode
void lcd_data(int data){
  PORTB=data & 0xf0;
  PORTB=PORTB+0x05;
  _delay_ms(2);
  PORTB=PORTB-0x04;
  PORTB=(data<<4)&0xf0;
  PORTB=PORTB+0x05;
  _delay_ms(2);
  PORTB=PORTB-0x04;
}

void lcd_num(int num){
  int a=0;
  if (num==0){
    lcd_data(48);
  }
  lcd_cmd(0x04);
  while(num!=0){
    a=num%10;
    lcd_data(a+48);
    num=num/10;
  }
  lcd_cmd(0x06);
}

void lcd_string(char *str){
  int i=0;
  while(str[i]!='\0'){
    lcd_data(str[i]);
    i++;
  }
}

void debounce(int x){
  while(PIND==x){}
}
//get key pressed
int get_key(){
  //CONFIGURATION :
  //CASE 1 : 11101111 --->keep upper 4 bits constant , and check whether lower
  //                      four bits are whether : 1110,1101,1011 or 0111
  //LIKEWISE take 3 more cases with upper four bits 1101,1011,0111. The 4
  //conditions for all of them will be likewise as first.

  //case 1:checking elements of first columns {7,4,1,ON/AC}
  while(1)
  {
    PORTD=0XEF;
    switch (PIND) {
      case 0XEE:{debounce(0XEE);return 7;}
      case 0XED:{debounce(0XED);return 4;}
      case 0XEB:{debounce(0XEB);return 1;}
      case 0XE7:{debounce(0XE7);return 10;}//for ON/AC
    }

    //case 2:checking elements of first columns {8,5,2,0}
    PORTD=0XDF;
    switch (PIND) {
      case 0XDE:{debounce(0XDE);return 8;}
      case 0XDD:{debounce(0XDD);return 5;}
      case 0XDB:{debounce(0XDB);return 2;}
      case 0XD7:{debounce(0XD7);return 0;}
    }

    //case 3:checking elements of first columns {9,6,3,=}
    PORTD=0XBF;
    switch (PIND) {
      case 0XBE:{debounce(0XBE);return 9;}
      case 0XBD:{debounce(0XBD);return 6;}
      case 0XBB:{debounce(0XBB);return 3;}
      case 0XB7:{debounce(0XB7);return 11;}//for =
    }

    //case 4:checking elements of first columns {/,*,-,+}
    PORTD=0X7F;
    switch (PIND) {
      case 0X7E:{debounce(0X7E);return 12;}
      case 0X7D:{debounce(0X7D);return 13;}
      case 0X7B:{debounce(0X7B);return 14;}
      case 0X77:{debounce(0X77);return 15;}
    }
  }
}

int main(){
  int a=0,k=0,p=5892;
  DDRB=0xFF;
  DDRD=0xF0;
  lcd_init();
  lcd_cmd(0X86);

  while(1){
    lcd_cmd(0x80);
    lcd_string("Enter Password");
    while(a!=11){
      a=get_key();
      if(a==11){
        break;
      }
      else{
        k=k*10+a;
        lcd_cmd(0x01);
        lcd_cmd(0x86);
        lcd_num(k);
      //  _delay_ms(400);
      }
    }
    if(k==p){
      lcd_cmd(0x01);
      lcd_string("CORRECT");
      while(1){}
    }
    else{
      lcd_cmd(0x01);
      lcd_string("INCORRECT");
      a=0;
    }
  }
}
