#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//��������������m��n���������Լ������С��������
int MaxDiv(int m, int n)
{
	int c = 0;
	while (c = m%n)
	{
		m = n;
		n = c;
	}
	return n;
}
int MaxMul(int m,int n)
{
	int num = 0;
	 num = MaxDiv(m,n);
	return m / num*n;
}

int main()
{
	int m = 0;
	int n = 0;
	printf("��������������m��n\n");
	scanf("%d %d", &m, &n);
	printf("���Լ����%d\n",MaxDiv(m, n));
	printf("��С��������%d\n", MaxMul(m, n));
	system("pause");
	return 0;
}