#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>
using namespace std;

class Date
{
public:
	int GetMonthDay(int year, int month);//��ȡĳ��ĳ�µ�����

	Date(int year = 1999, int month = 1, int day = 1);//ȫȱʡ���캯��

	void Print();//��ӡ������

	Date(const Date &d);//��������

	//~Date();//����������Date�಻��Ҫ�Լ�д��������

	//��ֵ���������
	Date &operator=(const Date &d);//��ֵ���������
	Date &operator+=(int day);//����+=����
	Date operator+(int day);//����+����
	Date operator-(int day);//����-����
	Date &operator-=(int day);//����-=����
	Date &operator++();//ǰ��++
	Date operator++(int);//����++
	Date operator--(int);//����--
	Date &operator--();//ǰ��--

	//���������
	bool operator>(const Date &d);//>���������
	bool operator==(const Date &d);//==���������
	bool operator>=(const Date &d);//>=���������
	bool operator<(const Date &d);//<���������
	bool operator<=(const Date &d);//<=���������
	bool operator!=(const Date &d);//!=���������

	int operator-(const Date &d);//����-���ڣ�������

private:
	int _year;
	int _month;
	int _day;
};


#endif