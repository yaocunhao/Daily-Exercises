#include <stdio.h>
#include <windows.h>
#include <assert.h>
char* My_Strcat(char str[], char dst[])
{
	assert(str&&dst);
	while (*str)
	{
		str++;
	}
	while (*str = *dst)
	{
		str++;
		dst++;;
	}
	return str;
}

int main()
{
	char str[50] = "hello,";
	char dst[] = "word!";
	My_Strcat(str,dst);
	printf("%s\n", str);
	system("pause");
	return 0;
}