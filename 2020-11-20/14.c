#include <stdio.h>
#include <windows.h>
#pragma warning(disable :4996)
//��һ���������ֽ����������磺����90����ӡ��90 = 2 * 3 * 3 * 5��

void NumPrin(int num)
{
	int count = 0;
	printf("%d= ", num);
	while (num)
	{
		int i = 2;
		for ( i = 2; i < num; i++)
		{
			if (num%i == 0)
			{
				printf("%d*", i);
				num/= i;
				break;
			}
		
		}
		if (i == num)
		{
			printf("%d", num);
			break;
		}
		
	}
}

int main()
{
	int num = 0;
	printf("��������Ҫ�ֽ������\n");
	scanf("%d", &num);
	NumPrin(num);
	system("pause");
	return 0;
}