#include <stdio.h>
#include <windows.h>

int strToInt(char* str){
	int num = 0;
	int count = 1;
	int flag = 1;
	while (*str == ' ')
	{
		str++;//筛除空白
	}


	if (*str != '+' && *str != '-' && *str - '0'>9)//第一个字符不是有效字符,注意字符串中的数字为字符
		return 0;

	if (*str == '-')
	{
		flag = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}

	while (*str != '\0'&&*str - '0'<10 && *str - '0'>0)//保证为有效字符
	{
		num = num*count + (*str - '0');
		str++;
		if (count == 1)
			count *= 10;
	}
	num *= flag;
	return num;

}

int main()
{
	char *s = " -91283472332";
	int result = strToInt(s);
	printf("%d\n", result);

	system("pause");
	return 0;
}