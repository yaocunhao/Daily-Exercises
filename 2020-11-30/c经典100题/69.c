#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//有五个学生，每个学生有3门课的成绩，从键盘输入以上数据（包括学生号，姓名，三门课成绩），\
计算出平均成绩，况原有的数据和计算出的平均分数存放在磁盘文件"stud"中。
typedef struct Stu
{
	char num[20];
	char name[20];
	int grade[3];
	int average;
}stu;
int main()
{
	FILE *fp = fopen("stud.log", "wb");
stu STU[5] = { 0 };
	for (int i = 0; i <5; i++)
	{
		printf("请输入第%d个学生的信息,学号，姓名，成绩\n", i+1);
		scanf("%s%s", STU[i].num, STU[i].name);
		for (int j = 0; j <3; j++)
		{
			scanf("%d", &(STU[i].grade[j]));

		}
		STU[i].average = ((STU[i].grade[0] + STU[i].grade[1] + STU[i].grade[2])/3);
	}
	fwrite(STU,sizeof(stu),1,fp);
	fclose(fp);
	system("pause");
	return 0;
}