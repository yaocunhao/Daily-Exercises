#include <stdio.h>
#include <windows.h>
//找单身狗：一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//编写一个函数找出这两个只出现一次的数字。
void Signle_dog(int arr[], int num)
{
	int j = 0;
	while (j < num)
	{
		int count=0;
		int i = 0;
		for (i = 0; i < num; i++)
		{
			if (arr[j] == arr[i])
			{
				count++;
				if (count==2)
				break;
			}
		}
		if (count!=2)
		{
			printf("这个数是%d\n", arr[j]);
		}
		j++;
	}
}

int main()
{
	int arr[] = {200,59,200,59,300,250};
	int num = sizeof(arr) / sizeof(arr[0]);
	Signle_dog(arr, num);
	system("pause");
	return 0;
}