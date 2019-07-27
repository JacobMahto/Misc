#include<avr/io.h>
#include<util/delay.h>

int main(){
//DDRC=0b11111111;
DDRC=0XFF;
DDRD=0XFF;
	int a[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	while(1){
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
			for(int s=0;s<10;s++){
			PORTD=0X02;//LSB on
        PORTC=a[j];
        _delay_ms(50);
        PORTD=0X01;
        PORTC=a[i];
        _delay_ms(50);
			}

      }
			}
	}
}
