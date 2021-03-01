#include "date.h"


int Date:: GetMonthDay(int year, int month)//获取某年某月的天数
{
	//一年12个月，除了2月份其余月份的天数是固定的，因此定义一个数组来保存天数
	//加static的原因是会多次调用，加上static变成变量，在静态区保存，不需要重复定义
	static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (month != 2)
	{
		return days[month];
	}
	else
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)//4年一润且百年不润，400年再润，闰年2月多1天
		{
			return 29;
		}
		return 28;
	}
}

Date::Date(int year, int month, int day)//全缺省构造函数
{
	_year = year;
	_month = month;
	_day = day;
	if (!(year > 0 && month >= 0 && month < 13 && day<=GetMonthDay(year, month)))//判断年月日是否合法
	{
		cout << "日期非法" << endl;
	}
}

void Date::Print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

Date::Date(const Date &d)//拷贝函数
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

Date &Date::operator=(const Date &d)//赋值运算符
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	return *this;//d1=d2,返回的是d1的引用
}

Date &Date::operator+=(int day)//日期+=天数
{
	if (day<0)
	{
		return *this -= -day;//加一个负数，等于这个数-负数的绝对值
	}

	_day += day;
	while (_day > GetMonthDay(_year, _month))//先将天数全部加在一起，再进行判断
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month > 12)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;//返回日期引用
}

Date Date::operator+(int day)//日期+天数
{
	//Date ret(*this);//调用拷贝构造函数
	//ret._day += day;

	//while (ret._day > GetMonthDay(ret._year, ret._month))//先将天数全部加在一起，再进行判断
	//{
	//	ret._day -= GetMonthDay(ret._year, ret._month);
	//	ret._month++;
	//	if (ret._month > 12)
	//	{
	//		ret._year++;
	//		ret._month = 1;
	//	}
	//}

	//return ret;//不能返回引用，这是一个临时变量，出了作用域就会被销毁

	//上述代码和重载运算符+=类似，因此有如下变化
	Date ret(*this);
	ret += day;
	return ret;
}

Date Date::operator-(int day)//日期-天数
{
	Date ret(*this);
	if (day < 0)//减负数=+这个负数的绝对值
	{
		return ret += day;
	}
	ret._day -= day;//天数先运算在一起，再向前借位

	while (ret._day<=0)//天数小于等于0，则需要向前借
	{
		ret._month--;//借一位
		ret._day += GetMonthDay(ret._year, ret._month);

		if (ret._month == 0)
		{
			ret._month = 12;//变成上一年的12月份
			ret._year--;
		}
		if (ret._year < 0)
		{
			cout << "日期错误" << endl;
			break;
		}
	}
	return ret;

}
Date &Date::operator-=(int day)//日期-=天数
{
	//-=和-的逻辑同样类似

	*this = *this - day;

	return *this;
}

//为了区分前置++和后置++的重载函数，后置++的参数中有个int，
//int可以是随意的整形值，因为参数只是用来进行区分重载函数
Date &Date::operator++()//前置++  
{
	//直接利用已经写好的符号重载函数
	*this += 1;
	return *this;//前置++，返回引用
}

Date Date::operator++(int)//后置++
{
	Date ret(*this);//拷贝一份
	*this += 1;

	return ret;//后置++返回自增前的备份，临时变量不能返回引用
}

Date Date::operator--(int)//后置--
{
	Date ret(*this);
	*this -= 1;

	return ret;
}

Date &Date::operator--()//前置--
{
	*this -= 1;
	return *this;
}

//运算符重载
bool Date::operator>(const Date &d)//>运算符重载
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year==d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			if (_day > d._day)
			{
				return true;
			}
		}
	}
	return false;
}

bool Date::operator==(const Date &d)//==运算符重载
{
	if (_year == d._year&&_month == d._month&&_day == d._day)
		return true;
	return false;
}
bool Date::operator>=(const Date &d)//>=运算符重载
{
	if (*this > d || *this == d)//直接利用前面的函数
		return true;
	return false;
}
bool Date::operator<(const Date &d)//<运算符重载
{
	if (!(*this >= d))
		return true;
	return false;
}
bool Date::operator<=(const Date &d)//<=运算符重载
{
	if (!(*this>d))
		return true;
	return false;
}
bool Date::operator!=(const Date &d)//!=运算符重载
{
	if (!(*this == d))
		return true;
	return false;
}


int Date::operator-(const Date &d)//日期-日期，返回天数
{
	Date max = *this;
	Date min = d;

	int flag = 1;
	if (max < min)
	{
		max = d;
		min = *this;//交换过来
		flag = -1;
	}

	int n = 0;
	while (max != min)
	{
		min++;
		n++;
	}
	return n*flag;

}