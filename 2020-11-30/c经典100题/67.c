#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
#include <ctype.h>
//�Ӽ�������һ���ַ�������Сд��ĸȫ��ת���ɴ�д��ĸ��
//Ȼ�������һ�������ļ�"test"�б��档 ������ַ����ԣ�������


int main()
{
	FILE *fp = fopen("code.log", "w");
	char str[10];
	gets(str);
	for (int i = 0; i < (signed)strlen(str); i++)
	{
		if (isalpha(str[i]))
		{
			str[i]=toupper(str[i]);
		}
	}
	printf("%s", str);
	fputs(str, fp);
	fclose(fp);
	system("pause");
	return 0;
}