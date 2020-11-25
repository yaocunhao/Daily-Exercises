#include <stdio.h>
#include <windows.h>
// atoi函数，读取字符串，从第一个不为空格的字符开始计算,遇到第一个+或者-跳过，
//遇到第一个非整停止；

int my_atoi(const char *str)
{
	int count = 0;
	int flag = 1;
	while (*str == ' ')//跳过空格
	{
		str++;
	}
	if (*str == '+')//跳过第一个符号位
	{
		str++;

		if (*str == '-')//防止下一个为‘-’；
		{
			return 0;
		}
	}
	if (*str == '-')
	{
		flag = -1;//标记为负数
		str++;
	}
	while (*str <= '9'&&*str >= '0'&&*str!='\0')//遇到整数且没有越界
	{
		count = (count * 10 + (*str-48));
		str++;
	}
	count *= flag;//确定符号
	return count;
}

int main()
{
	char str[] = "     +432sds44";
	printf("%d\n", my_atoi(str));
	system("pause");
	return 0;
}
