#include <stdio.h>
#include <windows.h>
//��0��7������ɵ�����������
OddNumber()
{
	int sum = 4;//һλ������
	int s = 4;
	for (int j = 2; j <= 8; j++)
	{
		printf("%dλ��Ϊ�����ĸ���Ϊ%d\n", j - 1, s);
		if (j <= 2)
			s = s * 7;//����0��
		else
			s = s * 8;
		sum += s;
	}
	printf("����������Ϊ%d\n", sum);
}
int main()
{
	OddNumber();
	system("pause");
	return 0;
}