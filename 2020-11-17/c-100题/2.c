//企业发放的奖金根据利润提成。
//利润(I)低于或等于10万元时，奖金可提10%；
//利润高于10万元，低于20万元时，低于10万元的部分按10%提成，高于10万元的部分，可提成7.5%；
//20万到40万之间时，高于20万元的部分，可提成5%；
//40万到60万之间时高于40万元的部分，可提成3%；
//60万到100万之间时，高于60万元的部分，可提成1.5%；
//高于100万元时，超过100万元的部分按1%提成。
//从键盘输入当月利润I，求应发放奖金总数？
#include<stdio.h>
#include <windows.h>
#pragma warning (disable :4996)

void Bonus()
{
	double i= 0;
	printf("请输入当月的利润\n");
	scanf("%lf", &i);
	double bonus1 = 10* 0.1;
	double bonus2 = bonus1 + 0.075*(i-10);
	double bonus3 = bonus2 + 0.075*(i - 20);
	double bonus4 = bonus3 + 0.03*(i - 40);
	double bonus5 = bonus4 + 0.015*(i - 60);
	double bonus6 = bonus5 + 0.01*(i - 100);
	if (i <= 10)
	{
		printf("你当月的奖金为%lf万元\n", i*0.1);
	}
	else if (i>10&&i<=20)
	{
		printf("你当月的奖金为%lf万元\n", bonus2);
	}
	else if (i>20&&i<=40)
	{
		printf("你当月的奖金为%lf\n万元", bonus3);
	}
	else if (i>40&&i<=60)
	{
		printf("你当月的奖金为%lf\n万元", bonus4);
	}
	else if (i>60&&i<=100)
	{
		printf("你当月的奖金为%lf\n万元", bonus5);
	}
	else 
	{
		printf("你当月的奖金为%lf\n万元", bonus6);
	}
}
int main()
{
	Bonus();
	system("pause");
	return 0;
}