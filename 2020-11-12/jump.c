#include<stdio.h>
#include <windows.h>
#pragma warning (disable:4996)

//������̨�ף�����ÿ�ο�����1��̨�ף���������̨�ף�дһ��������������N��̨��
//�ж����ַ���
int Jump(int num)
{
	if (num < 3)
		return num;
	return Jump(num - 1) + Jump(num - 2);
}
int main()
{
	int num = 0;
	printf("������̨����\n");
	scanf("%d", &num);
	printf("��%d�ַ���\n",Jump(num));
	system("pause");
	return 0;
}