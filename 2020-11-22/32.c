#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
#include <assert.h>
//ɾ��һ���ַ����е�ָ����ĸ���磺�ַ�����ACA����ɾ�����е�һ����ĸ��

char *DeleteCharacters(char *str,const char *dst)
{
	assert(str);
	if (dst == 0)
	{
		return str;
	}
	int src[300] = { 0 };
	int new = 0;
	for (int i = 0; i < (int)strlen(dst); i++)
	{
		src[dst[i]] = 1;//��Ӧ��ĸasciil�±��������ݱ�Ϊ1��
	}
	for (int i = 0; i < (int)strlen(str); i++)
	{
		if (src[str[i]]!= 1)//ascii����ͬ������
		{
			str[new++] = str[i];
		}
	}
	str[new] = '\0';//����new���ַ����±�Ϊnew��Ϊ\0��
	return str;
}

int main()
{
	char str[100];
	char dst[100];
	printf("������ԭ�ַ���\n");
	scanf("%s", &str);
	printf("��������Ҫɾ�����ַ�\n");
	scanf("%s", &dst);
	DeleteCharacters(str, dst);
	printf("%s\n", str);
	system("pause");
	return 0;
}