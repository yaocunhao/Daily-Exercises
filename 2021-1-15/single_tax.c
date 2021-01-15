#include <stdio.h>
#include <windows.h>
#pragma warning(disable :4996)


typedef struct TAX{
	float income;
	float base;
	float tax;
}tax;
tax first = { 23350, 0, 0.15f }, second = { 56550, 3502.50, 0.28f };
tax third = { 117950, 12798, 0.31f }, fourth = { 256500, 31832, 0.36f }, fifth = { 256500, 81710, 0.396f };

float single_tax(float money)
{
	if (money <= first.income)
		return (money*(first.tax));
	else if (money <= (second.income))
		return (second.base + money*(second.tax));
	else if (money <= third.income)
		return (third.base + money*(third.tax));
	else if (money <= fourth.income)
		return ((fourth.base) + money*(fourth.tax));
	else
		return (fifth.base + money*(fifth.tax));
}
int main()
{
	float money = 0;
	printf("请输入您的收入\n");
	scanf("%f", &money);
	float ret=single_tax(money);
	printf("您应该缴税%lf元\n", ret);
	system("pause");
	return 0;
}