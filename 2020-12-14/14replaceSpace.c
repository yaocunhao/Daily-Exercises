#include <stdio.h>
#include <windows.h>
char* replaceSpace(char* s){
	//����һ���������ȵ��ַ����飬Ȼ������ж������ո�ͽ����滻
	int len = 3 * strlen(s) + 1;//������ȫ�ǿո�
	char *str = (char *)malloc(sizeof(char)*len);
	char *str2 = str;
	while (*s)
	{
		if (*s == ' ')//���Ϊ�ո�
		{
			*(str++) = '%';
			*(str++) = '2';
			*str = '0';
		}
		else
			*str = *s;
		str++;
		s++;
	}
	*str = '\0';
	return str2;
}
int main()
{
	char *s = "we are happy";
	char *c=replaceSpace(s);
	printf("%s\n", c);
	system("pause");
	return 0;
}