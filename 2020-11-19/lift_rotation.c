#include <stdio.h>
#include <windows.h>
#pragma warning(disable :4996)
//ʵ��һ�����������������ַ����е�k���ַ���
//˼·���Ƚ�ȡ��K��λ�ã���ƴ��K����ĸ

int main()
{
	char str[64];
	char dst[64];
	int k = 0;
	printf("��������Ҫ�������ַ���\n");
		scanf("%s", str);
		printf("��������Ҫ���������ַ�\n");
			scanf("%d", &k);
			strcpy(dst, (str + k));//��ȡ��K��λ��
			strncat(dst, str, k);//ƴ��K����ĸ
			printf("����֮ǰ���ַ�����%s,����%d���ַ�����ַ�����%s", str, k, dst);
	system("pause");
	return 0;
}