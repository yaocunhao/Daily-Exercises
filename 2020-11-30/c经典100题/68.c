#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//�����������ļ�A��B,�����һ����ĸ��
//Ҫ����������ļ��е���Ϣ�ϲ�������ĸ˳�����У��������һ�����ļ�C�С�
int main()
{
	FILE *fp = fopen("code.log", "r");
	FILE *fp2 = fopen("code2.log", "r");
	FILE *fp3 = fopen("code3.log", "w");
	char str[50];
	char dst[50];
	fgets(str, sizeof(str), fp);
	fgets(dst, sizeof(dst), fp2);
	strcat(str, dst);
	fputs(str, fp3);
	fclose(fp2);
	fclose(fp);
	fclose(fp3);
	system("pause");
	return 0;
}