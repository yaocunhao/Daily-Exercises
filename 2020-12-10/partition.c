//现有一链表的头指针 ListNode* pHead，给一定值
//x，编写一段代码将所有小于x的结点排在其余结点之前，且不能改变原来的数据顺序，返回重新排列后的链表的头指针。

//
ListNode* partition(ListNode* pHead, int x) {
	struct ListNode *head_min = (ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *tail_min = head_min;
	struct ListNode *head_max = (ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *tail_max = head_max;
	while (pHead)
	{
		if ((pHead->val)<x)//小于x的节点给head_min
		{
			tail_min->next = pHead;
			tail_min = tail_min->next;
		}
		else
		{
			tail_max->next = pHead;
			tail_max = tail_max->next;
		}
		pHead = pHead->next;
	}
	tail_max->next = NULL;//最后一个节点next置为空
	tail_min->next = head_max->next;
	return head_min->next;
}
};