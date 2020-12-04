#include "seqlist.h"


int main()
{
	int quit = 0;
	int select = 0;
	SL s;//定义一个结构体变量
	SeqListInit(&s);//开辟空间
	while (!quit)
	{
		Menu();
		printf("输入你的选择\n");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			system("cls");
			SeqListPrint(&s);
			break;
		case 2:
			system("cls");
			SeqListPushBack(&s);
			break;
		case 3:
			system("cls");
			SeqListPopBack(&s);
			break;
		case 4:
			system("cls");
			SeqListPushFront(&s);
			break;
		case 5:
			system("cls");
			SeqListPopFront(&s);
			break;
		case 6:
			system("cls");
			SeqListFind(&s);
			break;
		case 7:
			system("cls");
			SeqListInsert(&s);
			break;
		case 8:
			system("cls");
			SeqListErase(&s);
			break;
		case 9:
			SeqListDestory(&s);
			quit = 1;//顺序表销毁退出循环;
			break;
		case 10:
			system("cls");
			quit = 1;//退出;
			break;
		default:
			printf("输入有误，请从新输入\n");
		}
	}
	system("pause");
	return 0;
}