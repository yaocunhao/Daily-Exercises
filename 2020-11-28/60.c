#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//�����ַ������ӳ��� ��

void Joint(char *str, char *dst)
{
	strcat(str, dst);
}

int main()
{
	char str[20];
	char dst[20];
	printf("�����������ַ���\n");
	scanf("%s%s", str, dst);
	Joint(str, dst);
	printf("%s\n", str);

	system("pause");
	return 0;
}