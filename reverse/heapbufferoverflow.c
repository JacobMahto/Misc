#include<string.h>
#include<stdio.h>

int main(int argc,char** argv){
  char* buff=malloc(20);
  strcpy(buff,argv[1]);
//  free(buff);
}
