#include <stdio.h>
#include <windows.h>
//�ŵ����⣨�������̣�����һ�����ӣ��ӳ������3������ÿ���¶���һ�����ӣ�
//С���ӳ����������º�ÿ��������һ�����ӣ��������Ӷ���������ÿ���µ���������Ϊ���٣������ǰ40���¼��ɣ�
//˼·: ���ӹ����� 1 1 2 3 5 8 13����3������ ��ǰ��������֮��
int RabbitNum(int num)
{
	if (num < 3)
		return 1;
	else
		return RabbitNum(num - 1) + RabbitNum(num - 2);
}
int main()
{
	for (int i = 1; i < 41; i++)
	{
		int ret = RabbitNum(i);
		printf("��%d���µ�����������%d\n", i, ret * 2);
	}
	system("pause");
	return 0;
}