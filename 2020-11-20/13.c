#include <stdio.h>
#include <windows.h>
#include <math.h>
//��ӡ�����е�"ˮ�ɻ���"����ν"ˮ�ɻ���"��ָһ����λ�������λ���������͵��ڸ�������
//���磺153��һ��"ˮ�ɻ���"����Ϊ153=1�����η���5�����η���3�����η���
void DaffodilNum()
{
	int i = 0;
	while (i < 100000)
	{
		int t = i;
		int count = 0;
		int result = 0;
		while (t)//�����ж���λ��;
		{
			count++;
			t /= 10;
		}
		t = i;
		while (t)//ÿλ���Ĵη������;
		{
			result += pow((t % 10), count);
			t /= 10;
		}
		if (result == i)
			printf("%d is daffodil number!\n",i);
		i++;
	}
}
int main()
{
	DaffodilNum();
	system("pause");
	return 0;
}