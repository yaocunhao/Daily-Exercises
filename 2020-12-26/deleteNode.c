struct ListNode* deleteNode(struct ListNode* head, int val){
	if (head == NULL)
		return head;
	struct ListNode* prev = NULL;
	struct ListNode *cur = head;
	while (cur)
	{
		if (cur->val == val&&prev != NULL)
		{
			prev->next = cur->next;
			free(cur);
			return head;
		}
		else if (cur->val == val&&prev == NULL)//删除第一个节点
		{
			return head->next;
		}
		prev = cur;
		cur = cur->next;

	}
	return head;


	struct ListNode* deleteNode(struct ListNode* head, int val){
		if (head == NULL)
			return NULL;
		if (head->val == val)
			return head->next;
		head->next = deleteNode(head->next, val);
		return head;
	}