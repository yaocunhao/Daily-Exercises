#include <stdio.h>
#include <windows.h>
int My_Strlen( const char str[])
{
	if (*str == '\0')
		return 0;
	else
		return 1 + My_Strlen(str+1);
}
int main()
{
	char str[] = "hello,word!!";
	int result = My_Strlen(str);
	printf("%d\n", result);
	system("pause");
	return 0;
}