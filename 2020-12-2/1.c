#include <windows.h>
#include <stdio.h>
#pragma warning (disable :4996)
//����һ���ַ����������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�
int String(char str[])
{
	int count = 0;
	int tem = 0;
	while (*str)
	{
		char *dst = str;
		char ch = *dst;
		count = 1;
		dst++;
		while (*dst)
		{
			if (ch != *dst)
			{
				count++;
			}
			else
			{
				break;
			}
			dst++;
		}
		if (count > tem)
		{
			tem = count;
		}
		str++;
	}
	return tem;
}

int main()
{
	char str[50];
	scanf("%s", str);
	int ret = String(str);
	printf("%d\n", ret);
	system("pause");
	return 0;
}