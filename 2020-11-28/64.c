#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//�Ӽ�������һЩ�ַ�������������͵�������ȥ��ֱ������һ��#Ϊֹ��
int main()
{
	FILE *fp = fopen("rest.log", "w");
	int c = 0;
	printf("�������ַ���#����\n");
	while ((c = fgetc(stdin) )!= '#')
	{
		fputc(c, fp);
		fseek(fp, 0, SEEK_END);
	}
	fclose(fp);
	system("pause");
	return 0;
}