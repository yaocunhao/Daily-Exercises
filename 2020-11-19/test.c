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
			printf("要不要再来一次？\n");
			break;
		case 2:
			printf("拜拜！\n");
			quit = 1;
			break;
		default:
			printf("输入有误，请从新输入！\n");
			break;

		}
	}
    system("pause");
	return 0;
}