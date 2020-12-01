#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//把只包含质因子2、3和5的数称作丑数（Ugly Number）。
//例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数

int UglyNum(int n)
{/*
	int count = 1;
	int i = 2;
	if (n == 1)
	{
		return 1;
	}
	while (i)
	{
		if (i % 7 != 0)
		{
			count++;
		}
		if (count == n)
		{
			return i;
		}
		i++;
		
	}
	return 0;*/
	int count = 1;
	int i = 2;
	if (n == 1)
		return 1;
	while (i)
	{
		if (i % 7 != 0)
		{
			count++;
		}
		if (count == n)
		{
			return i;
		}
		i++;
	}
	return 0;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d\n",UglyNum(n));
	system("pause");
	return 0;
}