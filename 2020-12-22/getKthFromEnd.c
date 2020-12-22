struct ListNode* getKthFromEnd(struct ListNode* head, int k){
	//双指针，其中一个指针先移动K个距离，然后和另外一个指针一同出发.
	//当快的指针指向NULL的时候，慢的指针就是倒数第K个节点
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