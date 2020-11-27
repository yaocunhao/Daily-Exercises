#include "test.h"

int main()
{
	address book;//创建通讯录book
	Open(&book);//给通讯录开辟空间

	int select = 0;
	while (!select)
	{
		Menu();
		printf("请输入你的选择\n");
		scanf("%d", &select);
		getchar();
		switch (select)
		{
		case 1:
			system("cls");
			Add(&book);//添加联系人,传址
			select = 0;
			break;
		case 2:
			system("cls");
			Delect(&book);//删除联系人
			select = 0;
			break;
		case 3:
			system("cls");
			Found(&book);//查找
			select = 0;
			break;
		case 4:
			system("cls");
			Alter(&book);//修改
			select = 0;
			break;
		case 5:
			system("cls");
			Show(&book);//显示
			select = 0;
			break;
		case 6:
			system("cls");
			Empty(&book);//清空
			select = 0;
			break;
		case 7:
			system("cls");
			Rank(&book);//以姓氏排序
			select = 0;
			break;
		case 8:
			select = 1;
			break;//退出
		default:
			printf("输入有误\n");
			select = 0;
		}
	}
	system("pause");
	return 0;
}