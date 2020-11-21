#include <stdio.h>
#include <windows.h>
const char *my_strstr(const char *str, const char *dst)
{
	while (*str)
	{
		const char *p = str;
		const char *q = dst;
		while (*p&&*q && (*p == *q))
		{
			*p++;
			*q++;
		}
		if (*q == '\0')
		{
			return str;
		}
		str++;
	}
	return NULL;
}

int main()
{
	char str[] = "abc a1123 acdef";
	char dst[] = "a1123";
	fputs(my_strstr(str,dst),stdout);
	system("pause");
	return 0;
}