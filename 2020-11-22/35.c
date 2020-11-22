#include <stdio.h>
#include <windows.h>
#pragma warning(disable :4996)
//字符串反转，如将字符串“www.runoob.com”反转为“moc.boonur.www”。
void ReverseString(char *str)
{
	char *left = str;
	char *right = str + strlen(str) - 1;
	char temp;
	while (left < right)
	{
		temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}

int main()
{
	char str[100];
	printf("请输入需要翻转的字符串\n");
	scanf("%s", str);
	ReverseString(str);
	printf("%s\n", str);
	system("pause");
	return 0;
}