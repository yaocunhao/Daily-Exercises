#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//有n个整数，使其前面各数顺序向后移m个位置，最后m个数变成最前面的m个数。
void Move(int arr[], int num,int m)
{
	int t = 0;
	for (int j = 0; j < m; j++)
	{
		t = arr[num - 1];//将最后一位拿出来
		for (int i = 1; i < num; i++)
		{

			arr[num - i] = arr[num - i - 1];//整体往后移动了一位
		}
		arr[0] = t;
	}
}
int main()
{
	int m = 0;
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int num = sizeof(arr) / sizeof(arr[0]);
	printf("请输入需要移动的个数\n");
	scanf("%d", &m);
	Move(arr, num,m);
	for (int i = 0; i < num; i++)
	{
		printf("%d\n", arr[i]);
	}
	system("pause");
	return 0;
}