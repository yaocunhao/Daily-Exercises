#include <stdio.h>
#include <windows.h>
//Ҫ����������������̡�64������
void Prin()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%c%c",177,219);
		}
		printf("\n");
	}
}
int main()
{
	SetConsoleOutputCP(437);//��ʾ����127��ASCII��
	Prin();
	system("pause");
	return 0;
}



