#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//��ȡ7������1��50��������ֵ��ÿ��ȡһ��ֵ�������ӡ����ֵ�����ģ���
void Prin(int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("*");
	}
}

int main()
{
	int n = 0;
for (int i = 0; i < 7; i++)
	{
		printf("����������\n");
		scanf("%d", &n);
		Prin(n);
	}
	system("pause");
	return 0;
}