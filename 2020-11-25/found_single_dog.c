#include <stdio.h>
#include <windows.h>
//�ҵ�����һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�
//��дһ�������ҳ�������ֻ����һ�ε����֡�
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
			printf("�������%d\n", arr[j]);
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