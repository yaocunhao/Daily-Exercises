#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>
using namespace std;

class Date
{
public:
	int GetMonthDay(int year, int month);//获取某年某月的天数

	Date(int year = 1999, int month = 1, int day = 1);//全缺省构造函数

	void Print();//打印函数；

	Date(const Date &d);//拷贝函数

	//~Date();//析构函数，Date类不需要自己写析构函数

	//赋值运算符重载
	Date &operator=(const Date &d);//赋值运算符重载
	Date &operator+=(int day);//日期+=天数
	Date operator+(int day);//日期+天数
	Date operator-(int day);//日期-天数
	Date &operator-=(int day);//日期-=天数
	Date &operator++();//前置++
	Date operator++(int);//后置++
	Date operator--(int);//后置--
	Date &operator--();//前置--

	//运算符重载
	bool operator>(const Date &d);//>运算符重载
	bool operator==(const Date &d);//==运算符重载
	bool operator>=(const Date &d);//>=运算符重载
	bool operator<(const Date &d);//<运算符重载
	bool operator<=(const Date &d);//<=运算符重载
	bool operator!=(const Date &d);//!=运算符重载

	int operator-(const Date &d);//日期-日期，返回天

private:
	int _year;
	int _month;
	int _day;
};


#endif