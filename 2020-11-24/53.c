#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//×Ö·û´®ÅÅĞò¡£
Rank(char str[])
{
	for (int i = 0; i < strlen(str)-1; i++)
	{
		for (int j = 0; j < strlen(str) - 1 - i; j++)
		{
			if (str[j]>str[j + 1])
			{
				char t = str[j];
				str[j] = str[j + 1];
				str[j + 1] = t;
			}
		}
	}

}
int main()
{
	char str[20];
	printf("ÇëÊäÈë×Ö·û´®\n");
	scanf("%s", str);
	Rank(str);
	printf("%s\n", str);
	system("pause");
	return 0;
}