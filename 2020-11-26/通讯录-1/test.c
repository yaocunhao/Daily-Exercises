#include "test.h"

void Menu()
{
	printf("###1.�����ϵ����Ϣ############2.ɾ��ָ����ϵ����Ϣ####################\n");
	printf("###3.����ָ����ϵ����Ϣ#########4.�޸�ָ������Ϣ#######################\n");
	printf("###5.��ʾ������ϵ����Ϣ#########6.���������ϵ��#######################\n");
	printf("###7.����������������ϵ��#######8.�˳�#################################\n");

}

 struct ADDRES_BOOK //ͨѶ¼�ṹ�壬�����洢��Ա����Щ��Ϣ
{
	char name[20];
	char sex[20];
	int age;
	char tel[20];
	char addres[50];
}p[NUM];//NUM,�洢����ϵ�˸���

int count = 0;//������
int Comp(char name[])//Ѱ�Ҷ�Ӧ�����֣�
{
	int i = 0;
	for (i = 0; i < NUM; i++)
	{
		if ((strcmp(p[i].name, name)) == 0)
			return i;//�����ҵ����±ꣻ

	}
	return -1;//�Ҳ�������-1
}
void Show()//��ʾ������ϵ��
{
	int i ;
	for (i = 0; i < NUM; i++)
	{
		if (*((p[i]).name) == '\0')//û���ҵ�ʱֹͣ
		{
			break;
		}
	}
	if (i == 0)
	{
		printf("��ϵ���б�Ϊ��\n");
	}
	for (int j = 0; j < i; j++)//����һ�������һ������Ϣ��������ӡ����
	{
		printf("������%s �Ա�%s ����:%d �绰��%s סַ��%s\n", \
			p[j].name,p[j].sex,p[j].age,p[j].tel,p[j].addres);
		printf("\n");
	}
}
void Found()//������ϵ��
{
	char name[20];
	printf("��������Ҫ���ҵ�����\n");
	scanf("%s", name);
	int j = Comp(name);//���շ���ֵ���ҵ�����ֵΪ��Ӧ�ĳ�Ա�±�
	if (j == -1)
	{
		printf("���޴���\n");
	}
	else
		printf("������%s �Ա�%s ����:%d �绰��%s סַ��%s\n", \
		p[j].name, p[j].sex, p[j].age, p[j].tel, p[j].addres);
}
void Alter()//�޸���ϵ����Ϣ
{
	int select = 0;
	char name[20];
	char newname[20];//��Ҫ�޸ĵ�����
	char newsex[20];//��Ҫ�޸ĵ��Ա�
	int  neweag;//��Ҫ�޸ĵ�����
	char newtel[20];//��Ҫ�޸ĵĵ绰
	char newaddres[50];//��Ҫ�޸ĵĵ�ַ;

	printf("��������Ҫ�޸ĵ���ϵ�˵�����\n");
	scanf("%s", name);
	int j = Comp(name);
	if (j == -1)
	{
		printf("���޴���\n");
	}
	else
	{
		printf("������%s �Ա�%s ����:%d �绰��%s סַ��%s\n", \
			p[j].name, p[j].sex, p[j].age, p[j].tel, p[j].addres);
	}
	while (!select)
	{
		printf("��ѡ����Ҫ�޸ĵ���Ϣ\n");
		printf("********************************\n");
		printf("**1.����**********2.�Ա�*********\n");
		printf("**3.����**********4.�绰*********\n");
		printf("**5.סַ**********6.�˳�*********\n");
		printf("********************************\n");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("�������µ�����\n");
			scanf("%s", newname);
			strcpy(p[j].name, newname);
			select = 0;
			break;
		case 2:
			printf("�������µ��Ա�\n");
			scanf("%s", newsex);
			strcpy(p[j].sex, newsex);
			select = 0;
			break;
		case 3:
			printf("�������µ�����\n");
			scanf("%d", &neweag);
			p[j].age = neweag;
			select = 0;
			break;
		case 4:
			printf("�������µĵ绰\n");
			scanf("%s", newtel);
			strcpy(p[j].tel, newtel);
			select = 0;
			break;
		case 5:
			printf("�������µ�סַ\n");
			scanf("%s", newaddres);
			strcpy(p[j].addres, newaddres);
			select = 0;
			break;
		case 6:
			select = 1;
			break;
		default:
			printf("�������󣬴�������\n");
			select = 0;
			break;
		}
	}
}


void Add()//������ϵ����Ϣ
{
	int n = 0;
	printf("��������Ҫ���뼸���˵���Ϣ\n");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("��������\n");
	}
	int i = count;//��������ÿ����һ��������+1
	for (i = count; i < n+count; i++)//�Ӽ�����λ�ÿ�ʼ��ӣ������Ա�ظ�;
	{
		printf("��������ϵ����Ϣ������ �Ա� ���� �绰 סַ\n");
		scanf("%s%s%d%s%s", p[i].name, p[i].sex, &(p[i].age), p[i].tel, p[i].addres);
	}
	count = i;
}
void Delect()
{
	int i = 0;//���ղ��ҵ���
	char name[20];
	printf("������Ҫɾ����ָ���˵�����\n");
	scanf("%s", name);
	 i= Comp(name);
	if (i == -1)
	{
		printf("���޴���\n");
	}
	else
	{
		if (i==NUM)//ɾ�����һ���ˣ�����ȫ����ֵΪ0��
		{
			strcpy(p[NUM - 1].name, 0);
			strcpy(p[NUM - 1].addres, 0);
			strcpy(p[NUM - 1].sex, 0);
			strcpy(p[NUM - 1].tel, 0);
			p[NUM - 1].age = 0;
		}
		else
		for (i; i < NUM - 1; i++)//���ǣ����ú�������ݽ�ǰ�������ȫ�����ǣ�
		{
			p[i] = p[i + 1];
		}
	}
	count--;//ɾ��һ���˼�������1��
	
}
void Empty()//���������ϵ��
{
	memset(p, 0, sizeof(p));//ȫ����ʼ��Ϊ0
}

int Compar(const struct ADDRES_BOOK *x, const struct ADDRES_BOOK*y)//����ص�����
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
	qsort(p, i, sizeof(p[0]), Compar);//����qsort��������
}