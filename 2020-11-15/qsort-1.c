#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
int  ComInt(const void *_x,const void *_y)//һ������֮�У�����һ��Ԫ�صĵ�ַ
{
	int *x = (int*)_x;//void���Ͳ��ܽ�����
	int *y = (int*)_y;
	if (*x > *y)
		return -1;
	else if (*x < *y)
		return 1;
	else
		return 0;
}
Print(int arr[],int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%d\n", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[] = { 515, 11515, 544, 2322, 55, 886, 2, 58 };
	int num = sizeof(arr) / sizeof(arr[0]);
	Print(arr, num);
	qsort(arr,num,sizeof(int),ComInt);
	Print(arr, num);
	system("pause");
	return 0;
}