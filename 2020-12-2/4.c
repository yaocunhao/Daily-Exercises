#include <stdio.h>
#include <windows.h>
//给出一个转动过的有序数组，你事先不知道该数组转动了多少(例如, 0 1 2 4 5 6 7可能变为4 5 6 7 0 1 2).
//在数组中搜索给出的目标值，如果能在数组中找到，返回它的索引，否则返回 - 1。
//假设数组中不存在重复项。

int FindNum(int arr[], int num,int target)
{
	int left = 0;
	int right = num - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (arr[mid] == target)
			{
				return mid;
			}
			if (arr[mid] >= arr[left])//左边有序
			{
				if (target < arr[mid]&&target>=arr[left])
					right = mid - 1;
				else
					left = mid +1 ;
			}
			else//右边有序
			{
				if (target>arr[mid]&&target<=arr[right])
					left = mid + 1;
				else
					right = mid - 1;
			}
	
		}
		return -1;

}

int main()
{
	int arr[] = {7,6,5,4,3,2,1,0,8};
	int num = sizeof(arr) / sizeof(arr[0]);
	int target =0;
	printf("%d\n",FindNum(arr, num,target));
	system("pause");
	return 0;
}