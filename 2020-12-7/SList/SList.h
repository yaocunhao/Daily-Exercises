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

SListNode *BuySListNode(SListDataType x);//申请节点
void SListPrint(SListNode *phead);//打印
void SListPushBack(SListNode **pphead,SListDataType x);//尾插
void SListPopBack(SListNode **pphead);//尾删
void SListPushFront(SListNode **pphead, SListDataType x);//头插
void SListPopFront(SListNode **pphead);//头删
SListNode* SListFind(SListNode *pphead, SListDataType x);//查找
void SListInsertAfter(SListNode *pos,SListDataType x);//pos之后插入
void SListEraseAfter(SListNode* pos);//pos之后删除
void SListDestory(SListNode **pList);//销毁

#endif 