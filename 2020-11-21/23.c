#include <stdio.h>
#include <windows.h>
//打印出如下图案（菱形）。

          // *
          //***
         //*****
        //*******
       //  *****
         // ***
         //  *
void PrinDiamod()
{
	for (int i = 1; i < 5; i++)//控制上半部分行数
	{
		for (int k =10; k>i; k--)//空格
		{
			printf(" ");
		}
		for (int j = 0; j < i * 2 - 1; j++)//个数
		{
			printf("*");
		}
		printf("\n");
	}
	for (int i = 3; i>0; i--)//下半部分
	{
		for (int k = 10; k > i; k--)
		{
			printf(" ");
		}
		for (int j = 0; j < i*2-1; j++)
		{
			printf("*");
		}
		printf("\n");
	}

}
int main()
{
	PrinDiamod();
	system("pause");
	return 0;
}