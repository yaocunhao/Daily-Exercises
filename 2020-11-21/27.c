#include <stdio.h>
#include <windows.h>
#pragma warning(disable :4996)
//�����õݹ麯�����÷�ʽ�����������5���ַ������෴˳���ӡ������
int ReversePrin(char str[])
{
	if (*str== 0)
	{
		return 0;
	}
    ReversePrin(str + 1);
	printf("%c\n", *str);
	return 0;
	
}

int main()
{
	char str[6];
	printf("�������ַ�\n");
	scanf("%s", str);
	ReversePrin(str);
	system("pause");
	return 0;
}