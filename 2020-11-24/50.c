#include <stdio.h>
#include <windows.h>
#pragma warning (disable:4996)
//����һ�������������䷴ת�������
void Reverse(int num)
{
	int reverse_number = 0;
	int t = 0;
	while (num)
	{
		t = num % 10;
		reverse_number = reverse_number * 10 + t;
		num /= 10;
	}
	printf("�ߵ����������%d\n", reverse_number);
}
int main()
{
	int num = 0;
	printf("������һ������\n");
	scanf("%d", &num);
	Reverse(num);
	system("pause");
	return 0;
}