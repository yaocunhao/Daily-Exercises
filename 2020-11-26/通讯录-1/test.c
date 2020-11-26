#include "test.h"

void Menu()
{
	printf("###1.添加联系人信息############2.删除指定联系人信息####################\n");
	printf("###3.查找指定联系人信息#########4.修改指定人信息#######################\n");
	printf("###5.显示所有联系人信息#########6.清空所有联系人#######################\n");
	printf("###7.以名字排序所有联系人#######8.退出#################################\n");

}

 struct ADDRES_BOOK //通讯录结构体，表明存储成员的那些信息
{
	char name[20];
	char sex[20];
	int age;
	char tel[20];
	char addres[50];
}p[NUM];//NUM,存储的联系人个数

int count = 0;//计数器
int Comp(char name[])//寻找对应的名字；
{
	int i = 0;
	for (i = 0; i < NUM; i++)
	{
		if ((strcmp(p[i].name, name)) == 0)
			return i;//返回找到的下标；

	}
	return -1;//找不到返回-1
}
void Show()//显示所有联系人
{
	int i ;
	for (i = 0; i < NUM; i++)
	{
		if (*((p[i]).name) == '\0')//没有找到时停止
		{
			break;
		}
	}
	if (i == 0)
	{
		printf("联系人列表为空\n");
	}
	for (int j = 0; j < i; j++)//将第一个到最后一个有信息的名单打印出来
	{
		printf("姓名：%s 性别：%s 年龄:%d 电话：%s 住址：%s\n", \
			p[j].name,p[j].sex,p[j].age,p[j].tel,p[j].addres);
		printf("\n");
	}
}
void Found()//查找联系人
{
	char name[20];
	printf("请输入你要查找的名字\n");
	scanf("%s", name);
	int j = Comp(name);//接收返回值，找到返回值为对应的成员下标
	if (j == -1)
	{
		printf("查无此人\n");
	}
	else
		printf("姓名：%s 性别：%s 年龄:%d 电话：%s 住址：%s\n", \
		p[j].name, p[j].sex, p[j].age, p[j].tel, p[j].addres);
}
void Alter()//修改联系人信息
{
	int select = 0;
	char name[20];
	char newname[20];//需要修改的名字
	char newsex[20];//需要修改的性别
	int  neweag;//需要修改的年龄
	char newtel[20];//需要修改的电话
	char newaddres[50];//需要修改的地址;

	printf("请输入需要修改的联系人的名字\n");
	scanf("%s", name);
	int j = Comp(name);
	if (j == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("姓名：%s 性别：%s 年龄:%d 电话：%s 住址：%s\n", \
			p[j].name, p[j].sex, p[j].age, p[j].tel, p[j].addres);
	}
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
			strcpy(p[j].name, newname);
			select = 0;
			break;
		case 2:
			printf("请输入新的性别\n");
			scanf("%s", newsex);
			strcpy(p[j].sex, newsex);
			select = 0;
			break;
		case 3:
			printf("请输入新的年龄\n");
			scanf("%d", &neweag);
			p[j].age = neweag;
			select = 0;
			break;
		case 4:
			printf("请输入新的电话\n");
			scanf("%s", newtel);
			strcpy(p[j].tel, newtel);
			select = 0;
			break;
		case 5:
			printf("请输入新的住址\n");
			scanf("%s", newaddres);
			strcpy(p[j].addres, newaddres);
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


void Add()//增加联系人信息
{
	int n = 0;
	printf("请输入你要输入几个人的信息\n");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("输入有误\n");
	}
	int i = count;//计数器，每增加一个计数器+1
	for (i = count; i < n+count; i++)//从计数器位置开始添加，避免成员重复;
	{
		printf("请输入联系人信息，姓名 性别 年龄 电话 住址\n");
		scanf("%s%s%d%s%s", p[i].name, p[i].sex, &(p[i].age), p[i].tel, p[i].addres);
	}
	count = i;
}
void Delect()
{
	int i = 0;//接收查找的人
	char name[20];
	printf("请输入要删除的指定人的名字\n");
	scanf("%s", name);
	 i= Comp(name);
	if (i == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		if (i==NUM)//删除最后一个人，将其全部赋值为0；
		{
			strcpy(p[NUM - 1].name, 0);
			strcpy(p[NUM - 1].addres, 0);
			strcpy(p[NUM - 1].sex, 0);
			strcpy(p[NUM - 1].tel, 0);
			p[NUM - 1].age = 0;
		}
		else
		for (i; i < NUM - 1; i++)//覆盖，利用后面的数据将前面的数据全部覆盖；
		{
			p[i] = p[i + 1];
		}
	}
	count--;//删除一个人计数器减1；
	
}
void Empty()//清空所有联系人
{
	memset(p, 0, sizeof(p));//全部初始化为0
}

int Compar(const struct ADDRES_BOOK *x, const struct ADDRES_BOOK*y)//排序回调函数
{
	return strcmp(x->name, y->name);
}
void Rank()
{
	int i;
	for (i = 0; i < NUM; i++)
	{
		if (*(p[i].name) == '\0')
		{
			break;
		}
	}
	qsort(p, i, sizeof(p[0]), Compar);//利用qsort进行排序；
}