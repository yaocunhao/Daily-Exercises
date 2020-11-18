#include <stdio.h>
#include <windows.h>

int My_Strlen(char* str)
{
	char *p = str;
	while (*p != '\0')
	{
		p++;
	}
	return p - str;
}


int main()
{
		char str[] = "hello,word!!";
		int result = My_Strlen(str);
		printf("%d\n", result);
		system("pause");
}