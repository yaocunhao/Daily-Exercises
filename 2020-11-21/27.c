#include <stdio.h>
#include <windows.h>
#pragma warning(disable :4996)
//，利用递归函数调用方式，将所输入的5个字符，以相反顺序打印出来。
int ReversePrin(char str[])
{
	if (*str== 0)
	{
		return 0;
	}
    ReversePrin(str + 1);
	printf("%c\n", *str);
	return 0;
	
}

int main()
{
	char str[6];
	printf("请输入字符\n");
	scanf("%s", str);
	ReversePrin(str);
	system("pause");
	return 0;
}