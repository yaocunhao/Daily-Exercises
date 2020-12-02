#include <stdio.h>
#include <windows.h>
//请实现有重复数字的有序数组的二分查找。
//输出在数组中第一个大于等于查找值的位置，如果数组中不存在这样的数，则输出数组长度加一。
int NewBinearch(int arr[], int num, int flag)
{
	int left = 0;
	int right = (num - 1);

	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (flag <= arr[mid])
		{
			if (flag > arr[mid - 1])
				return (mid + 1);
			else
				right = mid - 1;
		}
		else if (flag > arr[mid])
		{
			left = mid + 1;
		}
	}
	return num + 1;
}
int main()
{
	int flag =97;
	int arr[] = { 3, 3, 4, 4, 4, 5, 6, 6, 6, 7, 8, 8, 12, 13, 15, 16, 21, 21, 22, 24, 24, 27, 28, 32, 34, 35, 35, 36, 36, 39, 40, 41, 41, 42, 44, 44, 45, 45, 47, 47, 47, 47, 48, 48, 50, 51, 51, 53, 53, 53, 54, 54, \
		54, 56, 56, 57, 59, 60, 60, 60, 60, 61, 62, 63, 65, 65, 65, 65, 67, 67, 68, 70, 71, 71, 74, 75, 75, 79, 81, 84, 84, 86, 86, 87, 90, 90, 90, 90, 91, 92, 93, 94, 94, 94, 95, 97, 97, 98, 98, 99 };
	int num = sizeof(arr) / sizeof(arr[0]);
	int ret = NewBinearch(arr, num, flag);
	printf("查找的下标为%d\n", ret);
	system("pause");
	return 0;
}