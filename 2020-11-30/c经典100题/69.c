#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
//�����ѧ����ÿ��ѧ����3�ſεĳɼ����Ӽ��������������ݣ�����ѧ���ţ����������ſγɼ�����\
�����ƽ���ɼ�����ԭ�е����ݺͼ������ƽ����������ڴ����ļ�"stud"�С�
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
		printf("�������%d��ѧ������Ϣ,ѧ�ţ��������ɼ�\n", i+1);
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