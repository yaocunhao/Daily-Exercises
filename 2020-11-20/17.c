#include <stdio.h>
#include <windows.h>
//输入一行字符，分别统计出其中英文字母，空格，数字和其它字符的个数。

void Sum()
{
	int num = 0;
	int  c = 0;
	int letter = 0;
	int blank = 0;
	int Else = 0;
	while ((c = getchar()) != '\n')
	{
		if ((c >= 'a'&&c<='z')|| (c>='A'&&c <= 'Z'))
		{
			letter++;
		}
		else if (c == ' ')
		{
			blank++;
		}
		else if (c >= '0'&&c <= '9')
		{
			num++;
		}
		else
		{
			Else++;
		}
	}
	printf("字母个数为%d\n", letter);
	printf("空格个数为%d\n", blank);
	printf("数字个数为%d\n", num);
	printf("其他个数为%d\n", Else);
}

int main()
{
	Sum();
	system("pause");
	return 0;
}