#include <stdio.h>
#include <windows.h>
#pragma warning(disable :4996)
//��һ���Ѿ��ź�������顣������һ������Ҫ��ԭ���Ĺ��ɽ������������С�
void  Insert(int arr[],int num,int n)
{
	int t = 0;
	int i = 0;
	if (n>arr[num - 2])
	{
	arr[num-1] = n;
	}
	else
	for (i = 0; i < num; i++)
	{
		if (arr[i]>n)
		{
			for (i; i < num; i++)
			{
				t = arr[i];
				arr[i] = n;
				n = t;
			}
			break;
		}
	}
}

int main()
{
	int n = 0;
	int arr[11] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	int num = sizeof(arr) / sizeof(arr[0]);
	printf("��������Ҫ���������\n");
	scanf("%d", &n);
	Insert(arr,num,n);
	for (int i = 0; i < num; i++)
	{
		printf("%d\n", arr[i]);
	}
	system("pause");
	return 0;
}