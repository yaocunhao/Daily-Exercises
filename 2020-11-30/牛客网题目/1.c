#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
#include <string.h>
//��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20��
//���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��

int main()
{	
	char str[20]="we are happy";
	printf("������һ���ַ���\n");
	gets(str);
	char *dst;
	dst= strstr(str, " ");
	strncpy(dst, "%20", 3);
	while (dst)
	{
		if (dst = strstr(dst, " "))
		{
			strncpy(dst, "%20", 3);
		}
	}
	puts(str);

	







	
	system("pause");
	return 0;
}