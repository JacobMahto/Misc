//lcd 16x2
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


  //command mode transmission
  void lcd_cmd(char cmd){
    char upperNibble=cmd & 0xf0;
    char lowerNibble=cmd & 0x0f;
    lowerNibble=lowerNibble<<4;
    char controlPins=0X04;//RS=0,RW=0 and E=1

    //4 bit transmission
    PORTB=upperNibble+controlPins;
    _delay_ms(2);
    PORTB=upperNibble;
    PORTB=lowerNibble+controlPins;
    _delay_ms(2);
    PORTB=lowerNibble;
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

int main(){
  DDRB=0xff;
  lcd_init();
  _delay_ms(10);
  while(1){
    lcd_cmd(0x86);
	lcd_data('2');
	lcd_data('5');
	lcd_data(0xdf);
	lcd_data('C');
  }
}
