#include<stdio.h>
#include <windows.h>
#pragma warning (disable:4996)

//��������ΪA��B��C��A���ϵ�����n����С���ȵ��̣����ε���Ϊ�������£�С�����¡�Ҫ�����n�����Ƶ�C���ϣ�\
���ƶ������п��Խ���B����ÿ��ֻ����һ���̣�\
�������ƶ������б��뱣��3�����ϵĴ������ϣ�С�����¡���д���򣬲���ӡ�����̲��衣

void Prinmove(int num,char a,char b)
{
	printf("%d�̣�%c->%c\n",num,a,b);
}

void Move(int num,char A,char B,char C) //�������� A,B,C
{
	if (num == 1) //��n=1��ֱ�Ӵ�A->c
	{
		Prinmove(num,A, C);
		return;
	}
	else
		Move(num - 1, A,C,B);//����n-1������B������
		Prinmove(num,A, C);//����n������C��
		Move(num - 1, B, A, C);//�ٽ���n-1������B�ŵ�C
}

int main()
{
	int num = 0;
	printf("��������\n");
	scanf("%d", &num);
	Move(num,'A','B','C');
	system("pause");
	return 0;
}