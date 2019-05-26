#include<stdio.h>
#include<stdlib.h>
int main(){
  int data=85;
  int *p;
  p=&data;
  printf("p:%d\ndata%d\n*p:%d\np[0]%d\np[1]:%d\np2:%d",p,data,*p,p[0],p[1],p[2]);
  int *j;
  int arr[3]={5,6,7};
  j=arr;
  return 0;
}
