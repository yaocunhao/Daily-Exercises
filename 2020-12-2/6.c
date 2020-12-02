#include <stdio.h>
#include <windows.h>
void SingleNumbers(int arr[], int Num[], int num)
{
	int ret = 0;
	int val = 0;
	int target = 0;
	for (int i = 0; i < num; i++)
	{
		ret ^= arr[i];//相同异或为0，得到两个单数的异或值X=A^B
	}
	val = ret&(-ret);//得到x二进制序列之中第一个1，即A和B的二进制第一个不同位
	for (int i = 0; i < num; i++)
	{
		if ((val&arr[i]) != 0)
		{
			target ^= arr[i];//得到其中一个单的数字
		}
	}
	Num[0] = target;
	target ^= ret;//得到第二个
	Num[1] = target;
}

int main()
{
	int Num[2];
	int arr[] = { 4, 1, 4, 6,5,8,5,8,1,9 };
	int num = sizeof(arr) / sizeof(arr[0]);
	SingleNumbers(arr, Num, num);
	printf("%d\n%d\n", Num[0], Num[1]);
	system("pause");
	return 0;
}