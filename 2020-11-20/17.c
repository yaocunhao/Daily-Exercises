#include <stdio.h>
#include <windows.h>
//����һ���ַ����ֱ�ͳ�Ƴ�����Ӣ����ĸ���ո����ֺ������ַ��ĸ�����

void Sum()
{
	int num = 0;
	int  c = 0;
	int letter = 0;
	int blank = 0;
	int Else = 0;
	while ((c = getchar()) != '\n')
	{
		if ((c >= 'a'&&c<='z')|| (c>='A'&&c <= 'Z'))
		{
			letter++;
		}
		else if (c == ' ')
		{
			blank++;
		}
		else if (c >= '0'&&c <= '9')
		{
			num++;
		}
		else
		{
			Else++;
		}
	}
	printf("��ĸ����Ϊ%d\n", letter);
	printf("�ո����Ϊ%d\n", blank);
	printf("���ָ���Ϊ%d\n", num);
	printf("��������Ϊ%d\n", Else);
}

int main()
{
	Sum();
	system("pause");
	return 0;
}