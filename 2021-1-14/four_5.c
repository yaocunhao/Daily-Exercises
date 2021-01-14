#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)


int main()
{
	char str[128];
	char dst[128];
	while (1)
	{
		gets(dst);
		if (strcmp(dst, str))
		{
			printf("%s\n", dst);
			strcpy(str, dst);
		}

	}


	system("pause");
	return 0;
}