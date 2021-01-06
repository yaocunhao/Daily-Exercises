//判断三角形类型
#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
int main()
{
	int first = 0;
	int second = 0;
	int third = 0;
	printf("请输入三条边\n");
	scanf("%d %d %d", &first, &second, &third);
	if (first + second < third || first + third < second || second + third < first)
		printf("不是三角形\n");
	else
	{
		if (first == second&&second == third)
			printf("等边三角形\n");
		else if (first == second || first == third || second == third)
			printf("等腰三角形");
		else
			printf("这是一个普通的三角形");
	}
	system("pause");
	return 0;
}