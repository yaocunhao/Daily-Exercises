#include "game.h"
void Menu() //菜单
{
	printf("########################\n");
	printf("##1.GO##########2.quit##\n");
	printf("########################\n");
}
void Login()  //登录账号密码
{
	char str[64];
	char arr[64];
	int quit = 0;
	int count = 3;
	while (!quit)
	{
		printf("请输入你的账号\n");
		scanf("%s %s", str, arr);
		if (strcmp(str, ACCOUNT) == 0 && strcmp(arr, PASSWORD) == 0)
		{
			printf("欢迎来到游戏\n");
			quit = 1;
		}
		else
			printf("输入错误，你还有%d次机会\n", --count);
		if (count == 0)
		{
			printf("3秒后再试\n");
			for (int i = 0; i < 3; i++)
			{
				printf("%dS\r", i + 1);
				Sleep(1000);
				count = 3;
			}
		}
	}

}
static void Showboard(char board[][LINE], int row, int line) //棋盘显示
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
static char Detect(char mineboard[][LINE], int x, int y)//进行扫雷时，如果不是雷，则显示周围雷数
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
void Firstmine(char mineboard[][LINE], int x, int y)//避免第一次被炸死
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
static void Mineset(char mineboard[][LINE])//随机分布雷
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
static void Openmine(char board[][LINE], char mineboard[][LINE], int x, int y)//平铺展开函数
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
static void Lable(char board[][LINE])//标记坐标
{
	int x = 0;
	int y = 0;
	int quit = 0;
	int select = 0;
	while (!quit)
	{
		printf("请输入是否需要进行标记#1.yes#2.no\n");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("请输入你的标记坐标\n");
			scanf("%d %d", &x, &y);
			board[x][y] = '#';
			system("cls");
			Showboard(board, ROW, LINE);
			break;
		case 2:
			quit = 1;
			break;
		default:
			printf("输入有误，请从新输入\n");
		}
	}

}
static int Blank(char board[][LINE], int row, int line)//判断棋盘剩余的空白处
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
	memset(board, '*', sizeof(board));//显示的没点开之前为*
	char mineboard[ROW][LINE];
	memset(mineboard, '0', sizeof(board));//雷的统计初始化为0
	Mineset(mineboard);//设置雷区
	int n = 1;//防炸死次数；
	while (1) //
	{
		system("cls");
		Showboard(board, ROW, LINE);//展示棋盘
		while (1)//判断是否需要进行标记；
		{
			Lable(board);
			break;
		}
		int quit = 0;
		int x = 0;
		int y = 0;
		while (!quit)//循环输入坐标扫雷
		{
			printf("请输入你的坐标\n");
			scanf("%d %d", &x, &y);
			if (x<0 || x>ROW - 2 || y<0 || y>LINE - 2)
			{
				printf("输入越界，请从新输入\n");
				continue;
			}
			if (board[x][y] != '*' && board[x][y] != '#')
			{
				printf("此处已经排除，请从新输入\n");
				continue;
			}
			quit = 1;
		}
		while (n)//排除第一次被炸死
		{
			Firstmine(mineboard, x, y);
			n--;
			break;
		}
		int result = Detect(mineboard, x, y);//判断是否被炸死
		if (result == OVER)//炸死了
		{
			system("cls");
			board[x][y] = OVER;
			Showboard(board, ROW, LINE);
			printf("很遗憾，你被炸死了\n");
			printf("雷区分布如下\n");
			Showboard(mineboard, ROW, LINE);
			break;
		}
		else//没炸死
		{
			if (result == '0')//如果该扫雷处周围8个都是安全的，就将周围8个的周围8个的雷数显示出来；
			{
				Openmine(board, mineboard, x, y);
			}
			board[x][y] = result;
		}
		int Win = Blank(board, ROW, LINE);
		if (Win == MINE)
		{
			printf("恭喜你，你赢了\n");
			break;
		}
	}
}

