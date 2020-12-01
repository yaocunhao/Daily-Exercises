#include <stdio.h>
#include <windows.h>
//在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,
//并返回它的位置, 如果没有则返回 -1（需要区分大小写）.（从0开始计数）

int String(char str[])
{
	int size = strlen(str);
	int ch = 0;
	char *dst = str;
	while (*dst)
	{
		int count = 0;
		ch = *dst;
		for (int i = 0; i < size; i++)
		{
			if (ch == str[i])
			{
				count++;
			}
		}
		if (count == 1)
		{
			for (int j = 0; j < size; j++)
			{
				
				if (ch == str[j])
				{
					return j;
				}
			}
		}
		dst++;
	}
	return -1;
}

int main()
{
	char str[] = "abacdef";
	int ret=String(str);
	if (ret!=-1)
	printf("%c", str[ret]);
	system("pause");
	return 0;
}