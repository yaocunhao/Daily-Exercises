#include "test.h"


int main()
{
	int select = 0;
	while (!select)
	{
		Menu();
		printf("���������ѡ��\n");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			Add();//�����ϵ��
			select = 0;
			break;
		case 2:
			Delect();//ɾ����ϵ��
			select = 0;
			break;
		case 3:
			Found();//����
			select = 0;
				break;
		case 4:
			Alter();//�޸�
				select = 0;
			break;
		
		case 5:
			Show();//��ʾ
			select = 0;
			break;
		case 6:
			Empty();//���
			select = 0;
			break;
		case 7:
			Rank();//����������
			select = 0;
			break;
		case 8:
			select = 1;
			break;//�˳�
		default:
			printf("��������\n");
			select = 0;
		}
	}

	system("pause");
	return 0;
}

