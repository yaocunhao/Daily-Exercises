//����ϰ�Լ��ݹ�ѧϰ


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* newhead = head;
	while (l1&&l2)
	{
		//����ָ��ֱ�ָ��������������С����������
		if (l1->val<l2->val)
		{
			newhead->next = l1;
			newhead = newhead->next;
			l1 = l1->next;
		}
		else
		{
			newhead->next = l2;
			newhead = newhead->next;
			l2 = l2->next;
		}
		//��󻹻�ʣ��һ������
		if (l1 == NULL)
			newhead->next = l2;
		else
			newhead->next = l1;
	}
	struct ListNode* ret = head->next;
	free(head);
	return ret;

}



//�ݹ鷨
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	struct ListNode *head = NULL;
	if (l1->val<l2->val)
	{
		head = l1;
		head->next = mergeTwoLists(l1->next, l2);
	}
	else
	{
		head = l2;
		head->next = mergeTwoLists(l1, l2->next);
	}
	return head;

}