#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <windows.h>
#include <assert.h>

typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

ListNode* ListCreate(LTDataType data);// �������������ͷ���.
void ListDestory(ListNode** plist);// ˫����������
void ListPrint(ListNode* plist);// ˫�������ӡ
void ListPushBack(ListNode* plist, LTDataType x);// ˫������β��
void ListPopBack(ListNode* plist);// ˫������βɾ
void ListPushFront(ListNode* plist, LTDataType x);// ˫������ͷ��
void ListPopFront(ListNode* plist);// ˫������ͷɾ
ListNode* ListFind(ListNode* plist, LTDataType x);// ˫���������
void ListInsert(ListNode* pos, LTDataType x);// ˫��������pos��ǰ����в���
void ListErase(ListNode* pos);// ˫������ɾ��posλ�õĽڵ�






#endif 