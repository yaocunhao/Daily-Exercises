#include <stdio.h>
#include <windows.h>
void SingleNumbers(int arr[], int Num[], int num)
{
	int ret = 0;
	int val = 0;
	int target = 0;
	for (int i = 0; i < num; i++)
	{
		ret ^= arr[i];//��ͬ���Ϊ0���õ��������������ֵX=A^B
	}
	val = ret&(-ret);//�õ�x����������֮�е�һ��1����A��B�Ķ����Ƶ�һ����ͬλ
	for (int i = 0; i < num; i++)
	{
		if ((val&arr[i]) != 0)
		{
			target ^= arr[i];//�õ�����һ����������
		}
	}
	Num[0] = target;
	target ^= ret;//�õ��ڶ���
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