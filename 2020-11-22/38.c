#include <stdio.h>
#include <windows.h>
//��һ��3��3����Խ���Ԫ��֮�͡�
int DiagonalSum(int arr[][3])
{
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum += arr[i][i];
	}
	return sum;
}
int main()
{
	int arr[3][3] = { 1, 54, 12, 44, 51, 21, 4, 12, 65 };
	int result=DiagonalSum(arr);
	printf("%d\n", result);
	system("pause");
	return 0;
}