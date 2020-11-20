#include <stdio.h>
#include <windows.h>
//判断101到200之间的素数。
void PrimeNum()
{
	for (int i = 101; i < 201; i++)
	{
		int j = 2;
		for (j = 2; j < i; j++)
		{
			if (i%j == 0)
			{
				break;
			}
		}
		if (j == i)
		{
			printf("%d is prime number!\n", i);
		}
	}
}

int main()
{
	PrimeNum();
	system("pause");
	return 0;
}