#include <stdio.h>
#include <windows.h>
//һ���100�׸߶��������£�ÿ����غ�����ԭ�߶ȵ�һ��;
//�����£������ڵ�10�����ʱ�������������׵�10�η�����ߣ�
void Ball()
{
	double m = 100;
	double ret = 0;
	for (int i = 0; i < 10; i++)
	{
		ret += (m + m / 2);//�ܹ����������ף�
		m /= 2;
	}
	printf("��ʮ������ܹ�����%lf�ף���ʮ�η���%lf��\n",ret-m,m);
}
int main()
{
	
	Ball();
	system("pause");
	return 0;
}