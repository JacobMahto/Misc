//get the key pressed
int get_key(){
  //CONFIGURATION :
  //CASE 1 : 11101111 --->keep upper 4 bits constant , and check whether lower
  //                      four bits are whether : 1110,1101,1011 or 0111
  //LIKEWISE take 3 more cases with upper four bits 1101,1011,0111. The 4
  //conditions for all of them will be likewise as first.

  //case 1:checking elements of first columns {7,4,1,ON/AC}
  PORTD=0XEF;
  switch (PIND) {
    case 0XEE:return 7;
    case 0XED:return 4;
    case 0XEB:return 1;
    case 0XE7:return 10;//for ON/AC
  }

  //case 2:checking elements of second columns {8,5,2,0}
  PORTD=0XDF;
  switch (PIND) {
    case 0XDE:return 8;
    case 0XDD:return 5;
    case 0XDB:return 2;
    case 0XD7:return 0;
  }

  //case 3:checking elements of third columns {9,6,3,=}
  PORTD=0XBF;
  switch (PIND) {
    case 0XBE:return 6;
    case 0XBD:return 6;
    case 0XBB:return 3;
    case 0XB7:return 11;//for =
  }

  //case 4:checking elements of fifth columns {/,*,-,+}
  PORTD=0X7F;
  switch (PIND) {
    case 0X7E:return 12;
    case 0X7D:return 13;
    case 0X7B:return 14;
    case 0X77:return 15;
  }

  //no key pressed
  return 100;
}
