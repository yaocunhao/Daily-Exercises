#include <stdio.h>
#include <windows.h>
//学习静态定义静态变量的用法。
int main()
{
	for (int i = 0; i < 10; i++)
	{
		static	int j = 0;
		printf("%d\n", j);
		j++;
	}
	system("pause");
	return 0;
}