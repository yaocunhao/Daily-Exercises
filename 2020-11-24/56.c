#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
#include <math.h>
//八进制转换为十进制。

Conversion(int n)
{
	int sum = 0;
	int count = 0;
	while (n)
	{
		sum+=(n % 10)*pow(8,count);
		n /= 10;
		count++;
	}
	printf("%d\n", sum);
}
int main()
{
	int n = 0;
	printf("请输入数字\n");
	scanf("%d", &n);
	Conversion(n);
	system("pause");
	return 0;
}