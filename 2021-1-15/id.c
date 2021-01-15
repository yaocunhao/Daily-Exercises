#include <stdio.h>
#include <windows.h>

int Identity_matrix(int (*arr)[3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
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
	int arr[3][3] = { 1,0,1,0,1,0,0,0,1 };

	int ret = Identity_matrix(arr);
	if (ret)
		printf("是单位矩阵\n");
	else
		printf("不是单位矩阵\n");

	system("pause");
	return 0;
}