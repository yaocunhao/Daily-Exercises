//һ��������������100����һ����ȫƽ�������ټ���168����һ����ȫƽ���������ʸ����Ƕ��٣�
//��ȫƽ������һ��������һ����������ƽ��
//˼·�� x+100=n*2;x+100+168=m*2;  -> m>n;
//m+n=i,m-n=j, i*j=168 ,i j����һ����ż��
//m=(i+j)/2,n=(i-j)/2 ->i>j,�� i,j ��Ϊż�����桢j>=2,i<168/2+1��
#include <stdio.h>
#include <windows.h>
#include <math.h>

int main()
{
	int i, j, x, m, n;
	for (i = 1; i < 168 / 2 + 1; i++)
	{
		if (168 % i == 0)
		{
			j = 168 / i;
			if (i>j && (i + j) % 2 == 0 && (i - j) % 2 == 0)
			{
				m = (i + j) / 2;
				n = (i - j) / 2;
				x = n*n - 100;
				printf("%d+100=%d*%d\n", x, n, n);
				printf("%d+268=%d*%d\n", x, m, m);
			}
			
		}
	}
	
	system("pause");
	return 0;
}
