#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//����3����a,b,c������С˳�������

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
	printf("������3����\n");
	scanf("%d %d %d", &a, &b, &c);
	Prin(a, b, c);
	system("pause");
	return 0;
}