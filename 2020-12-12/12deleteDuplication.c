//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL)
		return pHead;
	ListNode *newhead = (ListNode*)malloc(sizeof(ListNode));
	newhead->next = pHead;
	ListNode *prev = newhead;
	ListNode *cur = newhead->next;
	ListNode *next = cur->next;
	while (next)
	{
		if ((cur->val) == (next->val))
		{
			if ((next->next != NULL) && (next->next->next == NULL) && (next->val == next->next->val))
			{
				free(next->next);
				free(next);
				free(cur);
				prev->next = NULL;
				break;
			}
			prev->next = next->next;//保存后面的节点
			free(cur);//释放掉
			free(next);
			cur = prev->next;//cur处于释放的两个节点之后的节点
			if (cur)//防止越界
				next = cur->next;
			else
				break;
		}
		else
		{
			//迭代往后走
			prev = cur;
			cur = next;
			next = next->next;
		}
	}
	return newhead->next;
}
};