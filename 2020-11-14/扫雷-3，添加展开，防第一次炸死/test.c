#include "game.h"

int main()
{
	//Login();
	int select = 0;
	int quit = 0;
	while(!quit)
	{
		Menu();
		printf("���������ѡ��\n");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("��ӭ������Ϸ\n");
			Game();
			printf("��Ҫ����һ����\n");
			break;
		case 2:
			printf("�ڴ������´ε���\n");
			quit = 1;
			break;
		default:
			printf("�����������������");
		}
	}
	system("pause");
	return 0;
}