#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//��n��������ʹ��ǰ�����˳�������m��λ�ã����m���������ǰ���m������
void Move(int arr[], int num,int m)
{
	int t = 0;
	for (int j = 0; j < m; j++)
	{
		t = arr[num - 1];//�����һλ�ó���
		for (int i = 1; i < num; i++)
		{

			arr[num - i] = arr[num - i - 1];//���������ƶ���һλ
		}
		arr[0] = t;
	}
}
int main()
{
	int m = 0;
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int num = sizeof(arr) / sizeof(arr[0]);
	printf("��������Ҫ�ƶ��ĸ���\n");
	scanf("%d", &m);
	Move(arr, num,m);
	for (int i = 0; i < num; i++)
	{
		printf("%d\n", arr[i]);
	}
	system("pause");
	return 0;
}