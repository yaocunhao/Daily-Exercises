#include <stdio.h>
#include <windows.h>
//求0—7所能组成的奇数个数。
OddNumber()
{
	int sum = 4;//一位数奇数
	int s = 4;
	for (int j = 2; j <= 8; j++)
	{
		printf("%d位数为奇数的个数为%d\n", j - 1, s);
		if (j <= 2)
			s = s * 7;//不算0；
		else
			s = s * 8;
		sum += s;
	}
	printf("总奇数个数为%d\n", sum);
}
int main()
{
	OddNumber();
	system("pause");
	return 0;
}