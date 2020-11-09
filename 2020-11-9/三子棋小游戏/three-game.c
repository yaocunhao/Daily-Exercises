#include "game.h"


void Menu()
{
	printf("########################\n");
	printf("1.enter###########2.quit\n");
	printf("########################\n");
	printf("����������ѡ��!\n");

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


	void Playmove(char board[][LINE], int cow, int line)//�������
	{
		int x = 0;
		int y = 0;
		while (1)
		{
			printf("�������������# ");
			scanf("%d %d", &x, &y);
			if (x<1 || x>3 || y<1 || y>3)
			{
				printf("������������������������\n");
				continue;
			}
			else if (board[x - 1][y - 1] != ' ')
			{
				printf("������������������������\n");
				continue;
			}
			else
			{
				board[x - 1][y - 1] = PLAY;
			}
			break;
		}
	}
 

char Judge(char board[][LINE], int cow, int line)//ϵͳ�ж�������
{
	for (int i = 0; i < cow; i++)//ÿ���Ƿ�һ��
	{
		if (board[i][0] == board[i][1] && \
			board[i][1] == board[i][2] && \
			board[i][0] != ' ')
		{
			return board[i][0];
		}

	}

	for (int i = 0; i < line; i++)//ÿ���Ƿ�һ��
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
		return board[0][0];                        //�����Խ��Ƿ�һ��
	}

	if (board[0][2] == board[1][1] && \
		board[1][1] == board[2][0] && \
		board[0][2] != ' ')
	{
		return board[0][2];
	}

	for (int i = 0; i < cow; i++)
	{
		for (int j = 0; j < line; j++)               //����û�пո�,�пո���û���ꣻ
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
		if (board[x][y] == ' ')     //����������ӣ�
		{
			board[x][y] = COMP;
			break;
		}
	}

}


void Game()
{
	system("cls");
	srand((unsigned)time(NULL));//������������ӣ�ϵͳ������壻
	char board[COW][LINE];//�������ӣ�X O��
	memset(board, ' ', sizeof(board));// ���������и��ӻ��ɿո�
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
		printf("��ϲ�㣬��Ӯ��\n");
	}
	else if (result == COMP)
	{
		printf("���ź���������\n");
	}
	else
	{
		printf("���壬����Ŭ��\n");
	}
}