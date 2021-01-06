#include <stdio.h>
#include <windows.h>

void copy_n(char dst[], char src[], int n)
{
	char *str = dst;
	while (n--)
	{
		if (*src)
			*str = *src;
		else
			*str = 0;
		str++;
		src++;
	}
	printf("%s\n", dst);
}
int main()
{

	char src[] = "helloword";
	char dst[100];
	copy_n(dst, src, 9);
	system("pause");
	return 0;
}