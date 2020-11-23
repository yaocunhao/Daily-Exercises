#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//输入3个数a,b,c，按大小顺序输出。

Prin(int a,int b,int c)
{
	int t = 0;
	if (a > b)
	{
		t = a;
		a = b;
		b = t;
	}
	if (a > c)
	{
		t = a;
		a = c;
		c = t;
	}
	if (b > c)
	{
		t = b;
		b = c;
		c = t;
	}
	printf("%d<%d<%d", a, b, c);
}

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	printf("请输入3个数\n");
	scanf("%d %d %d", &a, &b, &c);
	Prin(a, b, c);
	system("pause");
	return 0;
}