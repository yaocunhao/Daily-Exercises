#include "SList.h"


int main()
{
	SListNode *head=BuySListNode(100);//开辟节点
	SListPushBack(head,200);//尾插
	SListPushBack(head, 300);
	SListPushBack(head, 400);
	SListPopBack(head);
	SListPrint(head);//打印

	system("pause");
	return 0;
}