#include <stdio.h>
#include <windows.h>
//��5��������һ���ʵ�����˶����ꣿ��˵�ȵ�4���˴�2�ꡣ�ʵ�4������������˵�ȵ�3���˴�2�ꡣ
//�ʵ������ˣ���˵�ȵ�2�˴����ꡣ�ʵ�2���ˣ�˵�ȵ�һ���˴����ꡣ����ʵ�һ���ˣ���˵��10�ꡣ���ʵ�����˶��

int FiveAge(int num)
{
	if (num == 1)
		return 10;
	return 2 + FiveAge(num - 1);
}

int main()
{
	int age=FiveAge(5);
	printf("%d\n", age);
	system("pause");
	return 0;
}