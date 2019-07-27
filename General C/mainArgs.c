#include<stdio.h>

int main(int argc,char *argv[]){
  int j;
  printf("argc:%d\n",argc);
  for(j=0;j<argc;j++){
    printf("%s\n",argv[j]);
  }
  getchar();
  return 0;
}
