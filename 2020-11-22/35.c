#include <stdio.h>
#include <windows.h>
#pragma warning(disable :4996)
//�ַ�����ת���罫�ַ�����www.runoob.com����תΪ��moc.boonur.www����
void ReverseString(char *str)
{
	char *left = str;
	char *right = str + strlen(str) - 1;
	char temp;
	while (left < right)
	{
		temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}

int main()
{
	char str[100];
	printf("��������Ҫ��ת���ַ���\n");
	scanf("%s", str);
	ReverseString(str);
	printf("%s\n", str);
	system("pause");
	return 0;
}