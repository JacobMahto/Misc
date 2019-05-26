#include<avr/io.h>
#include<util/delay.h>

int main(){
  met2();
}

void met1(){
  //DDRC=0b11111111;
  DDRC=0XFF;
  DDRD=0XFF;
  	int a[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
  	while(1){
      for(int h2=0;h2<=2;h2++){
        int lim=9;
        if(h2==2){
          lim=3;
        }
        for(int h1=0;h1<=lim;h1++){
          for(int m2=0;m2<=5;m2++){
            for(int m1=0;m1<=9;m1++){
              for(int s2=0;s2<=5;s2++){
                for(int s1=0;s1<=9;s1++){
                  for(int hold=0;hold<=20;hold++){
                    PORTD=0X3e;
                    PORTC=a[s1];
                    _delay_ms(1);

                    PORTD=0X3d;
                    PORTC=a[s2];
                    _delay_ms(1);

                    PORTD=0X3b;
                    PORTC=a[m1];
                    _delay_ms(1);

                    PORTD=0X37;
                    PORTC=a[m2];
                    _delay_ms(1);

                    PORTD=0X2f;
                    PORTC=a[h1];
                    _delay_ms(1);

                    PORTD=0X1f;
                    PORTC=a[h2];
                    _delay_ms(1);
                  }

                }
              }
            }
          }


        }
      }
  	}
}

void met2(){
  //DDRC=0b11111111;
  DDRC=0XFF;
  DDRD=0XFF;
  int h1=0,h2=0;
  	int a[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
  	while(1){
      for(h2=0;h2<=2;h2++){
        if(h2==2 && h1==4){
          break;
        }
        for(h1=0;h1<=9;h1++){
          if(h2==2 && h1==4){
            break;
          }
          for(int m2=0;m2<=5;m2++){
            for(int m1=0;m1<=9;m1++){
              for(int s2=0;s2<=5;s2++){
                for(int s1=0;s1<=9;s1++){
                  for(int hold=0;hold<=20;hold++){
                    PORTD=0X3e;
                    PORTC=a[s1];
                    _delay_ms(1);

                    PORTD=0X3d;
                    PORTC=a[s2];
                    _delay_ms(1);

                    PORTD=0X3b;
                    PORTC=a[m1];
                    _delay_ms(1);

                    PORTD=0X37;
                    PORTC=a[m2];
                    _delay_ms(1);

                    PORTD=0X2f;
                    PORTC=a[h1];
                    _delay_ms(1);

                    PORTD=0X1f;
                    PORTC=a[h2];
                    _delay_ms(1);
                  }

                }
              }
            }
          }


        }
      }
  	}
}
