#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//输入两个正整数m和n，求其最大公约数和最小公倍数。
int MaxDiv(int m, int n)
{
	int c = 0;
	while (c = m%n)
	{
		m = n;
		n = c;
	}
	return n;
}
int MaxMul(int m,int n)
{
	int num = 0;
	 num = MaxDiv(m,n);
	return m / num*n;
}

int main()
{
	int m = 0;
	int n = 0;
	printf("请输入两个数字m和n\n");
	scanf("%d %d", &m, &n);
	printf("最大公约数是%d\n",MaxDiv(m, n));
	printf("最小公倍数是%d\n", MaxMul(m, n));
	system("pause");
	return 0;
}