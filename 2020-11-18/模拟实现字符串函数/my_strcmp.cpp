#include <stdio.h>
#include <windows.h>
#include <assert.h>
int My_Strcmp(char str[], char dst[])
{
	assert(str&&dst);
	int result = 0;
	while (!result&&*dst)
	{
		result = *(unsigned char *)str - *(unsigned char *)dst;
		str++;
		dst++;
	}
	if (result > 0)
	{
		return 1;
	}
	else if (result < 0)
	{
		return -1;
	}
	else

		return 0;
}

int main()
{
	char str[] = "abcdf";
	char dst[] = "abcdf";
	int result=My_Strcmp(str, dst);
	printf("%d\n", result);
	system("pause");
	return 0;
}