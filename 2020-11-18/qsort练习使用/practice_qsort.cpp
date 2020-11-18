#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
//整形数组
//int Comp(const void *_x,const void *_y)//传进来的是任意一个元素的地址
//{
//	int *x = (int *)_x;//void不能解引用
//	int *y = (int *)_y;
//	if (*x > *y)
//	{
//		return 1;
//	}
//	else if (*x < *y)
//	{
//		return -1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//void Prin(int arr[], int num)
//{
//	for (int i = 0; i < num; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//}
//
//int main()
//{
//	int arr[] = { 123, 15, 51, 2, 5451, 65, 45, 84 };
//	int num = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, num, sizeof(int), Comp);
//	Prin(arr, num);
//	system("pause");
//	return 0;
//}


//字符数组
//int Comp(const void *_x, const void *_y)//二级指针
//{
//	char *x = *(char **)_x;
//	char *y = *(char **)_y;
//	return  *x - *y;
//}
//void Prin(char *str[], int num)
//{
//	for (int i = 0; i < num; i++)
//	{
//		printf("%s \n",str[i]);
//	}
//}
//int main()
//{
//	char *str[] = { "one", "tow", "there", "four" };
//	int num = sizeof(str) / sizeof(str[0]);
//	qsort(str, num, sizeof(char*), Comp);
//	Prin(str, num);
//	system("pause");
//	return 0;
//}


//浮点型数组
//int Comp(const void *_x, const void *_y)
//{
//	double *x = (double *)_x;
//	double *y = (double *)_y;
//	if (*x > *y)
//	{
//		return 1;
//	}
//	else if (*x < *y)
//	{
//		return -1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//void Prin(double arr[], int num)
//{
//	for (int i = 0; i < num; i++)
//	{
//		printf("%lf\n", arr[i]);
//	}
//}
//
//int main()
//{
//	double arr[] = { 1.11,1.112,2.10,1.12,1.151,1.01};
//	int num = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, num, sizeof(double), Comp);
//	Prin(arr, num);
//	system("pause");
//	return 0;
//}

