//输出链表倒数第K个节点的值

struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
	struct ListNode*slow = pListHead;
	struct ListNode*fast = pListHead;
	while (k--)
	{
		if (fast)//防止K大于节点个数而导致越界
			fast = fast->next;//移动K步
		else
			return NULL;
	}
	while (fast)//fast为空找到节点
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}