#include <stdio.h>
#include <windows.h>
//���ӳ������⣺���ӵ�һ��ժ�����ɸ����ӣ���������һ�룬����񫣬�ֶ����һ��
//�ڶ��������ֽ�ʣ�µ����ӳԵ�һ�룬�ֶ����һ����
//�Ժ�ÿ�����϶�����ǰһ��ʣ�µ�һ����һ��������10���������ٳ�ʱ����ֻʣ��һ�������ˡ����һ�칲ժ�˶��١�
int  Monkey(int day)
{
	if (day == 10)
		return 1;
	else
		return 2 * (1 + Monkey(day + 1));
}

int main()
{
	printf("��һ�칲ժ��%d��\n", Monkey(1));
	system("pause");
	return 0;
}