#include "list.h"


int main()
{
	ListNode *plist = NULL;
	plist = ListCreate(0);
	plist->_next = plist;
	plist->_prev = plist;
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);

	ListPushFront(plist, 5);
	ListPushFront(plist, 6);
	ListPushFront(plist, 7);
	ListPushFront(plist, 8);
	ListInsert(plist->_next->_next, 1000);

	ListErase(plist->_next->_next);
	//ListPopFront(plist);
	//ListPopFront(plist);



	//ListPopBack(plist);
	//ListPopBack(plist);

	ListDestory(&plist);
	ListPrint(plist);
	//ListNode* cur = ListFind(plist, 100);
	//if (cur)
	//	printf("%d\n", cur->_data);
	//else
		//printf("链表中没有这个值\n");

	system("pause");
	return 0;
}