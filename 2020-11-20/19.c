#include <stdio.h>
#include <windows.h>
//һ�������ǡ�õ�����������֮�ͣ�������ͳ�Ϊ��������������6 = 1 + 2 + 3.����ҳ�1000���ڵ�����������
void PreNum()
{
	for (int i = 2; i < 1000; i++)//����ѭ������
	{
		int ret = 0;
		int arr[100] = {0};
		int k = 0;
		for (int j = 1; j < i; j++)//������
		{
			if (i%j == 0)
			{
				ret += j;
				arr[k] = j;
				k++;
			}
		}
		if (ret == i)
		{
			printf("%d=%d", ret,arr[0]);
			for (int j = 1; j < k; j++)
			{
				printf("+%d", arr[j]);
			}
			printf("\n");
		}
	}
	
}
int main()
{
	PreNum();
	system("pause");
	return 0;
}
