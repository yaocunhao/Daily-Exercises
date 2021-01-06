#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//获得平方根近似值

int main()
{
	int n = 0;
	float first = 0;
	float ret = 1;
	int count=0;
	printf("请输入一个正整数\n");
	scanf("%d", &n);
	if (n < 0)
		printf("输入错误\n");
	else
	{
		while (first != ret)
		{
			count++;
			first = ret;
			ret = (first + n / first) / 2;
			printf("第%d次的结果为%lf\n",count, ret);
		} 



	}
	system("pause");
	return 0;

}