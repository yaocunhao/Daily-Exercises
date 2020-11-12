#include<stdio.h>
#include <windows.h>
#pragma warning (disable:4996)

//青蛙跳台阶，青蛙每次可以跳1个台阶，或者两个台阶，写一个函数青蛙跳到N个台阶
//有多少种方法
int Jump(int num)
{
	if (num < 3)
		return num;
	return Jump(num - 1) + Jump(num - 2);
}
int main()
{
	int num = 0;
	printf("请输入台阶数\n");
	scanf("%d", &num);
	printf("有%d种方法\n",Jump(num));
	system("pause");
	return 0;
}