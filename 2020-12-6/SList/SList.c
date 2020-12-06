#include "SList.h"

SListNode *BuySListNode(SListDataType x)
{
	SListNode *NewNode = (SListNode*)malloc(sizeof(SListDataType));//开辟一个节点出来
	if (NewNode == NULL)
	{
		printf("申请失败\n");
		exit(-1);
	}
	else
	{
		NewNode->data = x;
		NewNode->next=NULL;
	}
	return NewNode;//返回新节点的地址
}
void SListPrint(SListNode *phead)
{
	while (phead!= NULL)
	{
		printf("%d->", phead->data);
		phead = phead->next;
	}
	printf("NULL\n");
}
void SListPushBack(SListNode *phead,SListDataType x)//尾插
{
	assert(phead);
		while (phead->next != NULL)
		{
			phead = phead->next;
		}
		phead->next = BuySListNode(x);
}
void SListPopBack(SListNode *phead)
{
	SListNode *pre = NULL;
	assert(phead);
	if (phead->next == NULL)
	{
		free(phead);
		phead = NULL;
	}
	else
	{
		while (phead->next != NULL)
		{
			pre = phead;
			phead = phead->next;
		}
		free(phead);
		pre->next = NULL;
	}

}