#include "game.h"
int main()
{
	int quit = 0;
	int num = 0;
	while (!quit)
	{
		Menu();
		printf("请输入您的选择\n");
		scanf("%d", &num);
		switch (num)
		{
	case 1://游戏开始；
		Game();
		break;
	case 2:
		quit = 1;
		printf("游戏愉快，下次再见！\n");
		break;
	default:
		printf("输入有误,请从新输入！\n");
		break;
		}
	}

    system("pause");
	return 0;
}