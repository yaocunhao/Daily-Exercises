#include "list.h"

ListNode* ListCreate(LTDataType data)// ������������Ľ��.
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node == NULL)
		exit(-1);
	node->_data = data;
	node->_prev = node->_next = NULL;
	return node;
}

void ListPrint(ListNode* plist)// ˫�������ӡ
{
	assert(plist);

	ListNode *cur = plist->_next;
	while (cur != plist)
	{
		printf("%d\n", cur->_data);
		cur = cur->_next;
	}
}
void ListPushBack(ListNode* plist, LTDataType x)// ˫������β��
{
	assert(plist);
	ListNode *prev = plist->_prev;//ǰһ��
	ListNode *node = ListCreate(x);
	//ǰһ����������
	node->_prev = prev;
	prev->_next = node;
	//��ͷ��������
	plist->_prev = node;
	node->_next= plist;
}

void ListPopBack(ListNode* plist)// ˫������βɾ
{
	assert(plist);
	if (plist->_next == plist)
	{
		return;
	}
	ListNode *prev = plist->_prev->_prev;//ָ�����һ����ǰһ����
	free(plist->_prev);
	plist->_prev = prev;
	prev->_next = plist;
}

void ListPushFront(ListNode* plist, LTDataType x)// ˫������ͷ��
{
	assert(plist);

	ListNode *node = ListCreate(x);
	ListNode *next = plist->_next;
	//�ڵ�ͺ�һ���ڵ��������
	node->_next = next;
	next->_prev = node;
	//�ڵ��ͷ�ڵ��������
	node->_prev = plist;
	plist->_next = node;
}
void ListPopFront(ListNode* plist)// ˫������ͷɾ
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

ListNode* ListFind(ListNode* plist, LTDataType x)// ˫���������
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

void ListInsert(ListNode* pos, LTDataType x)// ˫��������pos��ǰ����в���
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

void ListErase(ListNode* pos)// ˫������ɾ��posλ�õĽڵ�
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

void ListDestory(ListNode** plist)// ˫����������
{
	ListNode *cur = (*plist)->_next;//ǧ������ɾͷ����ɾͷ����ɺ���ѭ���в���Ұָ��
	while (cur != *plist)
	{
		ListNode *next = cur->_next;
		free(cur);
		cur = next;
	}
	free(*plist);
	*plist = NULL;

}