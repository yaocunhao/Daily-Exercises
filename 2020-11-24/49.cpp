#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//��дinput()��output()�������룬���5��ѧ�������ݼ�¼��

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
		printf("������%s ���䣺%d �Ա�%s\n", stu[i].name, stu[i].age,stu[i].sex);
	}
}

int main()
{
	printf("���������ѧ������Ϣ������ ���� �Ա�\n");
	input(stu);
	output(stu);
	system("pause");
	return 0;
}
