#include <stdio.h>
#include <windows.h>
//消除重复数组
//方法1：int removeDuplicates(int* nums, int numsSize){
//	int lable = 0;
//	for (int i = 0; i<numsSize; i++)
//	{
//		int count = 0;
//		for (int j = i; j<numsSize; j++)
//		{
//			if (nums[i] == nums[j])
//				count++;
//		}
//		if (count<2)
//		{
//			nums[lable] = nums[i];
//			lable++;
//		}
//	}
//	return lable;
//
//}

//方法2：
int removeDuplicates(int* nums, int numsSize){
	int src = 0;
	int str = 1;
	if (numsSize == 0)
		return 0;
	int dst = 1;
	while (str < numsSize)
	{
		if (nums[src] != nums[str])
		{
			nums[dst] = nums[str];
			dst++;
		}
		src++;
		str++;
	}
	return dst;
}
int main()
{
	int arr[] = {0,0,1,1,2,2,3,3,4 };
	int num = sizeof(arr) / sizeof(arr[0]);
	int ret=removeDuplicates(arr, num);
	for (int i = 0; i < ret; i++)
	{
		printf("%d\n", arr[i]);
	}
	system("pause");
	return 0;
}