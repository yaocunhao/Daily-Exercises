#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//����n����Χ��һȦ��˳���źš��ӵ�һ���˿�ʼ��������1��3����������
//����3�����˳�Ȧ�ӣ���������µ���ԭ���ڼ��ŵ���λ��
void Fun(int n)
{
	int arr[50];
	int *p = arr;
	int i = 0;//����ָ�����
	int k = 0;//���ڱ���
	int m = 0;//����ͳ���˳�������
	for (int i = 0; i<n; i++)
	{
		arr[i] = 1;//�������˱��Ϻţ�
	}
	while (m < n - 1)
	{
		if (*(p + i) == 1)
		{
			k++;//����+1
		}
		if (3==k)//������Ϊ3����
		{
			*(p + i) = 0;//�˳�
			m++;//����+1
			k = 0;//����
		}
		i++;//ָ�����
		if (i == n)//��ͷ��
		{
			i = 0;//����
		}
	}
	int j = 0;
	for (j = 0; j < n; j++)
	{
		if (arr[j] == 1)
		{
			break;
		}
	}
	printf("�������ԭ����%d��\n", j+1);
}

int main()
{
	int n;
	printf("����������\n");
	scanf("%d", &n);
	Fun(n);
	system("pause");
	return 0;
}