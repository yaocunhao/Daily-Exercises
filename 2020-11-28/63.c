#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//�����ַ������Ӵ����ֵĴ��� ��

int Sonstring(char str[], char dst[])
{
	int count=0;
	int len = strlen(dst);
	while (strstr(str, dst))
	{
		count++;
		str += len;
	}
	return count;
}

int main()
{
	char str[20];
	char dst[20];
	printf("�������Ӵ���ĸ��\n");
	scanf("%s%s", str, dst);
	int ret=Sonstring(str, dst);
	printf("������%d��\n",ret);
	system("pause");
	return 0;
}