#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
#include <assert.h>
//删除一个字符串中的指定字母，如：字符串“ACA”，删除其中的一个字母。

char *DeleteCharacters(char *str,const char *dst)
{
	assert(str);
	if (dst == 0)
	{
		return str;
	}
	int src[300] = { 0 };
	int new = 0;
	for (int i = 0; i < (int)strlen(dst); i++)
	{
		src[dst[i]] = 1;//对应字母asciil下标数组内容变为1；
	}
	for (int i = 0; i < (int)strlen(str); i++)
	{
		if (src[str[i]]!= 1)//ascii不相同则保留；
		{
			str[new++] = str[i];
		}
	}
	str[new] = '\0';//保留new个字符，下标为new设为\0；
	return str;
}

int main()
{
	char str[100];
	char dst[100];
	printf("请输入原字符串\n");
	scanf("%s", &str);
	printf("请输入需要删除的字符\n");
	scanf("%s", &dst);
	DeleteCharacters(str, dst);
	printf("%s\n", str);
	system("pause");
	return 0;
}