#include "game.h"
int main()
{
	int quit = 0;
	int select = 0;
	while (!quit)
	{
		Menu();
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			Game();
			printf("Ҫ��Ҫ����һ�Σ�\n");
			break;
		case 2:
			printf("�ݰݣ�\n");
			quit = 1;
			break;
		default:
			printf("����������������룡\n");
			break;

		}
	}
    system("pause");
	return 0;
}