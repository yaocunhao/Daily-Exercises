#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
#include <ctype.h>
//从键盘输入一个字符串，将小写字母全部转换成大写字母，
//然后输出到一个磁盘文件"test"中保存。 输入的字符串以！结束。


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