#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//��S = A + AA + AAA + AAAA + AA ...һ����ֵ������һ����һ�����֡�
//����2 + 22 + 222 + 2222 + 22222����ʱ����5������ӣ�������������ɼ��̿��ơ�
int Sum(int a,int k)
{
	int t = a;
	int ret = a;
	for (int i = 1; i < k; i++)
	{
		t = t*10 + a;
		ret += t;
	}
	return ret;
}


int main()
{
	int A = 0;
	int K = 0;
	printf("������A��ֵ����Ҫ���������K��ֵ\n");
	scanf("%d %d", &A, &K);
	printf("%d\n",Sum(A, K));
	system("pause");
	return 0;
}