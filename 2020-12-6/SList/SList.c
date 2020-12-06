#include "SList.h"

SListNode *BuySListNode(SListDataType x)
{
	SListNode *NewNode = (SListNode*)malloc(sizeof(SListDataType));//����һ���ڵ����
	if (NewNode == NULL)
	{
		printf("����ʧ��\n");
		exit(-1);
	}
	else
	{
		NewNode->data = x;
		NewNode->next=NULL;
	}
	return NewNode;//�����½ڵ�ĵ�ַ
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
void SListPushBack(SListNode *phead,SListDataType x)//β��
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