#include <stdio.h>
#include <windows.h>
//将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 
//数值为0或者字符串不是一个合法的数值则返回0

int main()
{
	int ret = 0;
	char str[20];
	fgets(str, sizeof(str)-1, stdin);
	for (int i = 0; i < (signed)strlen(str)-1; i++)
	{
		ret += str[i];
	}
	printf("%d\n",ret);
	system("pause");
	return 0;
}