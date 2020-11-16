#include <stdio.h>
#include <windows.h>
#include <assert.h>
#pragma warning(disable:4996)
int Add(int x,int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x*y;
}
int Div(int x, int y)
{
	if (y == 0)
	{
		printf("error!\n");
	}
	else
	return x / y;
}
int main()
{
	int x = 0;
	int y = 0;
	int select = 1;
	int result = 0;
	int(*p[5])(int x, int y) = { 0, Add, Sub, Mul, Div };
	while (select)
	{
		printf("########################################\n");
		printf("##1.Add#######################2.Sub#####\n");
		printf("##3.Mul#######################4.Div#####\n");
		printf("########################################\n");
		printf("please your select\n");
		scanf("%d", &select);
		if ((select <= 4) && (select >= 1))
		{
			printf("Enter two number\n");
			scanf("%d %d", &x, &y);
			result = (*p[select])(x, y);
		}
		else
			printf("error!\n");
		printf("result=%d\n", result);
	}
	system("pause");
	return 0;
}