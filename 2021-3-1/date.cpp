#include "date.h"


int Date:: GetMonthDay(int year, int month)//��ȡĳ��ĳ�µ�����
{
	//һ��12���£�����2�·������·ݵ������ǹ̶��ģ���˶���һ����������������
	//��static��ԭ���ǻ��ε��ã�����static��ɱ������ھ�̬�����棬����Ҫ�ظ�����
	static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (month != 2)
	{
		return days[month];
	}
	else
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)//4��һ���Ұ��겻��400����������2�¶�1��
		{
			return 29;
		}
		return 28;
	}
}

Date::Date(int year, int month, int day)//ȫȱʡ���캯��
{
	_year = year;
	_month = month;
	_day = day;
	if (!(year > 0 && month >= 0 && month < 13 && day<=GetMonthDay(year, month)))//�ж��������Ƿ�Ϸ�
	{
		cout << "���ڷǷ�" << endl;
	}
}

void Date::Print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

Date::Date(const Date &d)//��������
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

Date &Date::operator=(const Date &d)//��ֵ�����
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	return *this;//d1=d2,���ص���d1������
}

Date &Date::operator+=(int day)//����+=����
{
	if (day<0)
	{
		return *this -= -day;//��һ�����������������-�����ľ���ֵ
	}

	_day += day;
	while (_day > GetMonthDay(_year, _month))//�Ƚ�����ȫ������һ���ٽ����ж�
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month > 12)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;//������������
}

Date Date::operator+(int day)//����+����
{
	//Date ret(*this);//���ÿ������캯��
	//ret._day += day;

	//while (ret._day > GetMonthDay(ret._year, ret._month))//�Ƚ�����ȫ������һ���ٽ����ж�
	//{
	//	ret._day -= GetMonthDay(ret._year, ret._month);
	//	ret._month++;
	//	if (ret._month > 12)
	//	{
	//		ret._year++;
	//		ret._month = 1;
	//	}
	//}

	//return ret;//���ܷ������ã�����һ����ʱ����������������ͻᱻ����

	//������������������+=���ƣ���������±仯
	Date ret(*this);
	ret += day;
	return ret;
}

Date Date::operator-(int day)//����-����
{
	Date ret(*this);
	if (day < 0)//������=+��������ľ���ֵ
	{
		return ret += day;
	}
	ret._day -= day;//������������һ������ǰ��λ

	while (ret._day<=0)//����С�ڵ���0������Ҫ��ǰ��
	{
		ret._month--;//��һλ
		ret._day += GetMonthDay(ret._year, ret._month);

		if (ret._month == 0)
		{
			ret._month = 12;//�����һ���12�·�
			ret._year--;
		}
		if (ret._year < 0)
		{
			cout << "���ڴ���" << endl;
			break;
		}
	}
	return ret;

}
Date &Date::operator-=(int day)//����-=����
{
	//-=��-���߼�ͬ������

	*this = *this - day;

	return *this;
}

//Ϊ������ǰ��++�ͺ���++�����غ���������++�Ĳ������и�int��
//int���������������ֵ����Ϊ����ֻ�����������������غ���
Date &Date::operator++()//ǰ��++  
{
	//ֱ�������Ѿ�д�õķ������غ���
	*this += 1;
	return *this;//ǰ��++����������
}

Date Date::operator++(int)//����++
{
	Date ret(*this);//����һ��
	*this += 1;

	return ret;//����++��������ǰ�ı��ݣ���ʱ�������ܷ�������
}

Date Date::operator--(int)//����--
{
	Date ret(*this);
	*this -= 1;

	return ret;
}

Date &Date::operator--()//ǰ��--
{
	*this -= 1;
	return *this;
}

//���������
bool Date::operator>(const Date &d)//>���������
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

bool Date::operator==(const Date &d)//==���������
{
	if (_year == d._year&&_month == d._month&&_day == d._day)
		return true;
	return false;
}
bool Date::operator>=(const Date &d)//>=���������
{
	if (*this > d || *this == d)//ֱ������ǰ��ĺ���
		return true;
	return false;
}
bool Date::operator<(const Date &d)//<���������
{
	if (!(*this >= d))
		return true;
	return false;
}
bool Date::operator<=(const Date &d)//<=���������
{
	if (!(*this>d))
		return true;
	return false;
}
bool Date::operator!=(const Date &d)//!=���������
{
	if (!(*this == d))
		return true;
	return false;
}


int Date::operator-(const Date &d)//����-���ڣ���������
{
	Date max = *this;
	Date min = d;

	int flag = 1;
	if (max < min)
	{
		max = d;
		min = *this;//��������
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