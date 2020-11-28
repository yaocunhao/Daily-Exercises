#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//读取7个数（1—50）的整数值，每读取一个值，程序打印出该值个数的＊。
void Prin(int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("*");
	}
}

int main()
{
	int n = 0;
for (int i = 0; i < 7; i++)
	{
		printf("请输入数字\n");
		scanf("%d", &n);
		Prin(n);
	}
	system("pause");
	return 0;
}