#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//，有n个人围成一圈，顺序排号。从第一个人开始报数（从1到3报数），凡
//报到3的人退出圈子，问最后留下的是原来第几号的那位。
void Fun(int n)
{
	int arr[50];
	int *p = arr;
	int i = 0;//用于指针后移
	int k = 0;//用于报数
	int m = 0;//用于统计退出的人数
	for (int i = 0; i<n; i++)
	{
		arr[i] = 1;//将所有人编上号；
	}
	while (m < n - 1)
	{
		if (*(p + i) == 1)
		{
			k++;//报数+1
		}
		if (3==k)//报的数为3的人
		{
			*(p + i) = 0;//退出
			m++;//人数+1
			k = 0;//重置
		}
		i++;//指针后移
		if (i == n)//到头了
		{
			i = 0;//重置
		}
	}
	int j = 0;
	for (j = 0; j < n; j++)
	{
		if (arr[j] == 1)
		{
			break;
		}
	}
	printf("这个人是原来的%d号\n", j+1);
}

int main()
{
	int n;
	printf("请输入人数\n");
	scanf("%d", &n);
	Fun(n);
	system("pause");
	return 0;
}