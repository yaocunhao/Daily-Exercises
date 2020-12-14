#include <stdio.h>
#include <windows.h>
char* replaceSpace(char* s){
	//创建一个三倍长度的字符数组，然后进行判断遇到空格就进行替换
	int len = 3 * strlen(s) + 1;//最差情况全是空格
	char *str = (char *)malloc(sizeof(char)*len);
	char *str2 = str;
	while (*s)
	{
		if (*s == ' ')//如果为空格
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