struct ListNode* getKthFromEnd(struct ListNode* head, int k){
	//˫ָ�룬����һ��ָ�����ƶ�K�����룬Ȼ�������һ��ָ��һͬ����.
	//�����ָ��ָ��NULL��ʱ������ָ����ǵ�����K���ڵ�
	struct ListNode* curhead = head;
	struct ListNode* nexthead = head;
	while (k--)
	{
		if (nexthead == NULL)
			return NULL;
		nexthead = nexthead->next;
	}
	while (nexthead)
	{
		curhead = curhead->next;
		nexthead = nexthead->next;
	}
	return curhead;
}