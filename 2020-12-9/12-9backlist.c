#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
//回文链表
typedef struct ListNode {
	int val;
	struct ListNode *next;
}ListNode;

#define false -1
#define true 1
int fun(ListNode* A) {
	if (A == NULL || A->next == NULL)//空或者1个节点
		return false;
	struct ListNode *scr = A;//在原点的指针
	struct ListNode *first = A;//走一步的指针
	struct ListNode *second = A->next;//走两步的指针
	if (second->next == NULL || second->next->next == NULL)
		return false;//；4个以下节点
	while (second->next != NULL)
	{
		first = first->next;//移动一个节点；
		if (second->next->next == NULL)//注意越界
			return false;
		second = second->next->next;//移动两个节点         
	}
	//进行颠倒
	struct ListNode *prev = NULL;
	struct ListNode *cur = first->next;
	struct ListNode *next = cur->next;
	while (cur != NULL)
	{
		cur->next = prev;
		prev = cur;
		cur = next;
		if (next != NULL)
			next = next->next;
	}//颠倒完成，首节点为prev
	while (prev != NULL&&scr != NULL)
	{
		if (prev->val != scr->val)
			return false;
		prev = prev->next;
		scr = scr->next;
	}
	return true;
}

int main()
{
	ListNode *head = (ListNode *)malloc(sizeof(ListNode));
	head->val = 1;
	head->next = (ListNode *)malloc(sizeof(ListNode));
	head->next->val = 2;
	head->next->next = (ListNode *)malloc(sizeof(ListNode));
	head->next->next->val = 2;
	head->next->next->next = (ListNode *)malloc(sizeof(ListNode));
	head->next->next->next->val = 1;
	head->next->next->next->next = NULL;
	int ret = fun(head);
	if (ret == 1)
		printf("true!\n");
	else
		printf("false\n");
	system("pause");
	return 0;
}