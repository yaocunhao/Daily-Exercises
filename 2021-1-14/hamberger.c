#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//�Ժ�����hungry���������Ƿ񼢶�������ֵ���߼�ֵ
int Hungry(int n)
{
	if (n >= 0)
		return 0;
	else
		return 1;
}
void eat_hamberger(int n)
{
		int count = 0;
		while (n)
		{
			count++;
			printf("��ǰ����%d��\n", count);
			n++;
		}

}
int main()
{
	int count = 0;
	int hungry = 0;
	printf("�������㵱ǰ�ļ���ֵ");
	scanf("%d", &hungry);
	if (Hungry(hungry))
	{
	eat_hamberger(hungry);
	}
	else
	{
		printf("�����һ������");
	}



	system("pause");
	return 0;
}