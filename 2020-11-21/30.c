#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//һ��5λ�����ж����ǲ��ǻ���������12321�ǻ���������λ����λ��ͬ��ʮλ��ǧλ��ͬ��
void BackNum(int n)
{
	if ((n % 10 == n / 10000) && (n / 10 % 10 == n / 1000%10))
	{
		printf("%d�ǻ���\n", n);
	}
	else
		printf("%d���ǻ���\n", n);
}

int main()
{
	int n = 0;
	printf("����һ����λ��\n");
	scanf("%d", &n);
	BackNum(n);
	system("pause");
	return 0;
}