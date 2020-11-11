#include<stdio.h>
#include <windows.h>
#pragma warning (disable:4996)
//一块钱一瓶可乐，2空瓶子换一瓶可乐，求20块钱能喝多少可乐

int main()
{
	int money = 0;
	printf("请输入你有多少钱\n");
	scanf("%d", &money);
	money = money * 2 - 1;
	printf("你可以喝%d瓶可乐\n", money);
	system("pause");
	return 0;
}