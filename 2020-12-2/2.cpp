#include <stdio.h>
#include <windows.h>
#include <string.h>
//给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的中位数。

double MidNum(double nums1[], double nums2[], int m, int n)
{
	double *arr = (double *)malloc(sizeof(double)*(m + n));
	double *dst = arr;
	for (int i = 0; i < m; i++)
	{
		*dst = nums1[i];
		dst++;
	}
	for (int i = 0; i < n; i++)
	{
		*dst = nums2[i];
		dst++;
	}
	for (int i = 0; i < m + n - 1; i++)
	{
		int lable = 0;
		for (int j = 0; j < m + n-1; j++)
		{
			if (*(arr + j)>*(arr + j + 1))
			{
				double t = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = t;
				lable = 1;
			}
		}
		if (!lable)
			break;
	}
	double k = 0;
	int j = (m + n) / 2;
	if ((m + n) % 2 == 0)
	{
		printf("%lf %lf\n", arr[j], arr[j - 1]);
		k = (arr[j] / 2 )+ (arr[j - 1] / 2);
		return k;
	}
	else
		return arr[j];
}
int main()
{
	double nums1[] = { 1, 5, 4, 8, 9 };
	int m = sizeof(nums1) / sizeof(nums1[0]);
	double nums2[] = { 12, 23, 456, 48, 15 };
	int n = sizeof(nums2) / sizeof(nums2[0]);
	double ret=MidNum(nums1, nums2, m, n);
	printf("这个数的中位数是%lf\n", ret);

	system("pause");
	return 0;
}