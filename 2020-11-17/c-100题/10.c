#include <stdio.h>
#include <windows.h>
//��ӡ¥�ݣ�ͬʱ��¥���Ϸ���ӡ����Ц����

Prin()
{
	printf("%c%c",148,148);
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < i; j++)
		{
			printf("%c",178);
		}
		printf("\n");
	}
}
int main()
{
	SetConsoleOutputCP(437);
	Prin();
	system("pause");
	return 0;
}