#ifndef _SLIST_H_
#define _SLIST_H_

#include <stdio.h>
#include <windows.h>
#include <assert.h>
typedef int SListDataType;

typedef struct SlistNode
{
	SListDataType data;
	struct SlistNode *next;
}SListNode;

SListNode *BuySListNode(SListDataType x);
void SListPrint(SListNode *phead);
void SListPushBack(SListNode *phead,SListDataType x);
void SListPopBack(SListNode *phead);



#endif 