#include <stdio.h>
#include <windows.h>
#include <math.h>
//打印出所有的"水仙花数"，所谓"水仙花数"是指一个三位数，其各位数字立方和等于该数本身。
//例如：153是一个"水仙花数"，因为153=1的三次方＋5的三次方＋3的三次方。
void DaffodilNum()
{
	int i = 0;
	while (i < 100000)
	{
		int t = i;
		int count = 0;
		int result = 0;
		while (t)//计算有多少位！;
		{
			count++;
			t /= 10;
		}
		t = i;
		while (t)//每位数的次方再相加;
		{
			result += pow((t % 10), count);
			t /= 10;
		}
		if (result == i)
			printf("%d is daffodil number!\n",i);
		i++;
	}
}
int main()
{
	DaffodilNum();
	system("pause");
	return 0;
}