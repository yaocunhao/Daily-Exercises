#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//��ֻ����������2��3��5��������������Ugly Number����
//����6��8���ǳ�������14���ǣ���Ϊ������������7�� ϰ�������ǰ�1�����ǵ�һ���������󰴴�С�����˳��ĵ�N������

int UglyNum(int n)
{/*
	int count = 1;
	int i = 2;
	if (n == 1)
	{
		return 1;
	}
	while (i)
	{
		if (i % 7 != 0)
		{
			count++;
		}
		if (count == n)
		{
			return i;
		}
		i++;
		
	}
	return 0;*/
	int count = 1;
	int i = 2;
	if (n == 1)
		return 1;
	while (i)
	{
		if (i % 7 != 0)
		{
			count++;
		}
		if (count == n)
		{
			return i;
		}
		i++;
	}
	return 0;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d\n",UglyNum(n));
	system("pause");
	return 0;
}