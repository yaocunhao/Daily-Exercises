//����ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿
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
	printf("�����������գ���ʽΪ���꣬�£���\n");
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
		sum++;//�������겢�Ҵ��ڶ���ʱ�����µ��������1��
	}
	printf("������һ���%d��\n", sum);
	system("pause");
	return 0;
}