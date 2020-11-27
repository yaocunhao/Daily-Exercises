#include "test.h"
void Menu()
{
	printf("###1.添加联系人信息############2.删除指定联系人信息####################\n");
	printf("###3.查找指定联系人信息#########4.修改指定人信息#######################\n");
	printf("###5.显示所有联系人信息#########6.清空所有联系人#######################\n");
	printf("###7.以名字排序所有联系人#######8.退出#################################\n");

}
int Comp(char name[],address *sp)//寻找对应的名字；
{
	int i = 0;
	for (i = 0; i < sp->count; i++)
	{
		if ((strcmp(sp->call[i].name, name)) == 0)
			return i;//返回找到的下标；
	}
	return -1;//找不到返回-1
}

 void Open(address *p)//开辟空间函数
{
	p->call = (list *)malloc(TWO*sizeof(list));//宏TWO=2，给调用信息表的指针分配内存
	if (p->call != NULL)
	{
		p->count = 0;//记录存储个数的计数器count
		p->capacity = 2;//开辟空间容量计数器，每次开辟空间提供2次存储机会；
	}
}
static void Judge(address *sp)//进行空间容量判断
{
	if (sp->count == sp->capacity)//上次开辟的内存满了
	{
		list *dst = (list *)realloc(sp->call,(sp->capacity+TWO)*sizeof(list));//增加两个空间;
		if (dst != NULL)
		{
			sp->call = dst;//将开辟成功的地址返回给原指针
			sp->capacity += 2;//空间容量计数器+2；
		}
	}


}
void Add(address *p)//增加函数
{
	Judge(p);//进行空间判断是否足够；
	printf("请输入联系人姓名\n");
	scanf("%s", p->call[p->count].name);
	printf("请输入联系人性别\n");
	scanf("%s", p->call[p->count].sex);
	printf("请输入联系人年龄\n");
	scanf("%d", &(p->call[p->count].age));
	printf("请输入联系人电话\n");
	scanf("%s", p->call[p->count].tel);
	printf("请输入联系人住址\n");
	scanf("%s", p->call[p->count].address);
	p->count++;//计数器+1；
}

void Delect(address *p)//删指定人函数
{
	int i = 0;//接收查找的人
	char name[20];
	printf("请输入要删除的指定人的名字\n");
	scanf("%s", name);
	i = Comp(name,p);
	if (i == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		Judge(p);//进行空间判定，避免越界；
		for (i; i < p->count; i++)//覆盖，利用后面的数据将前面的数据全部覆盖；
		{
			p->call[i] = p->call[i + 1];
		}
		p->count--;//成员减1，计数器减1
		printf("删减成功\n");
	}
	
}

int Found(address *p)//查找成员
{
	char name[NUM];
	printf("请输入你要查找的名字\n");
	scanf("%s", name);
	int j = Comp(name,p);//接收返回值，找到返回值为对应的成员下标
	if (j == -1)
	{
		printf("查无此人\n");
	}
	else
		printf("姓名：%s 性别：%s 年龄:%d 电话：%s 住址：%s\n", p->call[j].name,
		p->call[j].sex,p->call[j].age,p->call[j].tel,p->call[j].address);

	return j;//方便Alter函数调用
}

void Alter(address *p)//修改指定人信息
{
	int select = 0;
	char newname[NUM];//需要修改的名字
	char newsex[NUM];//需要修改的性别
	int  neweag;//需要修改的年龄
	char newtel[NUM];//需要修改的电话
	char newaddress[NUM];//需要修改的地址;
	int j=Found(p);//先找到这个人
	if (j !=-1)
	{
		while (!select)
		{
			printf("请选择需要修改的信息\n");
			printf("********************************\n");
			printf("**1.姓名**********2.性别*********\n");
			printf("**3.年龄**********4.电话*********\n");
			printf("**5.住址**********6.退出*********\n");
			printf("********************************\n");
			scanf("%d", &select);
			switch (select)
			{
			case 1:
				printf("请输入新的姓名\n");
				scanf("%s", newname);
				strcpy(p->call[j].name, newname);
				select = 0;
				break;
			case 2:
				printf("请输入新的性别\n");
				scanf("%s", newsex);
				strcpy(p->call[j].sex, newsex);
				select = 0;
				break;
			case 3:
				printf("请输入新的年龄\n");
				scanf("%d", &neweag);
				p->call[j].age = neweag;
				select = 0;
				break;
			case 4:
				printf("请输入新的电话\n");
				scanf("%s", newtel);
				strcpy(p->call[j].tel, newtel);
				select = 0;
				break;
			case 5:
				printf("请输入新的住址\n");
				scanf("%s", newaddress);
				strcpy(p->call[j].address, newaddress);
				select = 0;
				break;
			case 6:
				select = 1;
				break;
			default:
				printf("输入有误，从新输入\n");
				select = 0;
				break;
			}
		}
	}

}

void Show(address *p)//显示所有人信息
{
	if (p->count == 0)
		printf("联系人列表为空\n");
	for (int j = 0; j < p->count; j++)//将第一个到最后一个有信息的名单打印出来
	{
		printf("姓名：%s 性别：%s 年龄:%d 电话：%s 住址：%s\n", p->call[j].name,
			p->call[j].sex, p->call[j].age, p->call[j].tel, p->call[j].address);
	}
}

void Empty(address *p)//清空通讯录			
{
	free(p->call);//释放掉申请的内存
	p->count = 0;//计数器归零
	p->capacity;//容量计数器归零
}

static int Compar(const list *x, const list *y)//排序回调函数
{
	return strcmp(x->name, y->name);
}
void Rank(address *p)
{
		if (p->count==0)
		{
			printf("联系人列表为空\n");
		}

	else
		qsort(p->call->name, p->count, sizeof(list), Compar);//利用qsort进行排序；
}
