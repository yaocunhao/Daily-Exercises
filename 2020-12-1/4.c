#include <stdio.h>
#include <windows.h>
//��һ���ַ���(0<=�ַ�������<=10000��ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,
//����������λ��, ���û���򷵻� -1����Ҫ���ִ�Сд��.����0��ʼ������

int String(char str[])
{
	int size = strlen(str);
	int ch = 0;
	char *dst = str;
	while (*dst)
	{
		int count = 0;
		ch = *dst;
		for (int i = 0; i < size; i++)
		{
			if (ch == str[i])
			{
				count++;
			}
		}
		if (count == 1)
		{
			for (int j = 0; j < size; j++)
			{
				
				if (ch == str[j])
				{
					return j;
				}
			}
		}
		dst++;
	}
	return -1;
}

int main()
{
	char str[] = "abacdef";
	int ret=String(str);
	if (ret!=-1)
	printf("%c", str[ret]);
	system("pause");
	return 0;
}