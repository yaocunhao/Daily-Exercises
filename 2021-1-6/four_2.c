//打印质数
#include <stdio.h>
#include <windows.h>
#include <math.h>

int main()
{
	for (int i = 2; i < 101; i++)
	{
		int j = 0;
		for (j = 2; j <=sqrt(i); j++)
		{
			if (i%j == 0)
				break;
		}
		if (j>sqrt(i))
		printf("%d是质数\n", i);
	}
	system("pause");
	return 0;
}