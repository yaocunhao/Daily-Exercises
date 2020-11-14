#include "game.h"
void Menu() //�˵�
{
	printf("########################\n");
	printf("##1.GO##########2.quit##\n");
	printf("########################\n");
}
void Login()  //��¼�˺�����
{
	char str[64];
	char arr[64];
	int quit = 0;
	int count = 3;
	while (!quit)
	{
		printf("����������˺�\n");
		scanf("%s %s", str, arr);
		if (strcmp(str, ACCOUNT) == 0 && strcmp(arr, PASSWORD) == 0)
		{
			printf("��ӭ������Ϸ\n");
			quit = 1;
		}
		else
			printf("��������㻹��%d�λ���\n", --count);
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
static void Showboard(char board[][LINE], int row, int line) //������ʾ
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
static char Detect(char mineboard[][LINE], int x, int y)//����ɨ��ʱ����������ף�����ʾ��Χ����
{
	if (mineboard[x][y] == '0')
	{
		return mineboard[x][y - 1] + mineboard[x][y + 1] \
			+ mineboard[x - 1][y - 1] + mineboard[x - 1][y] \
			+ mineboard[x - 1][y + 1] + mineboard[x + 1][y - 1]\
			+ mineboard[x + 1][y] + mineboard[x + 1][y + 1]-7*'0';
	}
	if (mineboard[x][y] =='1')
	{
		return OVER;
	}
}
void Firstmine(char mineboard[][LINE], int x, int y)//�����һ�α�ը��
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
static void Mineset(char mineboard[][LINE])//����ֲ���
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
static void Openmine(char board[][LINE], char mineboard[][LINE], int x, int y)//ƽ��չ������
{
		board[x][y - 1] = Detect(mineboard,x,y-1);
		board[x][y + 1] = Detect(mineboard, x, y + 1);
		board[x - 1][y - 1] = Detect(mineboard, x-1, y - 1);		
		board[x - 1][y] = Detect(mineboard, x-1, y );	
		board[x - 1][y + 1] = Detect(mineboard, x-1, y + 1);	
		board[x + 1][y - 1] = Detect(mineboard, x+1, y - 1);		
		board[x + 1][y] = Detect(mineboard, x+1, y );			
		board[x + 1][y + 1] = Detect(mineboard, x + 1, y + 1);
}
static void Lable(char board[][LINE])//�������
{
	int x = 0;
	int y = 0;
	int quit = 0;
	int select = 0;
	while (!quit)
	{
		printf("�������Ƿ���Ҫ���б��#1.yes#2.no\n");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("��������ı������\n");
			scanf("%d %d", &x, &y);
			board[x][y] = '#';
			system("cls");
			Showboard(board, ROW, LINE);
			break;
		case 2:
			quit = 1;
			break;
		default:
			printf("�����������������\n");
		}
	}

}
static int Blank(char board[][LINE], int row, int line)//�ж�����ʣ��Ŀհ״�
{
	int count = 0;
	for (int i = 1; i < row - 1; i++)
	{
		for (int j = 1; j < line - 1; j++)
		{
			if (board[i][j] == '*' || board[i][j] == '#')
			{
				count++;
			}
		}
	}
	return count;
}
void Game()
{
	srand((unsigned)time(NULL));
	char board[ROW][LINE];
	memset(board, '*', sizeof(board));//��ʾ��û�㿪֮ǰΪ*
	char mineboard[ROW][LINE];
	memset(mineboard, '0', sizeof(board));//�׵�ͳ�Ƴ�ʼ��Ϊ0
	Mineset(mineboard);//��������
	int n = 1;//��ը��������
	while (1) //
	{
		system("cls");
		Showboard(board, ROW, LINE);//չʾ����
		while (1)//�ж��Ƿ���Ҫ���б�ǣ�
		{
			Lable(board);
			break;
		}
		int quit = 0;
		int x = 0;
		int y = 0;
		while (!quit)//ѭ����������ɨ��
		{
			printf("�������������\n");
			scanf("%d %d", &x, &y);
			if (x<0 || x>ROW - 2 || y<0 || y>LINE - 2)
			{
				printf("����Խ�磬���������\n");
				continue;
			}
			if (board[x][y] != '*' && board[x][y] != '#')
			{
				printf("�˴��Ѿ��ų������������\n");
				continue;
			}
			quit = 1;
		}
		while (n)//�ų���һ�α�ը��
		{
			Firstmine(mineboard, x, y);
			n--;
			break;
		}
		int result = Detect(mineboard, x, y);//�ж��Ƿ�ը��
		if (result == OVER)//ը����
		{
			system("cls");
			board[x][y] = OVER;
			Showboard(board, ROW, LINE);
			printf("���ź����㱻ը����\n");
			printf("�����ֲ�����\n");
			Showboard(mineboard, ROW, LINE);
			break;
		}
		else//ûը��
		{
			if (result == '0')//�����ɨ�״���Χ8�����ǰ�ȫ�ģ��ͽ���Χ8������Χ8����������ʾ������
			{
				Openmine(board, mineboard, x, y);
			}
			board[x][y] = result;
		}
		int Win = Blank(board, ROW, LINE);
		if (Win == MINE)
		{
			printf("��ϲ�㣬��Ӯ��\n");
			break;
		}
	}
}

