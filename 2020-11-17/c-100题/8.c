#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//���9*9�ھ���

Prin(int x, int y)
{
	for (int i = 1; i < x + 1; i++)
	{
		for (int j = 1; j < i+1; j++)
		{
			printf("%d*%d=%2d ", j, i, i*j);
		}
		printf("\n");
	}
}
int main()
{
	int row = 0;
	int line = 0;
	printf("������Ҫ��ӡ���к���\n");
	scanf("%d %d", &row, &line);
	Prin(row, line);
	system("pause");
	return 0;
}