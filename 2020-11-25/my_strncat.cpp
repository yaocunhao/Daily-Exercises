#include <stdio.h>
#include <windows.h>
#include <assert.h>
char* My_Strncat(char str[], char dst[], int num)
{
	assert(str&&dst);
	while (*str)
	{
		str++;
	}
	while (num&&*dst)//∑¿÷πdst‘ΩΩÁ;
	{
		*str = *dst;
		str++;
		dst++;
		num--;
	}

	return str;
}
int main()
{
	char str[50] = "hello";
	char dst[] = "word!";
	My_Strncat(str, dst, 2);
	printf("%s\n", str);
	system("pause");
	return 0;
}