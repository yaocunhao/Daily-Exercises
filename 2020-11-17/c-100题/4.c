//输入某年某月某日，判断这一天是这一年的第几天？
#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)

int main()
{
	int year = 0;
	int month = 0;
	int day = 0;
	int sum = 0;
	int leap = 0;
	printf("请输入年月日，格式为：年，月，日\n");
	scanf("%d,%d,%d", &year, &month, &day);
	switch (month)
	{
	case 1:
		sum = 0;
		break;
	case 2:
		sum = 31;
		break;
	case 3:
		sum = 59;
		break;
	case 4:
		sum = 90;
		break;
	case 5:
		sum = 120;
		break;
	case 6:
		sum = 151;
		break;
	case 7:
		sum = 181;
		break;
	case 8:
		sum = 212;
		break;
	case 9:
		sum = 243;
		break;
	case 10:
		sum = 273;
		break;
	case 11:
		sum = 304;
		break;
	case 12:
		sum = 334;
		break;
	default:
		printf("enter error!!\n");
		break;
	}
	sum += day;
	if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)&&month>2)
	{
		sum++;//当是闰年并且大于二月时，二月的天数会加1；
	}
	printf("这是这一年的%d天\n", sum);
	system("pause");
	return 0;
}