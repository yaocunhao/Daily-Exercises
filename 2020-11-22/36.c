#include <stdio.h>
#include <windows.h>
//求100之内的素数。
void Prime()
{
	for (int i = 2; i < 101; i++)
	{
		int j = 0;
		for (j = 2; j < i; j++)
		{
			if (i%j == 0)
				break;
		}
		if (i == j)
			printf("%d is prime\n",i);
	}
}

int main()
{
	Prime();
	system("pause");
	return 0;
}