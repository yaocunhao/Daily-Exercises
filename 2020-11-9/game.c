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
	srand ((unsigned long)time(NULL));// ����һ�����ֿ�
	int c = rand() % RANGE + 1;//����һ���²�ķ�Χ
	while (1)
	{
		printf("��������²������\n");
		scanf("%d", &a);
		if (a > c)
		{
			printf("�´���\n");
		}
		else if (a < c)
		{
			printf("��С��\n");
		}
		else
		{
			printf("��ϲ�㣬�¶��ˣ�");
			break;
		}
	}


}