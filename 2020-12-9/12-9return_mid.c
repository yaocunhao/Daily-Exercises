struct ListNode* middleNode(struct ListNode* head){
	if (head->next == NULL)
		return head;
	struct ListNode *first = head;
	struct ListNode *second = head->next;
	while (second->next != NULL)
	{
		first = first->next;//�ƶ�һ���ڵ�
		if (second->next->next == NULL)//������ڵ�Ϊ������
			return first;
		second = second->next->next;//�ƶ������ڵ�
	}
	return first->next;
}