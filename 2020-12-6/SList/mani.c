#include "SList.h"


int main()
{
	SListNode *head=BuySListNode(100);//���ٽڵ�
	SListPushBack(head,200);//β��
	SListPushBack(head, 300);
	SListPushBack(head, 400);
	SListPopBack(head);
	SListPrint(head);//��ӡ

	system("pause");
	return 0;
}