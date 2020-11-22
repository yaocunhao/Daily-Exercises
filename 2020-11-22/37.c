#include <stdio.h>
#include <windows.h>
//对10个数进行排序。
void Bubblesort(int arr[],int num)
{
	int t = 0;
	for (int i = 0; i < num; i++)//控制次数
	{
		int flag = 0;
		for (int j = 0; j < num - 1 - i; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				t=arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
				flag = 1;
			}
		}
		if (!flag)
		{
			break;
		}
	}
}
int main()
{
	int arr[10] = { 121, 154, 1, 4, 2, 5, 6, 98, 155, 45 };
	int num = sizeof(arr) / sizeof(arr[0]);
	Bubblesort(arr, num);
	for (int i = 0; i < num; i++)
	{
		printf("%d\n", arr[i]);
	}
	system("pause");
	return 0;
}