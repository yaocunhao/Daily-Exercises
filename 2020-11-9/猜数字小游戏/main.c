#include "game.h"
int main()
{
	int quit = 0;
	int num = 0;
	while (!quit)
	{
		Menu();
		printf("����������ѡ��\n");
		scanf("%d", &num);
		switch (num)
		{
	case 1://��Ϸ��ʼ��
		Game();
		break;
	case 2:
		quit = 1;
		printf("��Ϸ��죬�´��ټ���\n");
		break;
	default:
		printf("��������,��������룡\n");
		break;
		}
	}

    system("pause");
	return 0;
}