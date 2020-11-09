#include "game.h"


void Menu()
{
	printf("########################\n");
	printf("1.enter###########2.quit\n");
	printf("########################\n");
	printf("请输入您的选择!\n");

}

void ShowBoard(char board[][LINE], int cow, int line)
{
	printf("\n");
	printf("    |  1 |  2 |  3 |\n--------------------\n");
	for (int i = 0; i < cow; i++)
	{
		printf(" %d  |", i + 1);
		for (int j = 0; j < line; j++)
		{
			printf("  %c |", board[i][j]);
		}
		printf("\n--------------------\n");
	}



}


	void Playmove(char board[][LINE], int cow, int line)//玩家落子
	{
		int x = 0;
		int y = 0;
		while (1)
		{
			printf("请输入你的坐标# ");
			scanf("%d %d", &x, &y);
			if (x<1 || x>3 || y<1 || y>3)
			{
				printf("你输入的坐标有误，请从新输入\n");
				continue;
			}
			else if (board[x - 1][y - 1] != ' ')
			{
				printf("你输入的坐标有误，请从新输入\n");
				continue;
			}
			else
			{
				board[x - 1][y - 1] = PLAY;
			}
			break;
		}
	}
 

char Judge(char board[][LINE], int cow, int line)//系统判断棋局情况
{
	for (int i = 0; i < cow; i++)//每行是否一样
	{
		if (board[i][0] == board[i][1] && \
			board[i][1] == board[i][2] && \
			board[i][0] != ' ')
		{
			return board[i][0];
		}

	}

	for (int i = 0; i < line; i++)//每列是否一样
	{
		if (board[0][i] == board[1][i] && \
			board[1][i] == board[2][i] && \
			board[0][i] != ' ')
		{
			return board[0][i];
		}

	}

	if (board[0][0] == board[1][1] && \
		board[1][1] == board[2][2] && \
		board[0][0] != ' ')                    
	{
		return board[0][0];                        //两个对角是否一样
	}

	if (board[0][2] == board[1][1] && \
		board[1][1] == board[2][0] && \
		board[0][2] != ' ')
	{
		return board[0][2];
	}

	for (int i = 0; i < cow; i++)
	{
		for (int j = 0; j < line; j++)               //还有没有空格,有空格则还没下完；
		{
			if (board[i][j] == ' ')
			{
				return NEXT;
			}
		}
	}
	return DRAW;
}


void Compmove(char board[][LINE], int cow, int line)
{
	while (1)
	{
		int x = rand() % cow;
		int y = rand() % line;
		if (board[x][y] == ' ')     //电脑随机落子；
		{
			board[x][y] = COMP;
			break;
		}
	}

}


void Game()
{
	system("cls");
	srand((unsigned)time(NULL));//种下随机数种子，系统随机下棋；
	char board[COW][LINE];//储存棋子，X O；
	memset(board, ' ', sizeof(board));// 将所有所有格子换成空格；
	char result = 'x';
	do
	{
		system("cls");
		ShowBoard(board,COW,LINE);
		Playmove(board,COW,LINE);
		result = Judge(board, COW, LINE);
		if (result != NEXT)
		{
			system("cls");
			ShowBoard(board, COW, LINE);
			break;
		}
		Compmove(board, COW, LINE);
		result = Judge(board, COW, LINE);
		if (result != NEXT)
		{
			system("cls");
			ShowBoard(board, COW, LINE);
			break;	
		}
		
	} while (1);
	if (result == PLAY)
	{
		printf("恭喜你，你赢了\n");
	}
	else if (result == COMP)
	{
		printf("很遗憾，你输了\n");
	}
	else
	{
		printf("和棋，继续努力\n");
	}
}