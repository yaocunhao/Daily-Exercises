#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�
//������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����

int rectCover(int number) {
	if (number<3)
		return number;
	else
		return rectCover(number - 1) + rectCover(number - 2);
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d",rectCover(n));
	system("pause");
	return 0;
}