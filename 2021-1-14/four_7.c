#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996 )

void Deblank(char string[])
{
	char *dst = string;
	while (*(dst+1)!='\0')
	{
		if (*dst == ' '&&*(dst + 1) == ' ')
			strcpy(dst, (dst + 1));
		else
		dst++;
	}
}

int main()
{

	char string[] = "h                   e                   l    lo    ! w o r     d           ";
	Deblank(string);
	printf("%s\n", string);
	printf("%d\n", strlen(string));
	system("pause");
	return 0;
}