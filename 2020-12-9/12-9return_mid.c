struct ListNode* middleNode(struct ListNode* head){
	if (head->next == NULL)
		return head;
	struct ListNode *first = head;
	struct ListNode *second = head->next;
	while (second->next != NULL)
	{
		first = first->next;//移动一个节点
		if (second->next->next == NULL)//该链表节点为单数个
			return first;
		second = second->next->next;//移动两个节点
	}
	return first->next;
}