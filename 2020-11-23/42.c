#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//ȡһ������a���Ҷ˿�ʼ��4��7λ����λ��
int main()
{
	int n = 0;
	int num = 0;
	scanf("%d", &n);
	num = ((n>>=3)&15);
	for (int i = 0; i < 4; i++)
	{
		if (num & 1)
			printf("%d\n", 1);
		else
			printf("%d\n", 0);
		num >>= 1;
	}
	system("pause");
	return 0;
}