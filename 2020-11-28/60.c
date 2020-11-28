#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//两个字符串连接程序 。

void Joint(char *str, char *dst)
{
	strcat(str, dst);
}

int main()
{
	char str[20];
	char dst[20];
	printf("请输入两个字符串\n");
	scanf("%s%s", str, dst);
	Joint(str, dst);
	printf("%s\n", str);

	system("pause");
	return 0;
}