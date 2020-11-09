#include "game.h"
void Menu()
{
	printf("#########################\n");
	printf("##1.start#####2.end######\n");
	printf("#########################\n");
}
#define RANGE 100
void Game()
{
	int a = 0;
	srand ((unsigned long)time(NULL));// 给予一个数字库
	int c = rand() % RANGE + 1;//给定一个猜测的范围
	while (1)
	{
		printf("请输入你猜测的数字\n");
		scanf("%d", &a);
		if (a > c)
		{
			printf("猜大了\n");
		}
		else if (a < c)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("恭喜你，猜对了！");
			break;
		}
	}


}