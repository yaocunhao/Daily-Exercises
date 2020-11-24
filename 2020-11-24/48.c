#include <stdio.h>
#include <windows.h>
#pragma warning (disable:4996)//递归法，计数法，while(*p)
//写一个函数，求一个字符串的长度，在main函数中输入字符串，并输出其长度。
my_strlen(char str[])
{
	if (*str == 0)
		return 0;
	return 1 + strlen(str + 1);
}
int main()
{
	char str[50];
	printf("输入你的字符串\n");
	gets(str);
	printf("%d\n",my_strlen(str));
	system("pause");
	return 0;

}