#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
 void Splicing(char spl[])
{
	strncat(spl, spl,strlen(spl));//����ƴ��
}
int main()
{
	char str[64];
	char dst[64];
	char spl[64];
	printf("������ԭ�ַ���\n");
	gets(str);
	strcpy(spl,str);//�����ַ���
	Splicing(spl);
	printf("������ԭ��Ҫ�Ƚϵ��ַ���\n");
	gets(dst);
	char *p = strstr(spl, dst);//�����ִ����Ҳ�������ֵΪ��
	if (p!=NULL)
	{
		printf("%s��%s��ת֮����ַ���\n",dst,str);
	}
	else
		printf("%s����%s��ת֮����ַ���\n", dst, str);
	

	
	system("pause");
	return 0;
}