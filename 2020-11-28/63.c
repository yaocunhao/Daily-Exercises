#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//计算字符串中子串出现的次数 。

int Sonstring(char str[], char dst[])
{
	int count=0;
	int len = strlen(dst);
	while (strstr(str, dst))
	{
		count++;
		str += len;
	}
	return count;
}

int main()
{
	char str[20];
	char dst[20];
	printf("请输入子串和母串\n");
	scanf("%s%s", str, dst);
	int ret=Sonstring(str, dst);
	printf("出现了%d次\n",ret);
	system("pause");
	return 0;
}