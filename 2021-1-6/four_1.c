#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//���ƽ��������ֵ

int main()
{
	int n = 0;
	float first = 0;
	float ret = 1;
	int count=0;
	printf("������һ��������\n");
	scanf("%d", &n);
	if (n < 0)
		printf("�������\n");
	else
	{
		while (first != ret)
		{
			count++;
			first = ret;
			ret = (first + n / first) / 2;
			printf("��%d�εĽ��Ϊ%lf\n",count, ret);
		} 



	}
	system("pause");
	return 0;

}