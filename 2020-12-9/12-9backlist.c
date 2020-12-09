#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
//��������
typedef struct ListNode {
	int val;
	struct ListNode *next;
}ListNode;

#define false -1
#define true 1
int fun(ListNode* A) {
	if (A == NULL || A->next == NULL)//�ջ���1���ڵ�
		return false;
	struct ListNode *scr = A;//��ԭ���ָ��
	struct ListNode *first = A;//��һ����ָ��
	struct ListNode *second = A->next;//��������ָ��
	if (second->next == NULL || second->next->next == NULL)
		return false;//��4�����½ڵ�
	while (second->next != NULL)
	{
		first = first->next;//�ƶ�һ���ڵ㣻
		if (second->next->next == NULL)//ע��Խ��
			return false;
		second = second->next->next;//�ƶ������ڵ�         
	}
	//���еߵ�
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
	}//�ߵ���ɣ��׽ڵ�Ϊprev
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