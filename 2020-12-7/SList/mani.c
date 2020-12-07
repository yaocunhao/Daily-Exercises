#include "SList.h"


int main()
{
	SListNode *pList = NULL;
	SListPushBack(&pList, 200);//Î²²å
	SListPushBack(&pList, 300);
	SListPushBack(&pList, 400);
	SListPrint(pList);//´òÓ¡
    SListPopBack(&pList);
	SListPushFront(&pList, 100);
	SListPrint(pList);//´òÓ¡
	SListPopFront(&pList);
	SListPrint(pList);//´òÓ¡
	//printf("%d\n",SListFind(pList,200)->data);
	SListInsertAfter(SListFind(pList, 200),250);
	SListPrint(pList);//´òÓ¡
	SListEraseAfter(SListFind(pList, 250));
	SListPrint(pList);//´òÓ¡
	SListDestory(&pList);//Ïú»Ù
	SListPrint(pList);//´òÓ¡
	system("pause");
	return 0;
}