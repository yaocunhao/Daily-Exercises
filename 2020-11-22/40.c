#include <stdio.h>
#include <windows.h>
//将一个数组逆序输出。
void Reverse(int arr[],int num)
{
	int t = 0;
	int left = 0;
	int right = num - 1;
	while (left < right)
	{
		t = arr[left];
		arr[left] = arr[right];
		arr[right] = t;
		left++;
		right--;
	}
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int num = sizeof(arr) / sizeof(arr[0]);
	Reverse(arr, num);
	for (int i = 0; i < num; i++)
	{
		printf("%d\n", arr[i]);
	}
	system("pause");
	return 0;
}