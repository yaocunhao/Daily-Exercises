#include <stdio.h>
#include <windows.h>
// atoi��������ȡ�ַ������ӵ�һ����Ϊ�ո���ַ���ʼ����,������һ��+����-������
//������һ������ֹͣ��

int my_atoi(const char *str)
{
	int count = 0;
	int flag = 1;
	while (*str == ' ')//�����ո�
	{
		str++;
	}
	if (*str == '+')//������һ������λ
	{
		str++;

		if (*str == '-')//��ֹ��һ��Ϊ��-����
		{
			return 0;
		}
	}
	if (*str == '-')
	{
		flag = -1;//���Ϊ����
		str++;
	}
	while (*str <= '9'&&*str >= '0'&&*str!='\0')//����������û��Խ��
	{
		count = (count * 10 + (*str-48));
		str++;
	}
	count *= flag;//ȷ������
	return count;
}

int main()
{
	char str[] = "     +432sds44";
	printf("%d\n", my_atoi(str));
	system("pause");
	return 0;
}
