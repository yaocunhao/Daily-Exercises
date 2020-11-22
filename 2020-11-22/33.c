#include <stdio.h>
#include <windows.h>
//判断一个数字是否为质数。
void PrimeNum()
{
	for (int i = 2; i < 200; i++)
	{
		int j = 2;
		for (j = 2; j < i; j++)
		{
			if (i%j == 0)
			{
				break;
			}
		}
		if (i == j)
		{
			printf("%d是质数\n", i);
		}
	}
}


int main()
{
	PrimeNum();
	system("pause");
	return 0;
}