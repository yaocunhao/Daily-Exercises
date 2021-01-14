#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//吃汉堡，hungry函数根据是否饥饿返回真值或者假值
int Hungry(int n)
{
	if (n >= 0)
		return 0;
	else
		return 1;
}
void eat_hamberger(int n)
{
		int count = 0;
		while (n)
		{
			count++;
			printf("当前吃了%d个\n", count);
			n++;
		}

}
int main()
{
	int count = 0;
	int hungry = 0;
	printf("请输入你当前的饥饿值");
	scanf("%d", &hungry);
	if (Hungry(hungry))
	{
	eat_hamberger(hungry);
	}
	else
	{
		printf("你吃了一个汉堡");
	}



	system("pause");
	return 0;
}