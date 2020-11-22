#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//请输入星期几的第一个字母来判断一下是星期几，如果第一个字母一样，则继续判断第二个字母。

void Day()
{
	char i = 0;
	char j = 0;
	printf("请输入第一个字母\n");
	scanf("%c", &i);
	getchar();//迟到scanf带来的空格；
	switch (i)
	{
	case 'm':
		printf("今天星期1\n");
		break;
	case 'w':
		printf("今天星期3\n");
		break;
	case 'f':
		printf("今天星期5\n");
		break;
	case 't':
		printf("请输入第二个字符\n");
		scanf("%c", &j);
		switch (j)
		{
		case 'h':
			printf("今天星期4\n");
			break;
		case 'u':
			printf("今天星期2\n");
			break;
		default:
			printf("输入有误\n");
			break;
		}
		break;
	case 's':
		printf("请输入第二个字符\n");
		scanf("%c", &j);
		switch (j)
		{
		case 'a':
			printf("今天星期7\n");
			break;
		case 'u':
			printf("今天星期6\n");
			break;
		default:
			printf("输入有误\n");
			break;
		}
		break;
	default:
		printf("输入有误\n");
		break;
	}

}
int main()
{
	Day();
	system("pause");
	return 0;
}