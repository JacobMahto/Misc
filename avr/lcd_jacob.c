//lcd 16x2
#include<avr/io.h>
#include<util/delay.h>

//CONNECTION
//COMMAND IS SENT IN THE ORDER : PB7------PB0
//PB7-PB6-PB5-PB4-PB3-PB2-PB1-PB0
//D7-D6-D5-D4-X-RS-RW-E
//RS--->0 FOR COMMAND &&&&& 1----> FOR DATA
//RW--->0 FOR WRITE. "READ" NOT USED.
//FOR COMMAND - LOWER 4 BIT(CONTROL):0X04
//FOR DATA - LOWER 4 BIT(CONTROL):0X05


//initializes the connected to lcd
void lcd_init(){
  _delay_ms(15);//"POWER ON" initialization time for LCD
  lcd_cmd(0X01);//clears screen
  lcd_cmd(0X02);//Return Home
  lcd_cmd(0X28);//4-bit , 2 line
  lcd_cmd(0X0C);//Display On , Cursor Off
  lcd_cmd(0X06);//Entry Mode set-Cursor From Left to Right
}

//command mode transmission
void lcd_cmd(char cmd){
  char upperNibble=cmd & 0xf0;
  char lowerNibble=cmd & 0x0f;
  lowerNibble=lowerNibble<<4;
  char controlPins=0X01;//RS=0,RW=0 and E=1

  //4 bit transmission
  PORTB=upperNibble+controlPins;
  _delay_ms(2);
  PORTB=upperNibble;//RS PIN RESET- COMMAND MODE
  PORTB=lowerNibble+controlPins;
  _delay_ms(2);
  PORTB=lowerNibble;//RS PIN RESET- COMMAND MODE
}

//sends data to lcd in 4 bit entry mode
void lcd_data_string(char a[]){
  for(char c=0;c<strlen(a);c++){
    char upperNibble=a[c] & 0xf0;
    char lowerNibble=a[c] & 0x0f;
    lowerNibble=lowerNibble<<4;
    char controlPins=0X05;//RS=1,RW=0 and E=1

    //4 bit transmission
    PORTB=upperNibble+controlPins;
    _delay_ms(2);
    PORTB=upperNibble+4;//RS PIN SET--DATA MODE
    PORTB=lowerNibble+controlPins;
    _delay_ms(2);
    PORTB=lowerNibble+4;//RS PIN SET--DATA MODE
  }
}

void lcd_data_char(char a){
  char upperNibble=a & 0xf0;
  char lowerNibble=a & 0x0f;
  lowerNibble=lowerNibble<<4;
  char controlPins=0X05;//RS=1,RW=0 and E=1

  //4 bit transmission
  PORTB=upperNibble+controlPins;
  _delay_ms(2);
  PORTB=upperNibble+4;//RS PIN SET--DATA MODE
  PORTB=lowerNibble+controlPins;
  _delay_ms(2);
  PORTB=lowerNibble+4;//RS PIN SET--DATA MODE
}

int main(){
  DDRB=0XFF;
  lcd_init();
  while(1){
    lcd_cmd(0x86);
    lcd_data_string("25");
    lcd_data_char(0XDF);
  }
}
