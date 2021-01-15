#include <stdio.h>
#include <windows.h>

int Identity_matrix(int(*arr)[4],int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j&&arr[i][j] != 1)
				return 0;
			if (i != j&&arr[i][j] != 0)
				return 0;
		}
	}
	return 1;
}


int main()
{
	int size = 4;
	int arr[4][4] = { 1,0,0,3,0,1,0,0,0,0,1,0,0,0,0,1};
	int ret = Identity_matrix(arr,size);
	if (ret)
		printf("是单位矩阵\n");
	else
		printf("不是单位矩阵\n");

	system("pause");
	return 0;
}