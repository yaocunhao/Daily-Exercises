#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//编写input()和output()函数输入，输出5个学生的数据记录。

struct Stu
{
	char name[64];
	int age;
	char sex[5];
}stu[5];
void input(Stu*stu)
{
	for (int i = 0; i < 5; i++)
	{

		scanf("%s%d%s", stu[i].name,&(stu[i].age),stu[i].sex);
	}
}
void output(Stu*stu)
{
	for (int i = 0; i < 5; i++)
	{
		printf("姓名：%s 年龄：%d 性别%s\n", stu[i].name, stu[i].age,stu[i].sex);
	}
}

int main()
{
	printf("请输入五个学生的信息：姓名 年龄 性别\n");
	input(stu);
	output(stu);
	system("pause");
	return 0;
}
