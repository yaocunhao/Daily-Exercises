#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
int ComChar(const void *_x, const void *_y)
{
	char *x = *(char**)_x;//�����������ַ����ĵ�ַ������Ƕ���ָ�룬
	char *y = *(char**)_y;//��Ҫ�����ַ����ĵ�ַ���ٽ�����
	return strcmp(x, y);
}
Prin(char *str[], int num)
{
	for(int i = 0; i < num; i++)
	{
		printf("%s\n", str[i]);
	}
	printf("\n");
}
int main()
{
	char *str[] = { "a1231", "ab1353", "122", "f15" };
	int num = sizeof(str) / sizeof(str[0]);
	Prin(str, num);
	qsort(str,num,sizeof(char*),ComChar);
	Prin(str, num);
	system("pause");
	return 0;
}