#include <stdio.h>
#include <windows.h>

int strToInt(char* str){
	int num = 0;
	int count = 1;
	int flag = 1;
	while (*str == ' ')
	{
		str++;//ɸ���հ�
	}


	if (*str != '+' && *str != '-' && *str - '0'>9)//��һ���ַ�������Ч�ַ�,ע���ַ����е�����Ϊ�ַ�
		return 0;

	if (*str == '-')
	{
		flag = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}

	while (*str != '\0'&&*str - '0'<10 && *str - '0'>0)//��֤Ϊ��Ч�ַ�
	{
		num = num*count + (*str - '0');
		str++;
		if (count == 1)
			count *= 10;
	}
	num *= flag;
	return num;

}

int main()
{
	char *s = " -91283472332";
	int result = strToInt(s);
	printf("%d\n", result);

	system("pause");
	return 0;
}