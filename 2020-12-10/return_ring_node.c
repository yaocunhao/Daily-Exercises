#include <stdio.h>
#include <windows.h>


 struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *fun(struct ListNode *head) {
	//先判断是不是环，如果是找出第一次相遇的位置
	if (head == NULL || head->next == NULL)
		return NULL;//成环最少两个
	struct ListNode *slow = head;
	struct ListNode *fast = head;
	while (fast)
	{
		slow = slow->next;
		if (fast->next == NULL)
			return NULL;
		fast = fast->next->next;
		if (slow == fast)//重合了
			break;
	}
	if (fast == NULL)
		return fast;
	//此时得到第一次相遇的位置
	struct ListNode *dst = head;//从原点开始出发
	while (1)
	{
		if (dst == slow)
		{
			return dst;
		}
		dst = dst->next;
		slow = slow->next;
	}
}

int main()
{
	struct ListNode *n1 = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *n2 = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *n3 = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *n4 = (struct ListNode *)malloc(sizeof(struct ListNode));
	n1->val = 3;
	n2->val = 2;
	//n3->val = 0;
	//n4->val = -4;
	n1->next = n2;
	n2->next = NULL;
	//n3->next = n4;
	//n4->next = n2;

	printf("%d\n",fun(n1));
	system("pause");
	return 0;
}