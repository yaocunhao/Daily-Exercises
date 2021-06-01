#include <iostream>
using namespace std;

int Getday(int year, int month)
{
	int arr[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		return 29;
	else
		return arr[month];
}

bool GetMoney(int month)
{
	if (month <= 1)
		return false;

	for (int i = 2; i<month; i++)
	{
		if (month%i == 0)
			return false;//不是素数
	}
	return true;
}


int main()
{
	int year1, year2;
	int month1, month2;
	int day1, day2;
	int money = 0;//平年一年能赚多少钱(闰年多一块)
	for (int i = 1; i<13; i++)
	{
		if (!GetMoney(i))//不是素数赚2块
		{
			money += (Getday(2013, i) * 2);
		}
		else
			money += Getday(2013, i);
	}


	while (cin >> year1 >> month1 >> day1)
	{
		cin >> year2 >> month2 >> day2;

		int count = 0;

			int _year = year1;

			if (year1 != year2)
			{
				while (year1 != year2)//先把年份调到位
				{
					count += money;
					if ((year1 % 4 == 0 && year1 % 100 != 0) || year1 % 400 == 0)//润年多赚一块
						count++;

					year1++;
				}

				//调年份多赚了月钱
				for (int i = 1; i<month1; i++)
				{
					if (!GetMoney(i))//不是素数赚2块
						count -= (Getday(_year, i) * 2);
					else
						count -= Getday(_year, i);
				}
				//多赚了天钱
				if (day1!=1&&!GetMoney(month1))
				{
					for (int i = 0; i<=day1; i++)
					{
						count -= 2;
					}
				}
				else
				{
					for (int i = 0; i<=day1; i++)
					{
						count -= 1;
					}
				}
			}

			//到此，年份是相同的
			if (_year == year2)//年份本来就是相同的
			{
				if (!GetMoney(month1))
					count += 2;
				else
					count += 1;
				while (month1<month2 || day1 != day2)
				{
					if (!GetMoney(month1))
						count += 2;
					else
						count += 1;
					day1++;

					if (month1 == month2&&day1 == day2)
						break;

					if (day1>Getday(year1, month1))
					{
						day1 = 1;
						month1++;
					}
				}
				
			}
			else//年份不相同，则从1月1开始赚前
			{
				for (int i = 1; i<month2; i++)//月份钱
				{
					if (!GetMoney(i))
						count += 2 * Getday(year2, i);
					else
						count += Getday(year2, i);
				}
				for (int i = 0; i<=day2; i++)//日子前
				{
					if (!GetMoney(month2))
						count += 2;
					else
						count += 1;
				}
			}

		//}//小判断循环

		cout << count << endl;


	}//大输入循环
	return 0;
}