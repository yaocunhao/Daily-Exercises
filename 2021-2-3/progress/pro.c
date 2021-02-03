#include "pro.h"

void proc()
{
  char arr[NUM]={0};
  const char *lable ="|/-\\";
  int i=0;
  while (i<100)
  {
    fflush(stdout);//强制刷新
    arr[i++]='#';//进度条个数
    usleep(50000);
    printf("[%-100s][%3d%%][%c]\r",arr,i,lable[i%4]);
  }
  printf("\n");
  
}
