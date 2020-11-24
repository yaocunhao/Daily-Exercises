#include <stdio.h>
#include <windows.h>
//809*??=800*??+9*?? 其中??代表的两位数, 809*??为四位数，
//8*??的结果为两位数，9*??的结果为3位数。求??代表的两位数，及809*??后的结果。
int main()
{
	int n = 9;
	while (!(((809 * n) == (800 * n + 9 * n))&&(n%10!=n)&&\
		((809*n)<10000)&&(8*n)<100&&(9*n)<1000&&(9*n)>100))
	{
		n++;
	}
	int result = 809 * n;
	printf("n=%d 809*%d=%d\n", n, n,result);
	system("pause");
	return 0;
}