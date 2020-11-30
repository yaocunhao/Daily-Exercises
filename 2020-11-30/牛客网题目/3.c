#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
//请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

int rectCover(int number) {
	if (number<3)
		return number;
	else
		return rectCover(number - 1) + rectCover(number - 2);
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d",rectCover(n));
	system("pause");
	return 0;
}