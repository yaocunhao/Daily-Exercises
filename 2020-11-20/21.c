#include <stdio.h>
#include <windows.h>
//猴子吃桃问题：猴子第一天摘下若干个桃子，当即吃了一半，还不瘾，又多吃了一个
//第二天早上又将剩下的桃子吃掉一半，又多吃了一个。
//以后每天早上都吃了前一天剩下的一半零一个。到第10天早上想再吃时，见只剩下一个桃子了。求第一天共摘了多少。
int  Monkey(int day)
{
	if (day == 10)
		return 1;
	else
		return 2 * (1 + Monkey(day + 1));
}

int main()
{
	printf("第一天共摘了%d个\n", Monkey(1));
	system("pause");
	return 0;
}