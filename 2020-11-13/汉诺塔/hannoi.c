#include<stdio.h>
#include <windows.h>
#pragma warning (disable:4996)

//有三根棒为A、B、C。A棒上叠放着n个大小不等的盘，依次叠加为大盘在下，小盘在下。要求把这n个盘移到C棒上，\
在移动过程中可以借助B棒，每次只能移一个盘，\
并且在移动过程中必须保持3根棒上的大盘在上，小盘在下。编写程序，并打印出移盘步骤。

void Prinmove(int num,char a,char b)
{
	printf("%d盘：%c->%c\n",num,a,b);
}

void Move(int num,char A,char B,char C) //三根柱子 A,B,C
{
	if (num == 1) //当n=1，直接从A->c
	{
		Prinmove(num,A, C);
		return;
	}
	else
		Move(num - 1, A,C,B);//将（n-1）放在B柱子上
		Prinmove(num,A, C);//将第n个放在C上
		Move(num - 1, B, A, C);//再将（n-1）个从B放到C
}

int main()
{
	int num = 0;
	printf("请输盘数\n");
	scanf("%d", &num);
	Move(num,'A','B','C');
	system("pause");
	return 0;
}