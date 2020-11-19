#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，
//请编写程序在这样的矩阵中查找某个数字是否存在。
//时间复杂度小于O(N)，不能有两个相同函数相互嵌套
//思路：从第一行，最大一个数字开始比较，num大于这个数字就换行，num小于就往左移动一个数字，
//直到找到或者超出数组范围；
int FindNum(int arr[][3],int num,int x,int y)//判断范围
{
	int i = 0;
	int j = y-1;
	while (i<x&&j>=0)
	{
		if (num>arr[i][j])//比一行中最大的数还大就换行
		{
			i++;//往下换行一次；
		}
		else if (num < arr[i][j])//比一行中最大的数小，就往左边移
		{
			j--;//往左移动一个数字；
		}
		else
			return 1;//找到了

	}
	return 0;//没找到
	
}

int main()
{
	int arr[3][3] = { { 1, 2, 3 }, { 10, 20, 30 }, { 100, 200, 300 } };
	int x = 3;//横坐标
	int y = 3;//纵坐标
	int num = 0;
	printf("请输入你要查找的数字\n");
	scanf("%d", &num);
	int result=FindNum(arr,num,x,y);
	if (result)
	{
		printf("这个数字存在\n");
	}
	else
		printf("这个数字不存在\n");
	system("pause");
	return 0;
}