#include <stdio.h>
#include <windows.h>
//���������飬�������һ��Ԫ�ؽ�������С�������һ��Ԫ�ؽ�����������顣
void Prin(int arr[], int num)
{
	int num2 = 0;
	int t = 0;
	int i = 0;
	for (i = 0; i < num; i++)//�ҵ����Ԫ�ص��±�
	{
		if (arr[i]>t)
		{
			t = arr[i];
			num2 = i;
		}
	}
	t = arr[num2];
	arr[num2] = arr[0];
	arr[0] = t;

	for (i = 0; i < num; i++)//�ҵ���СԪ���±�
	{
		if (arr[i] < t)
		{
			t = arr[i];
			num2 = i;
		}
	}
	t = arr[num2];
	arr[num2] = arr[num - 1];
	arr[num - 1] = t;
}
int main()
{
	int arr[5] = { 12,123,4,65,21 };
	int num = sizeof(arr) / sizeof(arr[0]);
	Prin(arr, num);
	for (int i = 0; i < num; i++)
	{
		printf("%d\n", arr[i]);
	}
	system("pause");
	return 0;
}