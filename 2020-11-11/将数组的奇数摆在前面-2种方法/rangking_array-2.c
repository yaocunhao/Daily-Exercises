#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)
void Exca(int arr[], int num)
{
	int t = 0;
	int j = 0;
	for (int i = 0; i < num; i++)
	{
		if (arr[i] % 2 != 0)
		{
			t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
			j++;//遇到奇数，就指向下一个数组元素;
		}
	}
}

int main()
{
	int arr[] = { 2, 6, 5, 7, 9, 11, 20, 41, 51, 33, 58 };
	int num = sizeof(arr) / sizeof(arr[0]);
	Exca(arr, num);
	for (int i = 0; i < num; i++)
	{
		printf("%d\n", arr[i]);
	}
	system("pause");
	return;
}