#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//求1 + 2！+3！+ ... + 20！的和。
//double SumFac(int num)
//{
//	double t = 1;
//	double result = 0;
//	for (int i = 1; i <= num; i++)
//	{
//		t *= i;
//		result += t;
//	}
//	return result;
//}
double  Recursion(int num)
{
	if (num == 1)
		return 1;
	else
		return num*Recursion(num - 1);
}
double SumFac(int num)
{
	double result = 0;
	while (num)
	{
		result+=Recursion(num);
		num--;
	}
	return result;
}
int main()
{
	int num = 0;
	printf("请输入需要求前多少项的阶乘和\n");
	scanf("%d", &num);
	double result=SumFac(num);
	printf("%lf", result);
	system("pause");
	return 0;
}