#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//���������������Ƕ������ɴ��⣺ѧϰ�ɼ�> = 90�ֵ�ͬѧ��A��ʾ��60-89��֮�����B��ʾ��60�����µ���C��ʾ��
char  Score(int num)
{
	return num >= 90 ? 'A' : (num >= 60 ? 'B': 'C');
}

int main()
{
	int num = 0;
	printf("������ɼ�\n");
	scanf("%d", &num);
	char result=Score(num);
	printf("%c\n", result);
	system("pause");
	return 0;
}