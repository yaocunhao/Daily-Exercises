//����һ�����ͷָ�� ListNode* pHead����һ��ֵ
//x����дһ�δ��뽫����С��x�Ľ������������֮ǰ���Ҳ��ܸı�ԭ��������˳�򣬷����������к�������ͷָ�롣

//
ListNode* partition(ListNode* pHead, int x) {
	struct ListNode *head_min = (ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *tail_min = head_min;
	struct ListNode *head_max = (ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *tail_max = head_max;
	while (pHead)
	{
		if ((pHead->val)<x)//С��x�Ľڵ��head_min
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
	tail_max->next = NULL;//���һ���ڵ�next��Ϊ��
	tail_min->next = head_max->next;
	return head_min->next;
}
};