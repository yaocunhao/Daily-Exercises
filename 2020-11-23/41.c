#include <stdio.h>
#include <windows.h>
//ѧϰ��̬���徲̬�������÷���
int main()
{
	for (int i = 0; i < 10; i++)
	{
		static	int j = 0;
		printf("%d\n", j);
		j++;
	}
	system("pause");
	return 0;
}