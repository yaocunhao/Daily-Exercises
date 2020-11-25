#include <stdio.h>
#include <windows.h>
#include <assert.h>
char *My_Strncpy(char *dst, char *str,int num)
{
		assert(dst&&str);
		char *s = dst;
		while (*str&&num)
		{
			*s = *str;
			s++;
			str++;
			num--;
		}
		if (num != 0)
		{
			*s = '\0';
		}
		return dst;
	
}
int main()
{
	char str[] = "abcdefgh";
	char dst[20];
	My_Strncpy(dst, str,9);
	printf("%s\n", dst);
	system("pause");
	return 0;
}