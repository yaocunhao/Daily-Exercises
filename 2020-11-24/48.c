#include <stdio.h>
#include <windows.h>
#pragma warning (disable:4996)//�ݹ鷨����������while(*p)
//дһ����������һ���ַ����ĳ��ȣ���main�����������ַ�����������䳤�ȡ�
my_strlen(char str[])
{
	if (*str == 0)
		return 0;
	return 1 + strlen(str + 1);
}
int main()
{
	char str[50];
	printf("��������ַ���\n");
	gets(str);
	printf("%d\n",my_strlen(str));
	system("pause");
	return 0;

}