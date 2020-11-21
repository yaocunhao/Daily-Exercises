#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//一个5位数，判断它是不是回文数。即12321是回文数，个位与万位相同，十位与千位相同。
void BackNum(int n)
{
	if ((n % 10 == n / 10000) && (n / 10 % 10 == n / 1000%10))
	{
		printf("%d是回数\n", n);
	}
	else
		printf("%d不是回数\n", n);
}

int main()
{
	int n = 0;
	printf("输入一个五位数\n");
	scanf("%d", &n);
	BackNum(n);
	system("pause");
	return 0;
}