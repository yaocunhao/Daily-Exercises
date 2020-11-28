#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//从键盘输入一些字符，逐个把它们送到磁盘上去，直到输入一个#为止。
int main()
{
	FILE *fp = fopen("rest.log", "w");
	int c = 0;
	printf("请输入字符以#结束\n");
	while ((c = fgetc(stdin) )!= '#')
	{
		fputc(c, fp);
		fseek(fp, 0, SEEK_END);
	}
	fclose(fp);
	system("pause");
	return 0;
}