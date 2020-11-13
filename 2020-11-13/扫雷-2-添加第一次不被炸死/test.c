#include "game.h"

int main()
{
	int select = 0;
	int quit = 0;
	while(!quit)
	{
		Menu();
		printf("请做出你的选择\n");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("欢迎来到游戏\n");
			Login();
			Game();
			printf("需要再来一把吗？\n");
			break;
		case 2:
			printf("期待您的下次到来\n");
			quit = 1;
			break;
		default:
			printf("输入有误，请从新输入");
		}
	}
	system("pause");
	return 0;
}