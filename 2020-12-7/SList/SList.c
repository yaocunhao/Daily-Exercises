#include "SList.h"

SListNode *BuySListNode(SListDataType x)
{
	SListNode *NewNode = (SListNode*)malloc(sizeof(SListNode));//开辟一个节点出来
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
void SListPushBack(SListNode **pphead, SListDataType x)//尾插
{
	SListNode *tail = *pphead;
	if (tail == NULL)
	{
		*pphead = BuySListNode(x);
	}
	else
	{
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = BuySListNode(x);

	}
}
void SListPopBack(SListNode **pphead)//尾删
{
	SListNode *tail = *pphead;
	SListNode *pre = NULL;
	if (*pphead == NULL)
	{
		return;
	}
	if (tail->next == NULL)//只有一个节点
	{
		free(tail);
		*pphead = NULL;
	}
	else
	{
		while (tail->next != NULL)
		{
			pre = tail;
			tail = tail->next;
		}
		free(tail);
		pre->next = NULL;
	}
}
void SListPushFront(SListNode **pphead,SListDataType x)//头插
{
	SListNode *head = BuySListNode(x);
	head->next = *pphead;
	*pphead = head;
}

void SListPopFront(SListNode **pphead)//头删
{
	SListNode *phead = *pphead;
	*pphead = (*pphead)->next;
	free(phead);
}

SListNode *SListFind(SListNode *pphead, SListDataType x)//查找
{
	while (pphead!=NULL)
	{
		if (pphead->data == x)
		{
			return pphead;
		}
		pphead = pphead->next;
	}
	return NULL;
}

void SListInsertAfter(SListNode *pos, SListDataType x)//插入
{
	SListNode *temp=BuySListNode(x);
	temp->next = pos->next;
	pos->next = temp;
}
void SListEraseAfter(SListNode* pos)//pos之后销毁
{
	SListNode *temp = (pos->next)->next;
	free(pos->next);
	pos->next = temp;
}
void SListDestory(SListNode **pList)
{
	SListNode *plist = *pList;
	SListNode *prev = NULL;
	while (plist!= NULL)
	{
		prev = plist->next;
		free(plist);
		plist = prev;
	}
	*pList = NULL;
	printf("销毁成功\n");
}