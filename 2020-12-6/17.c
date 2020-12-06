//给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
#include <stdio.h>
#include <windows.h>
//方法1：//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
//	for (int i = 0; i<n; i++)
//	{
//		nums1[m + i] = nums2[i];
//	}
//	for (int i = 0; i<m + n - 1; i++)
//	{
//		int flag = 0;
//		for (int j = 0; j<m + n - 1 - i; j++)
//		{
//			if (nums1[j]>nums1[j + 1])
//			{
//				int temp = nums1[j];
//				nums1[j] = nums1[j + 1];
//				nums1[j + 1] = temp;
//				flag = 1;
//			}
//
//		}
//		if (!flag)
//			break;
//	}
//
//}


//方法2：void merge(int* nums1, int m, int* nums2,  int n){
//	int *arr = (int *)malloc(sizeof(int)*(n + m));
//	int first = 0;
//	int second = 0;
//	int sub = 0;
//	while (first<m&&second<n)
//	{
//		if (nums1[first]<nums2[second])
//		{
//			arr[sub] = nums1[first];
//			first++;
//		}
//		else
//		{
//			arr[sub] = nums2[second];
//			second++;
//		}
//		sub++;
//	}
//	if (second == n)
//	{
//		while (first<m)
//		{
//			arr[sub] = nums1[first];
//			sub++;
//			first++;
//		}
//	}
//	else
//	{
//		while (second<n)
//		{
//			arr[sub] = nums2[second];
//			sub++;
//			second++;
//		}
//	}
//	for (int i = 0; i<m + n; i++)
//	{
//		nums1[i] = arr[i];
//	}
//}


//解法3：void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	int first = m - 1;
	int second = n - 1;
	int sub = m + n - 1;
	while (first >= 0 && second >= 0)
	{
		if (nums1[first]>nums2[second])
		{
			nums1[sub] = nums1[first];
			first--;
		}
		else
		{
			nums1[sub] = nums2[second];
			second--;
		}
		sub--;
	}
	if (first<0)
	{
		while (second >= 0)
		{
			nums1[sub] = nums2[second];
			sub--;
			second--;
		}
	}
	else
	{
		while (first >= 0)
		{
			nums1[sub] = nums1[first];
			sub--;
			first--;
		}
	}


}

int main()
{
	int arr1[3] = { 1, 2, 3 };
	int arr2[3] = { 2, 5, 6 };
	merge(arr1, 3, arr2, 3);
	for (int i = 0; i < 6; i++)
	{
		printf("%d\n", arr1[i]);
	}
	system("pause");
	return 0;
}