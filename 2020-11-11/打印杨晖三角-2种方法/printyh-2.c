#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

void PrintYh()
{
	int arr[50] = { 1 };
	printf("%5d\n", 1);
	for (int i = 1; i < 10; i++)
	{
		for (int j = i; j>0; j--)
		{
			arr[j] += arr[j - 1];//´ÓºóÍùÇ°Ìî³ä
		}
		for (int j = 0; j <= i; j++)
		{
			printf("%5d ", arr[j]);
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