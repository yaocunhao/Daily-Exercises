#include <stdio.h>
#include <windows.h>
#pragma warning (disable:4996)
//输入一个整数，并将其反转后输出。
void Reverse(int num)
{
	int reverse_number = 0;
	int t = 0;
	while (num)
	{
		t = num % 10;
		reverse_number = reverse_number * 10 + t;
		num /= 10;
	}
	printf("颠倒后的数字是%d\n", reverse_number);
}
int main()
{
	int num = 0;
	printf("请输入一个整数\n");
	scanf("%d", &num);
	Reverse(num);
	system("pause");
	return 0;
}