#include <stdio.h>
#include <windows.h>
//有一分数序列：2 / 1,3 / 2,5 / 3,8 / 5,13 / 8,21 / 13 ...求出这个数列的前20项之和。
void Sum()
{
	double i = 2;
	double j = 1;
	double result = 0;
	for (int h = 0; h < 20; h++)
	{
		result += i / j;
		double k = i;
		i = i + j;
		j = k;
	}
	printf("result=%lf\n", result);
}
int main()
{
	Sum();
	system("pause");
	return 0;
}