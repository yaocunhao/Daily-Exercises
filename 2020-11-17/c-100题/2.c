//��ҵ���ŵĽ������������ɡ�
//����(I)���ڻ����10��Ԫʱ���������10%��
//�������10��Ԫ������20��Ԫʱ������10��Ԫ�Ĳ��ְ�10%��ɣ�����10��Ԫ�Ĳ��֣������7.5%��
//20��40��֮��ʱ������20��Ԫ�Ĳ��֣������5%��
//40��60��֮��ʱ����40��Ԫ�Ĳ��֣������3%��
//60��100��֮��ʱ������60��Ԫ�Ĳ��֣������1.5%��
//����100��Ԫʱ������100��Ԫ�Ĳ��ְ�1%��ɡ�
//�Ӽ������뵱������I����Ӧ���Ž���������
#include<stdio.h>
#include <windows.h>
#pragma warning (disable :4996)

void Bonus()
{
	double i= 0;
	printf("�����뵱�µ�����\n");
	scanf("%lf", &i);
	double bonus1 = 10* 0.1;
	double bonus2 = bonus1 + 0.075*(i-10);
	double bonus3 = bonus2 + 0.075*(i - 20);
	double bonus4 = bonus3 + 0.03*(i - 40);
	double bonus5 = bonus4 + 0.015*(i - 60);
	double bonus6 = bonus5 + 0.01*(i - 100);
	if (i <= 10)
	{
		printf("�㵱�µĽ���Ϊ%lf��Ԫ\n", i*0.1);
	}
	else if (i>10&&i<=20)
	{
		printf("�㵱�µĽ���Ϊ%lf��Ԫ\n", bonus2);
	}
	else if (i>20&&i<=40)
	{
		printf("�㵱�µĽ���Ϊ%lf\n��Ԫ", bonus3);
	}
	else if (i>40&&i<=60)
	{
		printf("�㵱�µĽ���Ϊ%lf\n��Ԫ", bonus4);
	}
	else if (i>60&&i<=100)
	{
		printf("�㵱�µĽ���Ϊ%lf\n��Ԫ", bonus5);
	}
	else 
	{
		printf("�㵱�µĽ���Ϊ%lf\n��Ԫ", bonus6);
	}
}
int main()
{
	Bonus();
	system("pause");
	return 0;
}