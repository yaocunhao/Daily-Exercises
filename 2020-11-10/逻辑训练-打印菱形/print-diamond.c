#include <stdio.h>
#include <windows.h>
#include <math.h>
void PrinDiamond()
{
	for (int i = 0; i < 7; i++)//控制换行
	{
		for (int j = 0; j < 50-i; j++)
		{
			printf(" ");//打印空格,每次少一个
		}
		for (int j = 0; j < 2 * i + 1; j++)//打印*,每次多两个
		{
			printf("*");
		}
		printf("\n");
	}
	for (int i = 6; i >0; i--)
	{
		for (int j = 0; j < 51-i; j++)
		{
			printf(" ");
		}
		for (int j = 1; j < 2 * i; j++)
		{
			printf("*");
		}
		printf("\n");
	}

}

int main()
{
	PrinDiamond();
    system("pause");
	return 0;
}
