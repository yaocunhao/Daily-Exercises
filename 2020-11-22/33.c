#include <stdio.h>
#include <windows.h>
//�ж�һ�������Ƿ�Ϊ������
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
			printf("%d������\n", i);
		}
	}
}


int main()
{
	PrimeNum();
	system("pause");
	return 0;
}