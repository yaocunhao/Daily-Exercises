#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996 )
#include <time.h>
//猜谜游戏。
void Guess_game(int n)
{
	int quit = 0;
	while (!quit)
	{
		int num = 0;
		printf("请输入0-100的数字\n");
		scanf("%d", &num);
		if (num < n)
			printf("猜小了\n");
		else if (num>n)
			printf("猜大了\n");
		else
		{
			printf("恭喜你，猜对了\n");
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