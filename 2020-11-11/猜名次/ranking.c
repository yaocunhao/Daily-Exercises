//5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ����������
//Aѡ��˵��B�ڶ����ҵ�����Bѡ��˵���ҵڶ���E���ģ�Cѡ��˵���ҵ�һ��D�ڶ���Dѡ��˵��C����ҵ�����
//Eѡ��˵���ҵ��ģ�A��һ������������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�
#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

char Judge(int *p)//�ж������η��ظ�
{
	char t = 0;
	for (int i = 0; i < 5; i++)
	{
		t |= 1 << p[i];
	}
	return t == 0x3e;
}

void Ranking(int *p,int n)
{
	if (n >= 5)
	{
		if (((p[1] == 2) + (p[0] == 3) == 1) && ((p[1] == 2) + (p[4] == 4) == 1)\
			&& ((p[2] == 1) + (p[3] == 2) == 1) && ((p[2] == 5) + (p[3] == 3) == 1)\
			&& ((p[4] == 4) + (p[0] == 1) == 1) && Judge(p))
		{
			for (int i = 0; i < 5; i++)
			{
				printf("%cѡ�ֵ�������%d\n", i + 'A', p[i]);
			}
		}
		return;
	}
	for (p[n] = 1; p[n] < 6; p[n]++) //��Ҫ����5x5�Σ��õݹ�������ࣻ
	{
		Ranking(p,n+1);
	}
}

int main()
{
	int p[5];
	Ranking(p,0);
	system("pause");
	return;	
}
