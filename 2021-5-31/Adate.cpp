#include <iostream>
using namespace std;
//1.要记录每个月的第一天是星期几
//2.然后往后推移，对应的天数，进行输出

//边界问题： 星期一到下个星期一 +7天
//确定某一年的1月1号是星期几

// 2014-1-1是星期三

void Judge(int year, int &week)//求出当前年份的一月一号是星期几
{
	int year2 = 2014;
	int num = 0;
	if (year>year2)//当前所求年> 2014
	{
		int day = 0;
		while (year2<year)
		{
			if ((year2 % 4 == 0 && year2 % 100 != 0) || year2 % 400 == 0)//四年一润，百年不润
				day += 366;
			else
				day += 365;

			year2++;
		}
		//求出了当前年份距离2014有多少天

		week = 3;//2014.1.1为星期三 
		day %= 7;

		while (day)
		{
			week++;
			if (week == 8)
				week = 1;
			day--;
		}
	}
	else if (year<year2)
	{
		int day = 0;
		while (year<year2)
		{
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)//闰年366天
				day += 366;
			else//平年365天
				day += 365;

			year++;
		}

		week = 3;//2014年的一月一号为星期三
		day %= 7;

		while (day)
		{
			week--;
			if (week == 0)
				week = 7;
			day--;
		}
	}
	else//相等
		week = 3;
}


int GetDay(int year, int month)
{
	int day[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		return day[month] + 1;
	else
		return day[month];
}

int GetWeek(int week, int _week)//判断剩余的一周还有多少天到达目的天数
{
	int day = 0;
	while (week != _week)
	{
		day++;
		week++;
		if (week == 8)
			week = 1;
	}
	return day;
}

int GetOneDay(int day, int week)//求出每一个月的第一天是星期几
{
	day %= 7;
	while (day)
	{
		week++;
		if (week == 8)
			week = 1;
		day--;
	}
	return week;
}

int main()
{
	int year;
	while (cin >> year)
	{
		int week = 0;
		Judge(year, week);//得到year的一月一号是星期几
		printf("%d-%02d-%02d\n", year, 1, 1);//元旦

		//1月

		printf("%d-%02d-%02d\n", year, 1, 1 + 14 + GetWeek(week, 1));//先加上两周再判断


		//2月
		//求出二月的第一天是星期几
		int day2 = 0;//求出当前1.1距离当前月份的距离
		day2 = GetDay(year, 1);
		int week2 = GetOneDay(day2, week);//得到2月份的第一天是星期几
		printf("%d-%02d-%02d\n", year, 2, 1 + 14 + GetWeek(week2, 1));//先加上两周，再判断



		//5月
		int day5 = 0;
		for (int i = 1; i<5; i++)
		{
			day5 += GetDay(year, i);//得到5月距离一月有多少天       
		}

		int week5 = GetOneDay(day5, week);//得到5月的第一天是星期几

		if (week5 == 1||(week5>=6&&week5<=7))//先加上4周
			printf("%d-%02d-%02d\n", year, 5, 1 +28+ GetWeek(week5,1));
		else//先加上3周
			printf("%d-%02d-%02d\n", year, 5, 1 + 21 + GetWeek(week5, 1));


		//7月.4
		printf("%d-%02d-%02d\n", year, 7, 4);

		//9月
		int day9 = 0;
		for (int i = 1; i<9; i++)
		{
			day9 += GetDay(year, i);//得到9月距离一月有多少天       
		}
		int week9 = GetOneDay(day9, week);//得到9月的第一天是星期几
		printf("%d-%02d-%02d\n", year, 9, 1 + GetWeek(week9, 1));//直接进行判断



		//11月
		int day11 = 0;
		for (int i = 1; i<11; i++)
		{
			day11 += GetDay(year, i);//得到11月距离一月有多少天       
		}
		int week11 = GetOneDay(day11, week);//得到11月的第一天是星期几
		printf("%d-%02d-%02d\n", year, 11, 1 + 21 + GetWeek(week11, 4));//先加上3周


		//12月.25
		printf("%d-%02d-%02d\n", year, 12, 25);

		printf("\n");
	}




	return 0;
}


