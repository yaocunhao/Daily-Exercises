#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//一个偶数总能表示为两个素数之和。
int Isprime(int n)
{
	int i = 2;
	for (i = 2; i < n; i++)
	{
		if (n % i == 0)
			break;
	}
	if (i == n)
		return 1;
	else
		return 0;
}

int  PrimeNum(int num)
{
	int i = 0;
	int num2 =0;
	while (1)
	{
		num2 = num - i;
		if (Isprime(num2) && Isprime(i))
			return num2;
		else
			i++;
	}
}
int main()
{
	int num = 0;
	printf("请输入一个偶数\n");
	scanf("%d", &num);
	int result=PrimeNum(num);
	printf("%d=%d+%d", num, result, num - result);
	system("pause");
	return 0;
}