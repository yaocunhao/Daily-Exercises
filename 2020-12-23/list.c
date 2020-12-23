#include "list.h"

ListNode* ListCreate(LTDataType data)// 创建返回链表的结点.
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node == NULL)
		exit(-1);
	node->_data = data;
	node->_prev = node->_next = NULL;
	return node;
}

void ListPrint(ListNode* plist)// 双向链表打印
{
	assert(plist);

	ListNode *cur = plist->_next;
	while (cur != plist)
	{
		printf("%d\n", cur->_data);
		cur = cur->_next;
	}
}
void ListPushBack(ListNode* plist, LTDataType x)// 双向链表尾插
{
	assert(plist);
	ListNode *prev = plist->_prev;//前一个
	ListNode *node = ListCreate(x);
	//前一个进行链接
	node->_prev = prev;
	prev->_next = node;
	//和头进行链接
	plist->_prev = node;
	node->_next= plist;
}

void ListPopBack(ListNode* plist)// 双向链表尾删
{
	assert(plist);
	if (plist->_next == plist)
	{
		return;
	}
	ListNode *prev = plist->_prev->_prev;//指向最后一个的前一个；
	free(plist->_prev);
	plist->_prev = prev;
	prev->_next = plist;
}

void ListPushFront(ListNode* plist, LTDataType x)// 双向链表头插
{
	assert(plist);

	ListNode *node = ListCreate(x);
	ListNode *next = plist->_next;
	//节点和后一个节点进行链接
	node->_next = next;
	next->_prev = node;
	//节点和头节点进行链接
	node->_prev = plist;
	plist->_next = node;
}
void ListPopFront(ListNode* plist)// 双向链表头删
{
	assert(plist);
	if (plist->_next == plist)
	{
		return;
	}
	ListNode *next = plist->_next->_next;
	free(plist->_next);
	plist->_next = next;
	next->_prev = plist;
}

ListNode* ListFind(ListNode* plist, LTDataType x)// 双向链表查找
{
	assert(plist);
	if (plist->_next == plist)
	{
		return NULL;
	}
	ListNode *cur = plist->_next;
	while (cur != plist)
	{
		if (cur->_data == x)
			return cur;
		cur = cur->_next;
	}
	return NULL ;
}

void ListInsert(ListNode* pos, LTDataType x)// 双向链表在pos的前面进行插入
{
	assert(pos);
	if (pos->_next == pos)
	{
		return;
	}
	ListNode *node = ListCreate(x);
	ListNode *prev = pos->_prev;
	
	prev->_next = node;
	node->_prev = prev;

	node->_next = pos;
	pos->_prev = node;
}

void ListErase(ListNode* pos)// 双向链表删除pos位置的节点
{
	assert(pos);
	if (pos->_next == pos)
	{
		return ;
	}
	ListNode *prev = pos->_prev;
	ListNode *next = pos->_next;

	free(pos);
	prev->_next = next;
	next->_prev = prev;
}

void ListDestory(ListNode** plist)// 双向链表销毁
{
	ListNode *cur = (*plist)->_next;//千万不能先删头，先删头会造成后续循环中产生野指针
	while (cur != *plist)
	{
		ListNode *next = cur->_next;
		free(cur);
		cur = next;
	}
	free(*plist);
	*plist = NULL;

}