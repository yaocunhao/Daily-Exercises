//��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����

#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
#include <math.h>

//int Sum(n)  ����1������&&��·ԭ��
//{
//	int x = n > 1 && (n += Sum(n - 1));
//	return n;
//}
//int Sum(n)//����2�����ù�ʽ S=��1+n)*n/2=(n^2+n)/2
//{
//	int ret = (pow(n, 2) + n);
//	ret >>= 1;
//	return ret;
//}
int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d\n",Sum(n));
	system("pause");
	return 0;
}