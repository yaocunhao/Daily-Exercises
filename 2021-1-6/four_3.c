//�ж�����������
#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
int main()
{
	int first = 0;
	int second = 0;
	int third = 0;
	printf("������������\n");
	scanf("%d %d %d", &first, &second, &third);
	if (first + second < third || first + third < second || second + third < first)
		printf("����������\n");
	else
	{
		if (first == second&&second == third)
			printf("�ȱ�������\n");
		else if (first == second || first == third || second == third)
			printf("����������");
		else
			printf("����һ����ͨ��������");
	}
	system("pause");
	return 0;
}