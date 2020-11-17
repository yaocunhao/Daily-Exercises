//：有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？

#include <stdio.h>
#include <windows.h>
void Ranking()
{
	int t = 0;
	int count = 0;
	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			for (int k = 1; k < 5; k++)
			{
				if (i != j&&j != k&&i!=k)
				{
					t = i * 100 + j * 10 + k;
					count++;
					printf("第%d个数字是%d\n", count, t);
				}
			}
		}
	}
}
int main()
{
	Ranking();
	system("pause");
	return 0;
}