#include <stdio.h>
#include <windows.h>
//�������ͼ��������c����������
Prin()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%c%c",177, 176,178,219);
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