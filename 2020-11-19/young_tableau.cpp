#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ�
//���д�����������ľ����в���ĳ�������Ƿ���ڡ�
//ʱ�临�Ӷ�С��O(N)��������������ͬ�����໥Ƕ��
//˼·���ӵ�һ�У����һ�����ֿ�ʼ�Ƚϣ�num����������־ͻ��У�numС�ھ������ƶ�һ�����֣�
//ֱ���ҵ����߳������鷶Χ��
int FindNum(int arr[][3],int num,int x,int y)//�жϷ�Χ
{
	int i = 0;
	int j = y-1;
	while (i<x&&j>=0)
	{
		if (num>arr[i][j])//��һ��������������ͻ���
		{
			i++;//���»���һ�Σ�
		}
		else if (num < arr[i][j])//��һ����������С�����������
		{
			j--;//�����ƶ�һ�����֣�
		}
		else
			return 1;//�ҵ���

	}
	return 0;//û�ҵ�
	
}

int main()
{
	int arr[3][3] = { { 1, 2, 3 }, { 10, 20, 30 }, { 100, 200, 300 } };
	int x = 3;//������
	int y = 3;//������
	int num = 0;
	printf("��������Ҫ���ҵ�����\n");
	scanf("%d", &num);
	int result=FindNum(arr,num,x,y);
	if (result)
	{
		printf("������ִ���\n");
	}
	else
		printf("������ֲ�����\n");
	system("pause");
	return 0;
}