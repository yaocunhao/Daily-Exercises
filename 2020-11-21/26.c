#include <stdio.h>
#include <windows.h>
//���õݹ鷽����5��
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