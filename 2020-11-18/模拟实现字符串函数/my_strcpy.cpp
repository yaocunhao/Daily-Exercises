#include <stdio.h>
#include <windows.h>
#include <assert.h>
char* My_Strcpy(char dst[], const char str[])
{
	assert(dst&&str);
	char *s = dst;
	while(*s=*str)
	{
		s++;
		str++;
	}
	return dst;
}

int main()
{
	char str[] = "abcdefgh";
	char dst[20];
	My_Strcpy(dst,str);
	printf("%s\n", dst);
	system("pause");
	return 0;
}