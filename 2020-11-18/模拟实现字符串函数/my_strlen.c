#include <stdio.h>
#include <windows.h>
int My_Strlen(char str[])
{
	int count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return count;
}

int main()
{
	char str[] = "abcdef";
	int result=My_Strlen(str);
	printf("×Ö·û´®³¤¶ÈÎª%d\n", result);
	system("pause");
	return 0;
}