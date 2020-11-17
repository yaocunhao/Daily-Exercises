#include <stdio.h>
#include <windows.h>
//要求输出国际象棋棋盘。64个格子
void Prin()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%c%c",177,219);
		}
		printf("\n");
	}
}
int main()
{
	SetConsoleOutputCP(437);//显示大与127的ASCII码
	Prin();
	system("pause");
	return 0;
}



