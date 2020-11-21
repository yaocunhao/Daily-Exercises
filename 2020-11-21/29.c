#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//给一个不多于5位的正整数，要求：一，求它是几位数，二，逆序打印出各位数字。
void Num(int n)
{
	int count = 0;
	while (n)
	{
		count++;
		n/=10;
	}
	printf("%d\n", count);
}
int  Prin(int n)
{
	printf("%d\n", n % 10);
	if (n > 10)
	{
		Prin(n / 10);
	}
}
int main()
{
	int n = 0;
	printf("please enter a number\n");
	scanf("%d", &n);
	Num(n);
	Prin(n);
	system("pause");
	return 0;
}