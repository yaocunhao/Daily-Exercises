#include <stdio.h>
#include <windows.h>
//输出特殊图案，请在c环境中运行
Prin()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%c%c",177, 176,178,219);
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