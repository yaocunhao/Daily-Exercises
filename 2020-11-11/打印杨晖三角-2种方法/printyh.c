#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

void PrintYh()
{
	int arr[50][50] = { 1 };
	for (int i = 1; i < 10; i++)//»»ÐÐ
	{
		for (int j = 1; j <= i; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
	for (int i =0; i < 10; i++)
	{
		printf("%d ", arr[0][0]);
		for (int j = 1; j <= i; j++)
		{
			printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	PrintYh();
	system("pause");
	return;
}