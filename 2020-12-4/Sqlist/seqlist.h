#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)
#include <assert.h>

typedef int SLDataType;


typedef struct SeqList
{
	int size;
	int capacity;
	SLDataType *arr;
}SL;
void SeqListInit(SL*sp);
void SeqListPrint(SL*sp);
void CheckCapacoty(SL*sp);
void SeqListPushBack(SL*sp);
void SeqListPopBack(SL*sp);
void SeqListPushFront(SL*sp);
void SeqListPopFront(SL*sp);
void SeqListFind(SL*sp);
void SeqListInsert(SL*sp);
void SeqListErase(SL*sp);
void SeqListDestory(SL*sp);

void Menu();





#endif