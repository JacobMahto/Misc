//Simple Stack buffer overflow example
#include<string.h>
#include<stdio.h>

void functionFunction(char *param,int p2,float p3){
  char local[1024];
  strcpy(local,param);
}

int main(int argc,char** argv){
  //functionFunction(argv[1],42,3.14);
  char jc[]="Jacob";
  printf("jacob");
}
