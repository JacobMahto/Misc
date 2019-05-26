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

//sends data to lcd using port B
void lcd_cmd(int cmd){
  PORTB=cmd & 0xf0;//masking the lower 4 bits
  PORTB=PORTB+0x04;//Adding lower 4 bits 0100 for PB3-PB2-PB1-PB0 -->X-EN-RW-RS
  _delay_ms(2);
  PORTB=PORTB-0X04;
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
