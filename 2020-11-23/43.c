#include <stdio.h>
#include <windows.h>

//void Youngtableau()
//{
//	int arr[200] = { 0 };
//	arr[0] = 1;
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = i; j>0; j--)
//		{
//			arr[j] = arr[j] + arr[j - 1];//从后向前赋值
//		}
//		for (int k = 0; k < i + 1; k++)
//		{
//			printf("%2d ", arr[k]);//赋值一行，打印一行
//		}
//		printf("\n");
//	}
//}
void Youngtableau()
 {
	int arr[20][20] = { 0 };
	arr[0][0] = 1;
	for (int i = 1; i < 11; i++)
	{
		for (int j = 1; j < i+1; j++)
		{
			arr[i][j] = (arr[i - 1][j] + arr[i - 1][j - 1]);
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}
 }

int main()
{
	Youngtableau();
	system("pause");
	return 0;
}