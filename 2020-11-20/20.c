#include <stdio.h>
#include <windows.h>
//一球从100米高度自由落下，每次落地后反跳回原高度的一半;
//再落下，求它在第10次落地时，共经过多少米第10次反弹多高？
void Ball()
{
	double m = 100;
	double ret = 0;
	for (int i = 0; i < 10; i++)
	{
		ret += (m + m / 2);//总共经过多少米；
		m /= 2;
	}
	printf("第十次落地总共经过%lf米，第十次反弹%lf米\n",ret-m,m);
}
int main()
{
	
	Ball();
	system("pause");
	return 0;
}