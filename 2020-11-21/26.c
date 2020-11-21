#include <stdio.h>
#include <windows.h>
//利用递归方法求5！
int Recursion(int num)
{
	if (num == 1)
		return 1;
	return num*Recursion(num - 1);
}
int main()
{
	printf("%d\n", Recursion(5));
	system("pause");
	return 0;
}