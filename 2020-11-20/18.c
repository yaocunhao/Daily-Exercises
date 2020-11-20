#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//求S = A + AA + AAA + AAAA + AA ...一个的值，其中一个是一个数字。
//例如2 + 22 + 222 + 2222 + 22222（此时共有5个数相加），几个数相加由键盘控制。
int Sum(int a,int k)
{
	int t = a;
	int ret = a;
	for (int i = 1; i < k; i++)
	{
		t = t*10 + a;
		ret += t;
	}
	return ret;
}


int main()
{
	int A = 0;
	int K = 0;
	printf("请输入A的值和需要几个数相加K的值\n");
	scanf("%d %d", &A, &K);
	printf("%d\n",Sum(A, K));
	system("pause");
	return 0;
}