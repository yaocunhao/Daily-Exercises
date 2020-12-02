#include <stdio.h>
#include <windows.h>
//数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
int FindNum(int arr[],int num)
{
	int count = 0;
	int ret = 0;
	for (int i = 0; i < num; i++)
	{
		ret += i;
		count += arr[i];
	}
	return (ret + num - count);

}

int main()
{
	int arr[] = { 0,1,2,3,4,8,6,7};
	int num = sizeof(arr) / sizeof(arr[0]);
	int ret=FindNum(arr, num);
	printf("%d\n", ret);
	system("pause");
	return 0;
}