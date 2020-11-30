#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
#include <string.h>
//请实现一个函数，将一个字符串中的每个空格替换成“%20”
//例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

int main()
{	
	char str[20]="we are happy";
	printf("请输入一个字符串\n");
	gets(str);
	char *dst;
	dst= strstr(str, " ");
	strncpy(dst, "%20", 3);
	while (dst)
	{
		if (dst = strstr(dst, " "))
		{
			strncpy(dst, "%20", 3);
		}
	}
	puts(str);

	







	
	system("pause");
	return 0;
}