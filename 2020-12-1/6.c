#include <stdio.h>
#include <windows.h>
//��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯���� 
//��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0

int main()
{
	int ret = 0;
	char str[20];
	fgets(str, sizeof(str)-1, stdin);
	for (int i = 0; i < (signed)strlen(str)-1; i++)
	{
		ret += str[i];
	}
	printf("%d\n",ret);
	system("pause");
	return 0;
}