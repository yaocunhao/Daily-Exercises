#include "game.h"
void Menu()
{
	printf("########################\n");
	printf("##1.GO##########2.quit##\n");
	printf("########################\n");
}
static void Showboard(char board[][LINE], int row, int line)
{
	printf("    ");
	for (int i = 0; i <row-2; i++)
	{
		printf(" %2d |", i+1);
	}
	printf("\n------------------------------------------------------\n");
	for (int i = 1; i < row - 1; i++)
	{
		printf(" %2d|", i);
		for (int j = 1; j < line - 1; j++)
		{
			printf(" %2c |", board[i][j]);
		}
		printf("\n------------------------------------------------------\n");
	}
}
static char Detect(char mineboard[][LINE], int x, int y)
{
	if (mineboard[x][y] == '0')
	{
		return mineboard[x][y - 1] + mineboard[x][y + 1] \
			+ mineboard[x - 1][y - 1] + mineboard[x - 1][y] \
			+ mineboard[x - 1][y + 1] + mineboard[x + 1][y - 1]\
			+ mineboard[x + 1][y] + mineboard[x + 1][y - 1]-7*'0';
	}
	if (mineboard[x][y] =='1')
	{
		return OVER;
	}
}
void Firstmine(char mineboard[][LINE], int x, int y)
{
	if (mineboard[x][y] == '1')
	{
		mineboard[x][y] = '0';
	}
	while (1)
	{
		x = (rand() % (ROW - 2)) + 1;
		y = (rand() % (LINE - 2)) + 1;
		if (mineboard[x][y] == '0')
		{
			mineboard[x][y] = '1';
			break;
		}
	}
}
static void Mineset(char mineboard[][LINE],int row,int line)
{
	int x = 0;
	int y = 0;
	int count = MINE;
	while (count)
	{
		x = (rand() % (ROW - 2)) + 1;
		y = (rand() % (LINE - 2)) + 1;
		if (mineboard[x][y] == '0')
		{
			mineboard[x][y] = '1';
			count--;
		}
	}
}
void Game()
{
	srand((unsigned)time(NULL));
	char board[ROW][LINE];
	memset(board, '*', sizeof(board));//��ʾ��û�㿪֮ǰΪ*
	char mineboard[ROW][LINE];
	memset(mineboard, '0', sizeof(board));//�׵�ͳ�Ƴ�ʼ��Ϊ0
	Mineset(mineboard, ROW, LINE);//��������
	int count = (ROW - 2)*(LINE - 2);
	while (count)
	{
		system("cls");
		Showboard(board, ROW, LINE);
		int quit = 0;
		int x = 0;
		int y = 0;
		while (!quit)
		{
			printf("�������������\n");
			scanf("%d %d", &x, &y);
			if (x<0 || x>ROW - 2 || y<0 || y>LINE - 2)
			{
				printf("����Խ�磬���������\n");
				continue;
			}
			if (board[x][y] != '*')
			{
				printf("�˴��Ѿ��ų������������\n");
				continue;
			}
			quit = 1;
		}
		while (count == (ROW - 2)*(LINE - 2))
		{
			Firstmine(mineboard, x, y);
			break;
		}
		int result = Detect(mineboard, x, y);
		if (result == OVER)
		{
			board[x][y] = OVER;
			system("cls");
			Showboard(board, ROW, LINE);
			break;
		}
		else
		{
			board[x][y] = result;
		}
		count--;
	}
	if (count == 0)
	{
		printf("��ϲ�㣬��Ӯ��\n");
	}
	else
		printf("���ź����㱻ը����\n");
	printf("�����ֲ�����\n");
	Showboard(mineboard, ROW, LINE);
}
void Login()
{
	char str[64];
	char arr[64];
	int quit = 0;
	int count = 3;
	while (!quit)
	{
		printf("����������˺�\n");
		scanf("%s %s", str, arr);
		if (strcmp(str, ACCOUNT) && strcmp(arr, PASSWORD) == 0)
		{
			printf("��ӭ������Ϸ\n");
			quit = 1;
		}
		else
			printf("��������㻹��%d�λ���\n",--count);
		if (count == 0)
		{
			printf("3�������\n");
			for (int i = 0; i < 3; i++)
			{
				printf("%dS\r", i + 1);
				Sleep(1000);
				count = 3;
			}
		}
	}


}

