#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//��дһ������������nΪż��ʱ�����ú�����1/2+1/4+...+1/n,
//������nΪ����ʱ�����ú���1/1+1/3+...+1/n(����ָ�뺯��)��
double EvenNumber(int n)
{
	double sum = 0;
	for (double i = 2; i < (n+1); i+=2)
	{
		sum += 1 / i;
	}
	return sum;
}
double OddNumber(int n)
{
	double sum = 0;
	for (double  i = 1; i < (n + 1); i+=2)
	{
		sum += 1 / i;
	}
	return sum;
}

int main()
{
	int n = 0;
	printf("����������\n");
	scanf("%d", &n);
	if ((n % 2)!=0)
		printf("%lf\n", (*OddNumber)(n));
	else
		printf("%lf\n", (*EvenNumber)(n));
	system("pause");
	return 0;
}