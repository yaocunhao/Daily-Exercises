#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996 )
#include <time.h>
//������Ϸ��
void Guess_game(int n)
{
	int quit = 0;
	while (!quit)
	{
		int num = 0;
		printf("������0-100������\n");
		scanf("%d", &num);
		if (num < n)
			printf("��С��\n");
		else if (num>n)
			printf("�´���\n");
		else
		{
			printf("��ϲ�㣬�¶���\n");
			quit = 1;
		}
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int n = rand() % 100 + 1;
	Guess_game(n);
	system("pause");
	return 0;
}