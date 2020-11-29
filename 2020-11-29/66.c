#include <stdio.h>
#include <windows.h>
//调整数组使奇数全部都位于偶数前面。
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
			j++;
		}
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10};
	int num = sizeof(arr) / sizeof(arr[0]);
	Exca(arr, num);
	for (int i = 0; i < num; i++)
	{
		printf("%d\n", arr[i]);
	}
	system("pause");
	return 0;
}