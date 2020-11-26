#include "test.h"


int main()
{
	int select = 0;
	while (!select)
	{
		Menu();
		printf("请输入你的选择\n");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			Add();//添加联系人
			select = 0;
			break;
		case 2:
			Delect();//删除联系人
			select = 0;
			break;
		case 3:
			Found();//查找
			select = 0;
				break;
		case 4:
			Alter();//修改
				select = 0;
			break;
		
		case 5:
			Show();//显示
			select = 0;
			break;
		case 6:
			Empty();//清空
			select = 0;
			break;
		case 7:
			Rank();//以姓氏排序
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

