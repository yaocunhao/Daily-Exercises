#include<stdio.h>
#include <windows.h>
#pragma warning (disable:4996)
//һ��Ǯһƿ���֣�2��ƿ�ӻ�һƿ���֣���20��Ǯ�ܺȶ��ٿ���

int main()
{
	int money = 0;
	printf("���������ж���Ǯ\n");
	scanf("%d", &money);
	money = money * 2 - 1;
	printf("����Ժ�%dƿ����\n", money);
	system("pause");
	return 0;
}