#include<avr/io.h>
#include<util/delay.h>

int main(){
  DDRC=0XFF;
  DDRD=0XFF;
  while(1){
    boundSquare();


  }
}

void rotate(){
  for(int i=1;i<=128;i*=2){
	PORTC=i;
		for(int j=128;j>=1;j/=2){
			PORTD=255-j;
			_delay_ms(500);
		}
	}
	  }

void boundSquare(){
  PORTC=0B10000001;
  PORTD=0B00000000;
  // PORTC=0B10000001;
  // PORTD=0B01111110;
}

void chars(int i){
if(i==1){
  PORTC=0b00100000;
  PORTD=0b
}
}
