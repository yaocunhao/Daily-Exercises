//求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
#include <math.h>

//int Sum(n)  方法1：利用&&短路原理
//{
//	int x = n > 1 && (n += Sum(n - 1));
//	return n;
//}
//int Sum(n)//方法2：利用公式 S=（1+n)*n/2=(n^2+n)/2
//{
//	int ret = (pow(n, 2) + n);
//	ret >>= 1;
//	return ret;
//}
int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d\n",Sum(n));
	system("pause");
	return 0;
}