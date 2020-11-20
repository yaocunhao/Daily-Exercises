#include <stdio.h>
#include <windows.h>
//一个数如果恰好等于它的因子之和，这个数就称为“完数”。例如6 = 1 + 2 + 3.编程找出1000以内的所有完数。
void PreNum()
{
	for (int i = 2; i < 1000; i++)//整个循环控制
	{
		int ret = 0;
		int arr[100] = {0};
		int k = 0;
		for (int j = 1; j < i; j++)//求因子
		{
			if (i%j == 0)
			{
				ret += j;
				arr[k] = j;
				k++;
			}
		}
		if (ret == i)
		{
			printf("%d=%d", ret,arr[0]);
			for (int j = 1; j < k; j++)
			{
				printf("+%d", arr[j]);
			}
			printf("\n");
		}
	}
	
}
int main()
{
	PreNum();
	system("pause");
	return 0;
}
