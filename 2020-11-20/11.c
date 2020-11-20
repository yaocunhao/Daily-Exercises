#include <stdio.h>
#include <windows.h>
//古典问题（兔子生崽）：有一对兔子，从出生后第3个月起每个月都生一对兔子，
//小兔子长到第三个月后每个月又生一对兔子，假如兔子都不死，问每个月的兔子总数为多少？（输出前40个月即可）
//思路: 兔子规律是 1 1 2 3 5 8 13即第3个月其 是前面两个月之和
int RabbitNum(int num)
{
	if (num < 3)
		return 1;
	else
		return RabbitNum(num - 1) + RabbitNum(num - 2);
}
int main()
{
	for (int i = 1; i < 41; i++)
	{
		int ret = RabbitNum(i);
		printf("第%d个月的兔子数量是%d\n", i, ret * 2);
	}
	system("pause");
	return 0;
}