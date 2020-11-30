#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//求出任意非负整数区间中1出现的次数
int NUM(int n)
{
	int count = 0;
	for (int i = 0; i <= n; i++)
	{
		int j = i;
		while (j)
		{
			if (j%10==1)
			{
				count++;
			}
			j /=10;
		}
	}
	return count;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d\n",NUM(n));
	system("pause");
	return 0;
}