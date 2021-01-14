#include <stdio.h>
#include <windows.h>

int substr(char dst[], char src[], int start, int len)
{
	if ((int )strlen(src) <=start || start < 0 || len < 0)
	{
		*dst = '\0';
		return 0;
	}
	char *str = src + start;
	char *newdst = dst;
	while (str&&len)
	{
		*dst = *str;
		dst++;
		str++;
		len--;
	}
	*dst = '\0';
	return strlen(newdst);
}
int main()
{
	char dst[100];
	char src[] = "hello,word";
	int len=substr(dst, src,0,10);
	printf("%d\n", len);
	printf("%s\n", dst);
	system("pause");
	return 0;
}