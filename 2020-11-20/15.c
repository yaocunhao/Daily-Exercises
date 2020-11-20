#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//利用条件运算符的嵌套来完成此题：学习成绩> = 90分的同学用A表示，60-89分之间的用B表示，60分以下的用C表示。
char  Score(int num)
{
	return num >= 90 ? 'A' : (num >= 60 ? 'B': 'C');
}

int main()
{
	int num = 0;
	printf("请输入成绩\n");
	scanf("%d", &num);
	char result=Score(num);
	printf("%c\n", result);
	system("pause");
	return 0;
}