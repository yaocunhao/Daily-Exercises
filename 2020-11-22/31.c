#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//���������ڼ��ĵ�һ����ĸ���ж�һ�������ڼ��������һ����ĸһ����������жϵڶ�����ĸ��

void Day()
{
	char i = 0;
	char j = 0;
	printf("�������һ����ĸ\n");
	scanf("%c", &i);
	getchar();//�ٵ�scanf�����Ŀո�
	switch (i)
	{
	case 'm':
		printf("��������1\n");
		break;
	case 'w':
		printf("��������3\n");
		break;
	case 'f':
		printf("��������5\n");
		break;
	case 't':
		printf("������ڶ����ַ�\n");
		scanf("%c", &j);
		switch (j)
		{
		case 'h':
			printf("��������4\n");
			break;
		case 'u':
			printf("��������2\n");
			break;
		default:
			printf("��������\n");
			break;
		}
		break;
	case 's':
		printf("������ڶ����ַ�\n");
		scanf("%c", &j);
		switch (j)
		{
		case 'a':
			printf("��������7\n");
			break;
		case 'u':
			printf("��������6\n");
			break;
		default:
			printf("��������\n");
			break;
		}
		break;
	default:
		printf("��������\n");
		break;
	}

}
int main()
{
	Day();
	system("pause");
	return 0;
}