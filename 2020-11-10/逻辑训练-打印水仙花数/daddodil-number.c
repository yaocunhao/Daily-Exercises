#include <stdio.h>
#include <windows.h>
#include <math.h>
void DafNum()
{
	for (int i = 0; i < 1000001; i++)
	{
		int count = 0;
		int t1 = i;
		int t2 = i;
		int result = 0;
		while (t1)
		{
			t1 /= 10;
			count++;
		}
		while (t2)
		{
			result+=(int )pow((t2 % 10), count);
			t2 /= 10;
		}
		if (i == result)
			printf("%d是水仙花数\n", result);
	}
}

int main()
{
	DafNum();
    system("pause");
	return 0;
}
