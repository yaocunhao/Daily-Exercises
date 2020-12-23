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

ListNode* ListCreate(LTDataType data);// 创建返回链表的头结点.
void ListDestory(ListNode** plist);// 双向链表销毁
void ListPrint(ListNode* plist);// 双向链表打印
void ListPushBack(ListNode* plist, LTDataType x);// 双向链表尾插
void ListPopBack(ListNode* plist);// 双向链表尾删
void ListPushFront(ListNode* plist, LTDataType x);// 双向链表头插
void ListPopFront(ListNode* plist);// 双向链表头删
ListNode* ListFind(ListNode* plist, LTDataType x);// 双向链表查找
void ListInsert(ListNode* pos, LTDataType x);// 双向链表在pos的前面进行插入
void ListErase(ListNode* pos);// 双向链表删除pos位置的节点






#endif 